#include "tabla.h"
#include "figure.h"
#include "kocka.h"
#include "pomeranje.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
// /* Dimenzije prozora */

/**
 * random
 * Vracanje
 * zivoti
 * pop up message
 * zakljucavanje kocke
 * */
static int window_width, window_height;
int lvl=0;
int randombr1;
int randombr2;
int pomeraj;
int playable=1;
int zivoti=3;
tuple pozicije[]={{-3,0,5},{-3,0,4},{-3,0,3},{-3,0,2},{-3,0,1},
      {-3,0,0},{-2,0,0},{-1,0,0},{0,0,0},{1,0,0},{2,0,0},{3,0,0},
      {3,0,1},{3,0,2},{3,0,3},{3,0,4},{3,0,5},{2,0,5},{1,0,5},{0,0,5},{-1,0,5},{-2,0,5}
      
};
//  5 9 14 18 22
int lvl1_zamke[]={4,8,13,17,21};
int lvl1[]={3,4,7,8,12,13,16,17,20,21};
/* Deklaracije callback funkcija. */
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
int main(int argc, char **argv)
{
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB  /*GLUT_DEPTH */| GLUT_DOUBLE);
    
    /* Kreira se prozor. */
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 100);
     glutCreateWindow("Boze pomozi");

    /* Registruju se callback funkcije. */
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0.75, 0.75, 0.75, 0);
  //  glEnable(GL_DEPTH_TEST);
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
   // gluLookAt(2, 2, -4, 0, 0, 0, 0, 1, 0);
     gluLookAt(0, 5, 5, 0, 0, 0, 0, 1, 0);
     
    
    Kocke();
    Tacke1(randombr1); 
    Tacke2(randombr2);
    kreirajTablu();
  //  kreirajPijuna(pozicije[pomeraj].x,pozicije[pomeraj].y,pozicije[pomeraj].z);
    kreirajCudovista(lvl);
     kreirajPijuna(pozicije[pomeraj].x,pozicije[pomeraj].y,pozicije[pomeraj].z);
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
       
        break;
    case '2': //izaberi lvl 2
        lvl=2;
        pomeraj=0;
        break;
    case '3': //izaberi lvl 3
        lvl=3;
        pomeraj=0;
        break;
    case 'c':
        randombr1=random_num();
        pomeraj=igraj(randombr1,playable);
        if(pomeraj>=22){
            printf("Congrats!!!");
            exit(0);
        }
        for(int i=0;i<10;i++)
            if(pomeraj==lvl1[i])
            { //printf("BACI KOCKU");
                playable=0;
            }
        for(int i=0;i<10;i++)
            if(pomeraj==lvl1[i])
            { //printf("BACI KOCKU");
                playable=0;
            }
        break;
    case 'v':
        randombr2=random_num();
        if(randombr2>=4)
        {
            playable=1;
            
        }
        else
        {
            zivoti--;
            if(zivoti==0){
            printf("Game over!");
            exit(0);
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
