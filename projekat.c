#include "tabla.h"
#include "figure.h"
#include "kocka.h"
#include "pomeranje.h"
#include "reci.h"
#include <time.h> 
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
// /* Dimenzije prozora */

// Pobeda/poraz
#define TIMER_INTERVAL1 20
#define TIMER_INTERVAL2 20
#define TIMER_ID0 0
#define TIMER_ID1 1
#define PI 3.14159265359
void on_timer1(int id);
void on_timer2(int id);
float animation_parameterX=0;
float animation_parameterY = 0;
float animation_parameterZ = 0;
float animation_parameter_sphere=0.7;
int putanja=0;
int animation_ongoing1 = 0;
int animation_ongoing2 = 0;
static int window_width, window_height;
int lvl=0;
int randombr1;
int randombr2;
int kockica;
int pomeraj=0;
int *goaway;
int playable=1;
int mesto,mesto1,obrisi;
int fight=0;
int flagporuka=1;
int *goaway;
int zivoti=3;
char *zivotistring="LIVES:";
char *nizzivota="| | |  ";
int n,m,state_move=1,state_attack=1;
tuple pozicije[]={{-3,0,5},{-3,0,4},{-3,0,3},{-3,0,2},{-3,0,1},
      {-3,0,0},{-2,0,0},{-1,0,0},{0,0,0},{1,0,0},{2,0,0},{3,0,0},
      {3,0,1},{3,0,2},{3,0,3},{3,0,4},{3,0,5},{2,0,5},{1,0,5},{0,0,5},{-1,0,5},{-2,0,5}
      
};
//  4,8,13,17,21
int lvl1_zamke[]={4,8,13,17,21};
int lvl1[]={3,4,7,8,12,13,16,17,20,21};

int lvl2_zamke[]={2,4,7,10,13,16,20};
int lvl2[]={1,2,3,4,6,7,9,10,12,13,15,16,19,20};

