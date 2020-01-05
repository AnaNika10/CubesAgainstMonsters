#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "tabla.h"
void kreirajTablu(){
/*****Gornji deo*********/
   glPushMatrix();
        glColor3f(0.5, 0, 0.5);
        glutSolidCube(0.6);
   glPopMatrix(); 
    glPushMatrix();
    glTranslatef(-1, 0, 0);
      glutSolidCube(0.6);
   glPopMatrix(); 
    glPushMatrix();
      glTranslatef(-2, 0, 0);
         glutSolidCube(0.6);
       glPopMatrix(); 
       glPushMatrix();
      glTranslatef(-3, 0, 0);
         glutSolidCube(0.6);
      glPopMatrix(); 
        glPushMatrix();
      glTranslatef(1, 0, 0);
         glutSolidCube(0.6);
      glPopMatrix(); 
       glPushMatrix();
      glTranslatef(2, 0, 0);
         glutSolidCube(0.6);
     glPopMatrix(); 
     
       glPushMatrix();
      glTranslatef(3, 0, 0);
         glutSolidCube(0.6);
     glPopMatrix(); 
     /****Kraj gore*****/
      
      /*****Desnooooo*****/
       glPushMatrix();
      glTranslatef(3, 0, 1);
      glutSolidCube(0.6);
      glPopMatrix(); 
      
       glPushMatrix();
      glTranslatef(3, 0, 2);
      glutSolidCube(0.6);
     glPopMatrix(); 
       glPushMatrix();
      glTranslatef(3, 0, 3);
      glutSolidCube(0.6);
      glPopMatrix(); 
      
       glPushMatrix();
      glTranslatef(3, 0, 4);
      glutSolidCube(0.6);
      glPopMatrix(); 
      
       glPushMatrix();
      glTranslatef(3, 0, 5);
      glutSolidCube(0.6);
      glPopMatrix(); 
      
    
      /* Kraajj  Desnoooo*///
      
      /********Doleee*********/
      
      
      glPushMatrix();
    glTranslatef(0, 0, 5);
      glutSolidCube(0.6);
   glPopMatrix(); 
   
     glPushMatrix();
    glTranslatef(-1, 0, 5);
      glutSolidCube(0.6);
    glPopMatrix(); 
    
    glPushMatrix();
      glTranslatef(-2, 0, 5);
      glutSolidCube(0.6);
       glPopMatrix(); 
      
    
       glPushMatrix();
      glTranslatef(1, 0, 5);
      glutSolidCube(0.6);
      glPopMatrix(); 
      
       glPushMatrix();
      glTranslatef(2, 0, 5);
      glutSolidCube(0.6);
     glPopMatrix(); 
      
    
     
  /********* Krajj   Doleeeeeeeee*////////
  
  
  
  /*************LEVOOOO*************/
      glPushMatrix();
      glTranslatef(-3, 0, 1);
         glutSolidCube(0.6);
      glPopMatrix(); 
        
       glPushMatrix();
      glTranslatef(-3, 0, 2);
      glutSolidCube(0.6);
     glPopMatrix(); 
     
       glPushMatrix();
      glTranslatef(-3, 0, 3);
      glutSolidCube(0.6);
    glPopMatrix(); 
      
       glPushMatrix();
      glTranslatef(-3, 0, 4);
      glutSolidCube(0.6);
      glPopMatrix(); 
      
       glPushMatrix();
      glTranslatef(-3, 0, 5);
        glColor3f(0, 0.7, 0.2);
        glutSolidCube(0.6);
     glPopMatrix(); 
       
       
       /**************** Kraj LEVOOOOO*********/

}
