#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include "reci.h"
void iscrtajZivote(char *zivotistring, char *nizzivota){
   int n=strlen(nizzivota);
   int m=strlen(zivotistring);
        //iscrtaj tekst reci LIVES
        glPushAttrib(GL_CURRENT_BIT);
        glColor3f(0,0,0);
        
        glRasterPos3f(4,2,0);
	    for (int i=0; i<m; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , zivotistring[i]);
	    }
	    glPopAttrib();
        //iscrtaj tekst linija koji predstavlja zivote
        glPushAttrib(GL_CURRENT_BIT);
        glColor3f(0,0,0);
	    glRasterPos3f(5.5,2,0);
	    for (int i=0; i<n; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , nizzivota[i]);
	    }
       glPopAttrib();
}
//ispisivanje teksta Game over
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
//ispisivanje teksta CONGRATULATIONS
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
//ispisivanje teksta Choose level (use 1,2,3)
void iscrtajPoruku(){
    char *word="Choose level (use 1,2,3)!";
   int n=strlen(word);
   glPushMatrix();
        glColor3f(0,0,0);
        glRasterPos3f(-4,4,0); //pozicija teksta
	    for (int i=0; i<n; i++)
	    {
    		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , word[i]);
	    }
	   
    glPopMatrix();
}

