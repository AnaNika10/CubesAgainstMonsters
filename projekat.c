#include "tabla.h"
#include "figure.h"
#include "kocka.h"
#include "pomeranje.h"
#include "reci.h"
#include "osvetljenje.h"
#include "tekstura.h"
#include <time.h> 
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#define TIMER_INTERVAL1 20
#define TIMER_INTERVAL2 20
#define TIMER_ID0 0
#define TIMER_ID1 1
#define PI 3.14159265359
void on_timer1(int id);
void on_timer2(int id);
void restartuj();
/*Parametri animacije za pomeranje po X Y i Z osi*/
float animation_parameterX=0;
float animation_parameterY = 0;
float animation_parameterZ = 0;
/*Parametar za padanje loptice*/
float animation_parameter_sphere=0.7;
int putanja=0;
int animation_ongoing1 = 0;
static int window_width, window_height;
int lvl=0; //indikator nivoa
int r=0; // indikator da li moze da se promeni nivo (tj ili nismo zapoceli igru ili smo je restartovali u suprotnom promena nivoa nece biti registrovana)
int randombr1;
int randombr2;
int kockica; //promenljiva koja pokazuje koji broj se prikazuje na kockici
int pomeraj=0; //pozicija na koju treba da stignemo
int *goaway=NULL; //niz koji kaze sta treba raditi sa lopticom
int playable=0; //indikator za pomeranje
int mesto,mesto1,obrisi; //pozicije koje smo nasli i treba da obrisemo iz niza zamki
int fight=0; //indikator za borbu
int flagporuka=1; //indikator za iscrtavanje poruke
int zivoti; //promenljiva koja cuva zivote
char *zivotistring="LIVES:";
char *nizzivota="| | |  ";
int n,m,state_move=1,state_attack=1;
/*Niz loptica za prvi nivo i niz polja koji predstavljaju prelazak na borbu (mesto loptice i mesto ispred)*/
int lvl1_zamke[]={4,8,13,17,21};
int lvl1[]={3,4,7,8,12,13,16,17,20,21};
/*Niz loptica za drugi nivo i niz polja koji predstavljaju prelazak na borbu (mesto loptice i mesto ispred)*/
int lvl2_zamke[]={2,4,7,10,13,16,20};
int lvl2[]={1,2,3,4,6,7,9,10,12,13,15,16,19,20};
/*Niz loptica za treci nivo i niz polja koji predstavljaju prelazak na borbu (mesto loptice i mesto ispred)*/
int lvl3_zamke[]={2,4,6,9,11,13,15,18,21};
int lvl3[]={1,2,3,4,5,6,8,9,10,11,12,13,14,15,17,18,20,21};
int lvl_zamke[10]; //niz zamki za trenutno pokrenut nivo
int lvl_polja[20]; //niz opasnih polja za trenutno pokrenut nivo
/* Deklaracije callback funkcija. */
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
int main(int argc, char **argv)
{
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE| GLUT_DEPTH);
    
    /* Kreira se prozor. */
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 100);
     glutCreateWindow("Cubes against monsters");

    
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

   
     glClearColor(0.25, 1, 0.25, 0);
     
      zivoti=3;
      lvl=0;
      srand(time(0));
        initialize();
    /* Program ulazi u glavnu petlju. */
    glutMainLoop();

    return 0;
}
static void on_display(void)
{
   
    glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);

    /* Podesava se viewport. */
    glViewport(0, 0, window_width, window_height);
         
    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3,3, 2,10);
 
    /* Podesava se vidna tacka. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //Pozicija kamere 
    gluLookAt(0, 5, 5, 0, 0, 0, 0, 1, 0);
    glPushMatrix();    
    /* Iscrtava poruku za biranje nivoa*/
    if(flagporuka)
        iscrtajPoruku();
    glPopMatrix();
    //Iscrtava prikaz zivota
    glPushMatrix();
        iscrtajZivote(zivotistring,nizzivota);
    glPopMatrix();
    //Iscrtava poruku posle poraza
    if(!zivoti && !flagporuka){
        glPushMatrix(); 
        iscrtajGameOver();
        glPopMatrix();
    }
    //Iscrtava poruku posle pobede
    if(pomeraj>=22 && !flagporuka)
    {
        glPushMatrix(); 
        iscrtajCongrats();
        glPopMatrix();
  
    }
    //Postavlja osvetljenje
    glPushMatrix(); 
        postavi_osvetljenje();
    glPopMatrix();
    //Postavljanje teksture
    glPushMatrix();
        textures();
    glPopMatrix();  
    //Iscratava kocke i tackice
   glPushMatrix();
       glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        Kocke();
        Tacke1(kockica,state_attack); 
        Tacke2(randombr2,state_move);
   glPopMatrix();
   //Ukljucujemo osvetljenje
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //Kreira tablu
    glPushMatrix();
        kreirajTablu();
    glPopMatrix();
    //U zavisnosti od nivoa iscrtava cudovista
    if(goaway!=NULL){
    glPushMatrix();
        kreirajCudovista(lvl,goaway,animation_parameter_sphere);
    glPopMatrix();
    }
   
     //Crtanje piona i njegova animacija    
    glPushMatrix();
                glTranslatef(animation_parameterX*1.2,0.35+1.5*fabs(sin(PI*animation_parameterY/360)), -animation_parameterZ*1.15);
                kreirajPiona(-3,0,5);
    glPopMatrix();
 
     
  
    glutSwapBuffers();

}
static void on_keyboard(unsigned char key, int x, int y)
{
    
    switch (key) {
    case 27:
        exit(0);
        break;
    case 'r':
    case 'R':
          restartuj();
         break;
    case '1': //izaberi lvl 1
        if(!r){
 	r=1;
        lvl=1;
        playable=1;
        flagporuka=0;
        memcpy(lvl_zamke, lvl1_zamke, sizeof(lvl1_zamke));
        memcpy(lvl_polja, lvl1,sizeof(lvl1));
        goaway=(int*)calloc(5,sizeof(int));
         }
        break;
    case '2': //izaberi lvl 2
 	if(!r){
	r=1;
        lvl=2;
        flagporuka=0;
        playable=1;
        memcpy(lvl_zamke, lvl2_zamke, sizeof(lvl2_zamke));
        memcpy(lvl_polja, lvl2,sizeof(lvl2));
        goaway=(int*)calloc(7,sizeof(int));
        }
        break;
    case '3': //izaberi lvl 3
	 if(!r){
	r=1;
        lvl=3;
        flagporuka=0;
        playable=1;
        memcpy(lvl_zamke, lvl3_zamke, sizeof(lvl3_zamke));
        memcpy(lvl_polja, lvl3,sizeof(lvl3));
        goaway=(int*)calloc(9,sizeof(int));
	}
        break;
    case 'c':
        if(playable && !animation_ongoing1 && lvl){
            randombr1=random_num(); //odaberi slucajan broj
        kockica=randombr1; //koji broj se postavlja na kockicu
        pomeraj=igraj(randombr1,pomeraj,playable); //izvrsi pomeranje za randombr1 polja
        
        
        
        if(lvl==1){
        for(int i=0;i<5;i++)
            if(pomeraj==lvl_zamke[i])
            { 
                pomeraj--;    //ako se dobije mesto na kom se bas nalazi cudoviste vrati se za jedno polje
                randombr1--;
            }
        for(int i=0;i<10;i++)
            if(pomeraj==lvl_polja[i])
            {
                playable=0; //mod za pomeranje se iskljucuje
                fight=1; //fight mod se ukljucuje
                glClearColor(1, 0.25, 0.25, 0); //menjanje pozadine
            }
        }
        if(lvl==2){
        for(int i=0;i<7;i++)
            if(pomeraj==lvl_zamke[i])
            { 
                pomeraj--;   //ako se dobije mesto na kom se bas nalazi cudoviste vrati se za jedno polje
                randombr1--;
            }
        for(int i=0;i<13;i++)
            if(pomeraj==lvl_polja[i])
            {
                playable=0;  //mod za pomeranje se iskljucuje
                fight=1;   //fight mod se ukljucuje
                glClearColor(1, 0.25, 0.25, 0); //menjanje pozadine
            }
        }
        if(lvl==3){
        for(int i=0;i<9;i++)
            if(pomeraj==lvl_zamke[i])
            { 
                pomeraj--;   //ako se dobije mesto na kom se bas nalazi cudoviste vrati se za jedno polje
                randombr1--;
            }
        for(int i=0;i<18;i++)
            if(pomeraj==lvl_polja[i])
            {
                playable=0;   //mod za pomeranje se iskljucuje
                
                fight=1;   //fight mod se ukljucuje
                glClearColor(1, 0.25, 0.25, 0);   //menjanje pozadine
            }
        
       
        
        }
        //Namesta kockicu da u slucaju kad dodje do kraja da ne bi skakao u mestu
        if(pomeraj>=22){
           randombr1-=pomeraj-22;
        }
        
        /*  Pokretanje animacije*/
        if (!animation_ongoing1) {
                animation_ongoing1=1;
            glutTimerFunc(TIMER_INTERVAL1, on_timer1, TIMER_ID0);
            }
        }
        break;
    case 'v':
        if(!playable && zivoti && lvl && !animation_ongoing1){
            randombr2=random_num();
        if(fight==1)
        {    
            if(randombr2>=4)  // u slucaju dobijanja broja veceg od cetiri nastavi dalje
            {
                playable=1; //mozemo da se pomeramo
                fight=0; //gotova borba
                glClearColor(0.25, 1, 0.25, 0); //menjanje boje pozadine
                switch(lvl){
                    case 1:
                        //pronadji trenutnu poziciju posle borbe da bi ustavio na koju lopticu pokrenuti animaciju
                        mesto=pronadji(lvl_zamke,5,pomeraj); 
                        mesto1=pronadji(lvl_zamke,5,pomeraj+1);
                        if(mesto>mesto1)
                            obrisi=mesto;
                        else
                            obrisi=mesto1; 
                        goaway[obrisi]=1; // pokreni padanje animaicije
                        if (!animation_ongoing1) {
                               animation_ongoing1=1;
                               animation_parameter_sphere=0.7;
                        glutTimerFunc(TIMER_INTERVAL2, on_timer2, TIMER_ID1);
                        }
                        // obrisi tu lopticu iz trenutnih zamki da mozemo da idemo dalje
                        if(obrisi_element(lvl_zamke,5,pomeraj)){
                            obrisi_element(lvl_polja,10,pomeraj);
                            
                        }
                        else if(obrisi_element(lvl_zamke,5,pomeraj+1)){
                        obrisi_element(lvl_polja,10,pomeraj);
                        obrisi_element(lvl_polja,10,pomeraj+1);
                        
                        }
                     
                        break;     
                    case 2:
                        mesto=pronadji(lvl_zamke,7,pomeraj);
                        mesto1=pronadji(lvl_zamke,7,pomeraj+1);
                        if(mesto>mesto1)
                            obrisi=mesto;
                        else
                            obrisi=mesto1;
                        goaway[obrisi]=1;
                        if (!animation_ongoing1) {
                               animation_ongoing1=1;
                               animation_parameter_sphere=0.7;
                        glutTimerFunc(TIMER_INTERVAL2, on_timer2, TIMER_ID1);
                        }
                        if(obrisi_element(lvl_zamke,7,pomeraj))
                            obrisi_element(lvl_polja,14,pomeraj);
                        else{
                        obrisi_element(lvl_zamke,7,pomeraj+1);
                        obrisi_element(lvl_polja,14,pomeraj+1);
                        obrisi_element(lvl_polja,14,pomeraj);
                        } 
                        break;
                    case 3: 
                        mesto=pronadji(lvl_zamke,9,pomeraj);
                        mesto1=pronadji(lvl_zamke,9,pomeraj+1);
                        if(mesto>mesto1)
                            obrisi=mesto;
                        else
                            obrisi=mesto1;
                        goaway[obrisi]=1;
                        if (!animation_ongoing1) {
                               animation_ongoing1=1;
                               animation_parameter_sphere=0.7;
                        glutTimerFunc(TIMER_INTERVAL2, on_timer2, TIMER_ID1);
                        }
                        if(obrisi_element(lvl_zamke,9,pomeraj))
                            obrisi_element(lvl_polja,18,pomeraj);
                        else{
                        obrisi_element(lvl_zamke,9,pomeraj+1);
                        obrisi_element(lvl_polja,18,pomeraj+1);
                        obrisi_element(lvl_polja,18,pomeraj);
                        } 
                        break;
                    default:
                        printf("Greska!");
                        break;
                    
                }
            }
            else
            {   //Skrati string da smanji zivote
                if(zivoti){ 
                zivoti--;
                nizzivota+=2;
                }
                if(!zivoti){
                //printf("Game over!");
                nizzivota=" ";
                }
            }
        }
    }
        break;
    }
   
    glutPostRedisplay();
}
static void on_reshape(int width, int height)
{
    /* Pamte se sirina i visina prozora. */
    window_width = width;
    window_height = height;
}
//prvi timer za pomeranje piona
 void on_timer1(int id) {
    if (id == TIMER_ID0) {
    
        if (animation_parameterY >= randombr1*360) {
            animation_ongoing1 = 0;
            animation_parameterY=0;
            
            return;
        }
        
        if (animation_parameterZ+animation_parameterX>=pomeraj ) {
            animation_ongoing1=0;
            animation_parameterZ=0;
            animation_parameterX=0;
            return;
        }
        // levi  i gornji deo table
        if(putanja==0){
        if(animation_parameterZ>=4.2){
             animation_parameterZ=4.2f;
            
        }
        else{
             animation_parameterX=-0.2;
        }
        if(animation_parameterX>=5.2f)
        {
            animation_parameterX=5.2f;
            putanja=1;
            
        }
        else{ 
        animation_parameterX+=0.045f;
        animation_parameterZ+=0.05f;
        }
        }
        //desni i donji deo table
        else if(putanja==1)
        {
            
            if(animation_parameterZ<=0){
             animation_parameterZ=0;
            }
            else{
             animation_parameterX=5.2f;
            }
            if(animation_parameterX<=0){
            
                animation_parameterX=0;
                putanja=1;
            
            }
            
        animation_parameterZ-=0.052f;
        animation_parameterX-=0.047f;
        
        }
         
        animation_parameterY += 20;
    }
    
    glutPostRedisplay();

    if (animation_ongoing1) {
        glutTimerFunc(TIMER_INTERVAL1, on_timer1, TIMER_ID0);
    }
    
    
}
// drugi timer za padanja loptica
void on_timer2(int id) {
   
    if (id == TIMER_ID1) {
        
        if(animation_parameter_sphere<=-10){
            animation_parameter_sphere=0.7;
            animation_ongoing1=0;
            goaway[obrisi]=2;  //kada se zavrsi animacija prestani da iscrtavas lopticu           
            
        }
        animation_parameter_sphere-=1;  
    }
    glutPostRedisplay();
   if (animation_ongoing1) {
        glutTimerFunc(TIMER_INTERVAL2, on_timer2, TIMER_ID1);
    } 
}
//fja resetuje sve parametre za pocetak nove igre
void restartuj(){
   r=0; 
   animation_parameterX=0;
   animation_parameterY = 0;
   animation_parameterZ = 0;
   animation_parameter_sphere=0.7;
   putanja=0;
   fight=0;
   zivoti=3;
   playable=0;
   flagporuka=1;
   kockica=0;
   randombr2=0;
  pomeraj=0;
 nizzivota="| | |  ";
 glClearColor(0.25, 1, 0.25, 0);
 goaway=NULL;
}
