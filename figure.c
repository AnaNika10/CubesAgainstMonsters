#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "figure.h"
#include "pomeranje.h"
void kreirajPijuna(int x,int y,int z){

    glColor3f(0.196078,0.196078,0.8);
     glTranslatef(x,y,z);
     glRotatef(280, 1, 0, 0);
       glutSolidCone(0.2, 1, 50, 50);
     glRotatef(-280, 1, 0, 0);   
    glTranslatef(-x,-y,-z);     
    
}

void kreirajCudovista(int key){
    
    glColor3f(0, 0, 0);
    if(key==1){
    //if(!goaway[2]) {   
    glTranslatef(0, 0.7, 0);
        glutSolidSphere(0.3,10,10);
    glTranslatef(0, -0.7, 0);
    //}
    //if(!goaway[0]){
    glTranslatef(-3, 0.7, 1);
        glutSolidSphere(0.3,10,10);
    glTranslatef(3, -0.7, -1);
   // }
    //if(!goaway[4]){
    glTranslatef(2, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-2, -0.7, -5);
   // }
   // if(!goaway[3]){
    glTranslatef(3, 0.7, 2);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-3, -0.7, -2);
    //}
    //if(!goaway[1]){
    glTranslatef(-2, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(2, -0.7, -5);
    //}
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
      
    glTranslatef(3, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-3, -0.7, -5);
      
    glTranslatef(-1, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(1, -0.7, -5);
    
    glTranslatef(-3, 0.7, 1);
        glutSolidSphere(0.3,10,10);
    glTranslatef(3, -0.7, -1);
      
    glTranslatef(-3, 0.7, 3);
        glutSolidSphere(0.3,10,10);
    glTranslatef(3, -0.7, -3);
        
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
      
   // glTranslatef(-1, 0.7, 5);
   //     glutSolidSphere(0.3,10,10);
   // glTranslatef(1, -0.7, -5);
    
    glTranslatef(1, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(-1, -0.7, -5);
      
    glTranslatef(-2, 0.7, 5);
        glutSolidSphere(0.3,10,10);
    glTranslatef(2, -0.7, -5);
}

    
}
int pronadji(int *niz,int n,int vrednost)
{
     int nasao=0;
     int c,poz;
     for(c = 0; c < n; c++)
         if(*(niz+c) == vrednost){
            nasao = 1;
            poz = c;
            break; 
        }
    
    if(nasao)
        return poz;
    else
        return -1;
}


int obrisi_element(int *niz,int n,int vrednost)
{
   int uspesno=0;

    int c, poz;
    
    int nasao = 0; 
    
    for(c = 0; c < n; c++)
    {
        if(*(niz+c) == vrednost)
        {
            nasao = 1;
            poz = c;
            break; 
        }
    }
    if(nasao == 1)
    {
        
            *(niz+poz) = 0;
         uspesno=1;  
    }
    return uspesno;
   
}