int lvl3_zamke[]={2,4,6,9,11,13,15,18,21};
int lvl3[]={1,2,3,4,5,6,8,9,10,11,12,13,14,15,17,18,20,21};
/* Deklaracije callback funkcija. */
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
int main(int argc, char **argv)
{
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    
    /* Kreira se prozor. */
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 100);
     glutCreateWindow("Cubes against monsters");

    
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

   
     glClearColor(0.25, 1, 0.25, 0);
     
 
      srand(time(0));
    glLineWidth(2);

    /* Program ulazi u glavnu petlju. */
    glutMainLoop();

    return 0;
}
static void on_display(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);

    /* Podesava se viewport. */
    glViewport(0, 0, window_width, window_height);
         
    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3,3, 2,10);
 
    /* Podesava se vidna tacka. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
  
    gluLookAt(0, 5, 5, 0, 0, 0, 0, 1, 0); 
    if(flagporuka)
        iscrtajPoruku(); 
    iscrtajZivote(zivotistring,nizzivota); //Iscrta prikaz zivota
    if(!zivoti)
        iscrtajGameOver();
    if(pomeraj>=22)
        iscrtajCongrats();
   /*Iscrtava elemente: tablu, kocke, i u odnosu na zeljeni nivo postavlja kreirajCudovista*/
    glPushMatrix();
        Kocke();
        Tacke1(kockica,state_move); 
        Tacke2(randombr2,state_attack);
        kreirajTablu();
    glPopMatrix();
    
    glPushMatrix();
        kreirajCudovista(lvl,goaway,animation_parameter_sphere);
    glPopMatrix();
    
        glPushMatrix();
            glTranslatef(animation_parameterX*1.2,1.5*fabs(sin(PI*animation_parameterY/360)), -animation_parameterZ*1.2);
            kreirajPijuna(pozicije[0].x,pozicije[0].y,pozicije[0].z);
        glPopMatrix();
 
        
        
        
        
        
    glutSwapBuffers();

}
static void on_keyboard(unsigned char key, int x, int y)
{
    
    switch (key) {
    case 27:
        exit(0);
        break;
    case '1': //izaberi lvl 1
        lvl=1;
        flagporuka=0;
        goaway=(int*)calloc(5,sizeof(int)); 
        break;
    case '2': //izaberi lvl 2
        lvl=2;
        flagporuka=0;
        goaway=(int*)calloc(7,sizeof(int));
        break;
    case '3': //izaberi lvl 3
        lvl=3;
        flagporuka=0;
        goaway=(int*)calloc(9,sizeof(int));
        break;
    case 'c':            
        if(playable && !animation_ongoing1)
            randombr1=random_num();
        else 
            randombr1=0;
        kockica=randombr1;
        pomeraj=igraj(randombr1,pomeraj,playable);
        
    
        if(lvl==1){
        for(int i=0;i<5;i++)
            if(pomeraj==lvl1_zamke[i])
            { 
                pomeraj--;
                randombr1--;
            }
        for(int i=0;i<10;i++)
            if(pomeraj==lvl1[i])
            {
                playable=0;
                fight=1;
                glClearColor(1, 0.25, 0.25, 0);
            }
        }
        if(lvl==2){
        for(int i=0;i<7;i++)
            if(pomeraj==lvl2_zamke[i])
            { 
                pomeraj--;
                randombr1--;
            }
        for(int i=0;i<13;i++)
            if(pomeraj==lvl2[i])
            {
                playable=0;
                
                fight=1;
                glClearColor(1, 0.25, 0.25, 0);
            }
        }
        if(lvl==3){
        for(int i=0;i<9;i++)
            if(pomeraj==lvl3_zamke[i])
            { 
                pomeraj--;
                randombr1--;
            }
        for(int i=0;i<18;i++)
            if(pomeraj==lvl3[i])
            {
                playable=0;
                
                fight=1;
                glClearColor(1, 0.25, 0.25, 0);
            }
        
       
        
        }
        /*int j;
        for(j=0;j<5;j++){
            if(pomeraj>=lvl1_zamke[j])
                goaway[j]=1;
         }*/
            if (!animation_ongoing1) {
                animation_ongoing1=1;
            glutTimerFunc(TIMER_INTERVAL1, on_timer1, TIMER_ID0);
            }
        
        break;
    case 'v':
        if(!playable)
            randombr2=4;//random_num();
        else 
            randombr2=0;
        if(fight==1)
        {    
            if(randombr2>=4)
            {
                playable=1;
                fight=0;
                glClearColor(0.25, 1, 0.25, 0);
                switch(lvl){
                    case 1:
                        mesto=pronadji(lvl1_zamke,5,pomeraj);
                        mesto1=pronadji(lvl1_zamke,5,pomeraj+1);
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
                        if(obrisi_element(lvl1_zamke,5,pomeraj)){
                            obrisi_element(lvl1,10,pomeraj);
                            
                        }
                        else if(obrisi_element(lvl1_zamke,5,pomeraj+1)){
                        obrisi_element(lvl1,10,pomeraj);
                        obrisi_element(lvl1,10,pomeraj+1);
                        
                        }
                     
                        break;     
                    case 2:
                        mesto=pronadji(lvl2_zamke,7,pomeraj);
                        mesto1=pronadji(lvl2_zamke,7,pomeraj+1);
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
                        if(obrisi_element(lvl2_zamke,7,pomeraj))
                            obrisi_element(lvl2,14,pomeraj);
                        else{
                        obrisi_element(lvl2_zamke,7,pomeraj+1);
                        obrisi_element(lvl2,14,pomeraj+1);
                        obrisi_element(lvl2,14,pomeraj);
                        } 
                        break;
                    case 3: 
                        mesto=pronadji(lvl3_zamke,9,pomeraj);
                        mesto1=pronadji(lvl3_zamke,9,pomeraj+1);
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
                        if(obrisi_element(lvl3_zamke,9,pomeraj))
                            obrisi_element(lvl3,18,pomeraj);
                        else{
                        obrisi_element(lvl3_zamke,9,pomeraj+1);
                        obrisi_element(lvl3,18,pomeraj+1);
                        obrisi_element(lvl3,18,pomeraj);
                        } 
                        break;
                    default:
                        printf("Greska!");
                        break;
                    
                }
            }
            else
            {
                zivoti--;
                nizzivota+=2;
                if(zivoti==0){
                printf("Game over!");
                nizzivota=" ";
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
void on_timer2(int id) {
   
    if (id == TIMER_ID1) {
        
        if(animation_parameter_sphere<=-10){
            animation_parameter_sphere=0.7;
            animation_ongoing1=0;
            goaway[obrisi]=2;            
            
        }
        animation_parameter_sphere-=0.5;  
    }
    glutPostRedisplay();
   if (animation_ongoing1) {
        glutTimerFunc(TIMER_INTERVAL2, on_timer2, TIMER_ID1);
    } 
}
