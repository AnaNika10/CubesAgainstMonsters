#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h> 
#include "kocka.h"
#include "pomeranje.h"
 
void Kocke(){

   //crta zeleni kvadrat koji predstavlja kocku za pomeranje
    glColor3f(0, 0.7, 0.2);
    glBegin(GL_POLYGON);
       glVertex3f(2.0f, 5.0f, -2.0f); // top left
       glVertex3f(4.0f, 5.0f, -2.0f); // top right 
       glVertex3f(4.0f, 3.0f, 0.0f); // bottom right
       glVertex3f(2.0f, 3.0f, 0.0f); // bottom left
    glEnd();
   
   
    //crta crveni kvadrat koji predstavlja kocku za borbu
    glColor3f(1,0,0);
   glBegin(GL_POLYGON);
       glVertex3f(5.0f, 5.0f, -2.0f); // top left
       glVertex3f(7.0f, 5.0f, -2.0f); // top right 
       glVertex3f(7.0f, 3.0f, 0.0f); // bottom right
       glVertex3f(5.0f, 3.0f, 0.0f); //bottom left
    glEnd();
}
//vraca pseudo-slucajni broj
int random_num(){
    

    int nRandonNumber = rand()%6 + 1;

    return nRandonNumber;

}
// iscrtava tackice na kocki u zavisnosti od dobijenog broja
void Tacke1(int broj,int state){
    

    if(state==1){
   glColor3f(0,0,0);
    glPointSize(15);
    if(broj==1){
    glBegin(GL_POINTS);
          glVertex3f(3.0f, 4.0f, -1.0f); //-1
    glEnd();
    glFlush();
    }
    else if(broj==2){
    glBegin(GL_POINTS);
          glVertex3f(2.2f, 3.4f, 0.0f);  //0
           glVertex3f(3.8f, 4.6f, -2.0f); //-2
    glEnd();
    glFlush();
    }
    else if(broj==3){
    glBegin(GL_POINTS);
          glVertex3f(3.8f, 4.6f, -2.0f); //-2
           glVertex3f(3.0f, 4.0f, -1.0f); //-1
            glVertex3f(2.2f, 3.4f, 0.0f); //0
    glEnd();
    glFlush();
    }
    else if(broj==4){
    glBegin(GL_POINTS);
        glVertex3f(2.5f, 4.7f, -2.0f); // top left  //-2
       glVertex3f(3.9f, 4.7f, -2.0f); // top right  //-2
       glVertex3f(3.5f, 3.4f, 0.0f); // bottom right //0
       glVertex3f(2.2f, 3.4f, 0.0f); //bottom left //0
    glEnd();
    glFlush();
     }
   

else if(broj==5){
    glBegin(GL_POINTS);
        glVertex3f(2.5f, 4.7f, -2.0f); // top left //-2
       glVertex3f(3.9f, 4.7f, -2.0f); // top right //-2
       glVertex3f(3.0f, 4.0f, -1.0f); //center //-1
       glVertex3f(3.5f, 3.4f, 0.0f); // bottom right //0
       glVertex3f(2.2f, 3.4f, 0.0f); //0
    glEnd();
    glFlush();
    
}
else if(broj==6){
    glBegin(GL_POINTS);
        
       glVertex3f(3.85f, 4.7f, -2.0f); // top right 
       glVertex3f(3.7f, 4.0f, -1.0f); // top center
       glVertex3f(3.5f, 3.4f, 0.0f); // bottom right
       
       
       glVertex3f(2.45f, 4.7f, -2.0f); // top left
       glVertex3f(2.35f, 4.0f, -1.0f); // top center
       glVertex3f(2.2f, 3.4f, 0.0f); //bottom left
    glEnd();
    glFlush();
    
    }
     }

}
void Tacke2(int broj,int state){
  
  if(state==1){
   glColor3f(0,0,0);
    glPointSize(15);
    if(broj==1){
    glBegin(GL_POINTS);
          glVertex3f(6.0f, 4.0f, -1.0f); //-1
    glEnd();
    glFlush();
    }
    else if(broj==2){
    glBegin(GL_POINTS);
          glVertex3f(5.0f, 3.4f, 0.0f);  //0
           glVertex3f(7.0f, 4.6f, -2.0f); //-2
    glEnd();
    glFlush();
    }
    else if(broj==3){
    glBegin(GL_POINTS);
          glVertex3f(7.0f, 4.6f, -2.0f); //-2
           glVertex3f(6.0f, 4.0f, -1.0f); //-1
            glVertex3f(5.0f, 3.4f, 0.0f); //0
    glEnd();
    glFlush();
    }
    else if(broj==4){
    glBegin(GL_POINTS);
       glVertex3f(5.5f, 4.7f, -2.0f); // top left  //-2
       glVertex3f(6.9f, 4.7f, -2.0f); // top right  //-2
       glVertex3f(6.3f, 3.4f, 0.0f); // bottom right //0
       glVertex3f(5.0f, 3.4f, 0.0f); //bottom left //0
    glEnd();
    glFlush();
    
}
else if(broj==5){
    glBegin(GL_POINTS);
       glVertex3f(5.5f, 4.7f, -2.0f); // top left  //-2
       glVertex3f(6.9f, 4.7f, -2.0f); // top right  //-2
       glVertex3f(6.0f, 4.0f, -1.0f); //center //-1
       glVertex3f(6.3f, 3.4f, 0.0f); // bottom right //0
       glVertex3f(5.0f, 3.4f, 0.0f); //bottom left //0
    glEnd();
  
    glFlush();
    
}
else if(broj==6){
    glBegin(GL_POINTS);
        
       glVertex3f(7.0f, 4.7f, -2.0f); // top right 
       glVertex3f(6.7f, 4.0f, -1.0f); // top center
       glVertex3f(6.3f, 3.4f, 0.0f); // bottom right
       
       
       glVertex3f(5.55f, 4.7f, -2.0f); // top left
       glVertex3f(5.3f, 4.0f, -1.0f); // top center
       glVertex3f(5.0f, 3.4f, 0.0f); //bottom left
    glEnd();
    glFlush();
    
    }
  }
}
