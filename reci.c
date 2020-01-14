#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include "reci.h"
void iscrtajZivote(char *zivotistring, char *nizzivota){
   int n=strlen(nizzivota);
   int m=strlen(zivotistring);
    
        glPushAttrib(GL_CURRENT_BIT);
        glColor3f(0,0,0);
        
        glRasterPos3f(4,2,0);
	    for (int i=0; i<m; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , zivotistring[i]);
	    }
	    glPopAttrib();
  
        glPushAttrib(GL_CURRENT_BIT);
        glColor3f(0,0,0);
	    glRasterPos3f(5.5,2,0);
	    for (int i=0; i<n; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , nizzivota[i]);
	    }
       glPopAttrib();
}

void iscrtajGameOver(){
  
   char *word="Game over!";
   int n=strlen(word);
   glPushMatrix();
    
        glColor3f(0,0,0);
        glRasterPos3f(-4,4,0);
	    for (int i=0; i<n; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , word[i]);
	    }
	   
    glPopMatrix();
    
}
void iscrtajCongrats(){
    
   char *word="CONGRATULATIONS!";
   int n=strlen(word);
   glPushMatrix();
    
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
   glPushMatrix();
        glColor3f(0,0,0);
        glRasterPos3f(-4,4,0);
	    for (int i=0; i<n; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , word[i]);
	    }
	   
    glPopMatrix();
}

