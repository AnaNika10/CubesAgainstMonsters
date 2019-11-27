#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "tabla.h"
void kreirajTablu(){
/*****Gornji deo*********/
    glColor3f(0.5, 0, 0.5);
    glutSolidCube(0.6);
    
    glTranslatef(-1, 0, 0);
      glutSolidCube(0.6);
    glTranslatef(1, 0, 0); 
   
      glTranslatef(-2, 0, 0);
         glutSolidCube(0.6);
       glTranslatef(2, 0, 0); 
      
      glTranslatef(-3, 0, 0);
         glutSolidCube(0.6);
       glTranslatef(3, 0, 0); 
       
      glTranslatef(1, 0, 0);
         glutSolidCube(0.6);
      glTranslatef(-1, 0, 0);
      
      glTranslatef(2, 0, 0);
         glutSolidCube(0.6);
      glTranslatef(-2, 0, 0);
      
      glTranslatef(3, 0, 0);
         glutSolidCube(0.6);
      glTranslatef(-3, 0, 0); 
     /****Kraj gore*****/
      
      /*****Desnooooo*****/
     glTranslatef(3, 0, 1);
      glutSolidCube(0.6);
      glTranslatef(-3, 0, -1);
      
      
      glTranslatef(3, 0, 2);
      glutSolidCube(0.6);
      glTranslatef(-3, 0, -2);
      
      glTranslatef(3, 0, 3);
      glutSolidCube(0.6);
      glTranslatef(-3, 0, -3);
      
      
      glTranslatef(3, 0, 4);
      glutSolidCube(0.6);
      glTranslatef(-3, 0, -4);
      
      
      glTranslatef(3, 0, 5);
      glutSolidCube(0.6);
      glTranslatef(-3, 0, -5);
      
    
      /* Kraajj  Desnoooo*///
      
      /********Doleee*********/
      
      
     
    glTranslatef(0, 0, 5);
      glutSolidCube(0.6);
    glTranslatef(0, 0, -5); 
    
    glTranslatef(-1, 0, 5);
      glutSolidCube(0.6);
    glTranslatef(1, 0, -5); 
   
      glTranslatef(-2, 0, 5);
      glutSolidCube(0.6);
       glTranslatef(2, 0, -5); 
      
    
      
      glTranslatef(1, 0, 5);
      glutSolidCube(0.6);
      glTranslatef(-1, 0, -5);
      
      glTranslatef(2, 0, 5);
      glutSolidCube(0.6);
      glTranslatef(-2, 0, -5);
      
    
     
  /********* Krajj   Doleeeeeeeee*////////
  
  
  
  /*************LEVOOOO*************/
  
      glTranslatef(-3, 0, 1);
         glutSolidCube(0.6);
       glTranslatef(3, 0, -1); 
        
     // glTranslatef(-3, 0, 1);
     //    glutSolidCube(0.6);
    //  glTranslatef(3, 0, -1);
      
      
      glTranslatef(-3, 0, 2);
      glutSolidCube(0.6);
      glTranslatef(3, 0, -2);
      
      glTranslatef(-3, 0, 3);
      glutSolidCube(0.6);
      glTranslatef(3, 0, -3);
      
      
      glTranslatef(-3, 0, 4);
      glutSolidCube(0.6);
      glTranslatef(3, 0, -4);
      
      
      glTranslatef(-3, 0, 5);
        glColor3f(0, 0.7, 0.2);
        glutSolidCube(0.6);
      glTranslatef(3, 0, -5);     
       
       
       /**************** Kraj LEVOOOOO*********/

}
