#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "figure.h"
void kreirajPijuna(){

    
    glColor3f(0, 0, 1);
     glTranslatef(-2.5, 1, 5);
     glRotatef(280, 1, 0, 0);
       glutSolidCone(0.2, 1, 50, 50);
     glRotatef(-280, 1, 0, 0);   
glTranslatef(2.5,-1,-5);     
    
}

void kreirajCudovista(int key){
    
    glColor3f(0, 0, 0);
    if(key==1){
    glTranslatef(0, 0.7, 0);
        glutSolidSphere(0.3,10,10);
    glTranslatef(0, -0.7, 0);
      
    glTranslatef(-3, 0.7, 1);
        glutSolidSphere(0.3,10,10);
    glTranslatef(3, -0.7, -1);
      
    glTranslatef(2, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-2, -0.7, -5);
      
    glTranslatef(3, 0.7, 2);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-3, -0.7, -2);
      
    glTranslatef(-2, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(2, -0.7, -5);

   } else if(key==2){
    glTranslatef(-1, 0.7, 0);
        glutSolidSphere(0.3,10,10);
    glTranslatef(1, -0.7, 0);
      
    glTranslatef(2, 0.7, 0);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-2, -0.7, 0);
      
    glTranslatef(3, 0.7, 2);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-3, -0.7, -2);
      
    glTranslatef(3, 0.7, 4);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-3, -0.7, -4);
      
    glTranslatef(-1, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(1, -0.7, -5);
    
    glTranslatef(-3, 0.7, 1);
        glutSolidSphere(0.3,10,10);
    glTranslatef(3, -0.7, -1);
      
    glTranslatef(-3, 0.7, 4);
        glutSolidSphere(0.3,10,10);
    glTranslatef(3, -0.7, -4);
        
    }
    else if(key==3){
    glTranslatef(-3, 0.7, 3);
        glutSolidSphere(0.3,10,10);
    glTranslatef(3, -0.7, -3);
      
    glTranslatef(1, 0.7, 0);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-1, -0.7, 0);
      
    glTranslatef(-2, 0.7, 0);
        glutSolidSphere(0.3,10,10);
    glTranslatef(2, -0.7, 0);
      
    glTranslatef(3, 0.7, 0);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-3, -0.7, 0);
      
    glTranslatef(-3, 0.7, 1);
        glutSolidSphere(0.3,10,10);
    glTranslatef(3, -0.7, -1);
      
    
    glTranslatef(3, 0.7, 2);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-3, -0.7, -2);
    
    glTranslatef(3, 0.7, 4);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-3, -0.7, -4);
      
    glTranslatef(-1, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(1, -0.7, -5);
    
    glTranslatef(1, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-1, -0.7, -5);
      
    glTranslatef(-2, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(2, -0.7, -5);
}

    
}
