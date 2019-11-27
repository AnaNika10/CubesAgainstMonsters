#include "tabla.h"
#include "figure.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
// /* Dimenzije prozora */
static int window_width, window_height;
int lvl=0;
/* Deklaracije callback funkcija. */
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
int main(int argc, char **argv)
{
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

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
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

    /* Program ulazi u glavnu petlju. */
    glutMainLoop();

    return 0;
}

static void on_display(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
     
    kreirajTablu();
    kreirajPijuna();
    kreirajCudovista(lvl);
      
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
        break;
    case '3': //izaberi lvl 3
        lvl=3;
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
