#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include "reci.h"
void iscrtajZivote(char *zivotistring, char *nizzivota){
   int n=strlen(nizzivota);
   int m=strlen(zivotistring);
    glPushMatrix();
        glColor3f(1,1,1);
        glRasterPos3f(4,2,0);
	    for (int i=0; i<m; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , zivotistring[i]);
	    }
    glPopMatrix();
    glPushMatrix();
        glColor3f(1,1,1);
	    glRasterPos3f(5.5,2,0);
	    for (int i=0; i<n; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , nizzivota[i]);
	    }
    glPopMatrix();
}

void iscrtajGameOver(){
  
   char *word="Game over!";
   int n=strlen(word);
   
    
        glColor3f(0,0,0);
        glRasterPos3f(-4,4,0);
	    for (int i=0; i<n; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , word[i]);
	    }
	   
    glPopMatrix();
    
}
void iscrtajCongrats(){
    
   char *word="Congrats!";
   int n=strlen(word);
   
    
        glColor3f(0,0,0);
        glRasterPos3f(-4,4,0);
	    for (int i=0; i<n; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , word[i]);
	    }
	   
    glPopMatrix();
   
}
void iscrtajPoruku(){
    char *word="Choose level (use 1,2,3)!";
   int n=strlen(word);
   
    
        glColor3f(0,0,0);
        glRasterPos3f(-4,4,0);
	    for (int i=0; i<n; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , word[i]);
	    }
	   
    glPopMatrix();
}

