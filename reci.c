#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include "reci.h"
void iscrtajZivote(char *zivotistring, char *nizzivota){
   int n=strlen(nizzivota);
   int m=strlen(zivotistring);
    glPushMatrix();
        glColor3f(0,0,0);
        glRasterPos3f(4,2,0);
	    for (int i=0; i<m; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , zivotistring[i]);
	    }
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
	    glRasterPos3f(5.5,2,0);
	    for (int i=0; i<n; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , nizzivota[i]);
	    }
    glPopMatrix();
}
/*
void iscrtajGameOver(){
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3,3, 2,10);
     glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
  
    gluLookAt(0, 5, 5, 0, 0, 0, 0, 1, 0); 
   char *word="Game over!";
   int n=strlen(word);
   
    
        glColor3f(0,0,0);
        glRasterPos3f(5,2,0);
	    for (int i=0; i<n; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , word[i]);
	    }
	   
    glPopMatrix();
    printf("game over");
}*/
