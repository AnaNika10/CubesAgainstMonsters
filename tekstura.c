#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "image.h"
#include "tekstura.h"



//imena fajlova sa teksturama
#define FILENAME0 "7.bmp"
#define FILENAME1 "8.bmp"

//identifikatori tekstura
static GLuint names[1];

void initialize(void)
{
    //objekat koji predstavlja teskturu ucitanu iz fajla
    Image * image;

    //ukljucuje se testiranje z-koordinate piksela
    glEnable(GL_DEPTH_TEST);

    //ukljucuju se teksture
    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

     //inicijalizuje se objekat koji ce sadrzati teksture ucitane iz
    //fajla
    image = image_init(0, 0);

    //kreira se prva tekstura
    image_read(image, FILENAME0);

    //generisu se identifikatori tekstura
    glGenTextures(2, names);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    //kreira se druga tekstura
    image_read(image, FILENAME1);

    glBindTexture(GL_TEXTURE_2D, names[1]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    //iskljucujemo aktivnu teksturu
    glBindTexture(GL_TEXTURE_2D, 0);

    //unistava se objekat za citanje tekstura iz fajla
    image_done(image);
}

void textures(){
    
   //iscrtava se pozadina
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS); //19
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3, 0.31 , -0.3+5 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3, 0.31, -0.3+5);

        glTexCoord2f(1, 1);
        glVertex3f(0.3,0.31,0.3+5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3, 0.31,0.3+5);
    glEnd();
    
    glBegin(GL_QUADS); //18
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0); 
        glVertex3f(-0.3+1, 0.31, -0.3+5 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3+1, 0.31, -0.3+5);

        glTexCoord2f(1, 1);
        glVertex3f(0.3+1,0.31,0.3+5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3+1, 0.31,0.3+5);
    glEnd();
     glBegin(GL_QUADS); //20
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3-1, 0.31 , -0.3+5 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3-1, 0.31, -0.3+5);

        glTexCoord2f(1, 1);
        glVertex3f(0.3-1,0.31,0.3+5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3-1, 0.31,0.3+5);
    glEnd();
    glBegin(GL_QUADS); //21
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3-2, 0.31, -0.3+5 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3-2, 0.31, -0.3+5);

        glTexCoord2f(1, 1);
        glVertex3f(0.3-2,0.31,0.3+5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3-2, 0.31,0.3+5);
    glEnd();
    glBegin(GL_QUADS); //17
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3+2, 0.31 , -0.3+5 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3+2, 0.31, -0.3+5);

        glTexCoord2f(1, 1);
        glVertex3f(0.3+2,0.31,0.3+5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3+2, 0.31,0.3+5);
    glEnd();
     glBegin(GL_QUADS); //16
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3+3, 0.31 , -0.3+5 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3+3, 0.31, -0.3+5);

        glTexCoord2f(1, 1);
        glVertex3f(0.3+3,0.31,0.3+5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3+3, 0.31,0.3+5);
    glEnd();
      glBegin(GL_QUADS); //1
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3-3, 0.31 , -0.3+4 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3-3, 0.31, -0.3+4);

        glTexCoord2f(1, 1);
        glVertex3f(0.3-3,0.31,0.3+4);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3-3, 0.31,0.3+4);
    glEnd();
     glBegin(GL_QUADS); //2
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3-3, 0.31 , -0.3+3 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3-3, 0.31, -0.3+3);

        glTexCoord2f(1, 1);
        glVertex3f(0.3-3,0.31,0.3+3);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3-3, 0.31,0.3+3);
    glEnd();
     glBegin(GL_QUADS); //3
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3-3, 0.31 , -0.3+2 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3-3, 0.31, -0.3+2);

        glTexCoord2f(1, 1);
        glVertex3f(0.3-3,0.31,0.3+2);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3-3, 0.31,0.3+2);
    glEnd();
     glBegin(GL_QUADS); //4
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3-3, 0.31 , -0.3+1 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3-3, 0.31, -0.3+1);

        glTexCoord2f(1, 1);
        glVertex3f(0.3-3,0.31,0.3+1);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3-3, 0.31,0.3+1);
    glEnd();
     glBegin(GL_QUADS); //5
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3-3, 0.31 , -0.3 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3-3, 0.31, -0.3);

        glTexCoord2f(1, 1);
        glVertex3f(0.3-3,0.31,0.3);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3-3, 0.31,0.3);
    glEnd();
      glBegin(GL_QUADS); //6
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3-2, 0.31 , -0.3 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3-2, 0.31, -0.3);

        glTexCoord2f(1, 1);
        glVertex3f(0.3-2,0.31,0.3);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3-2, 0.31,0.3);
    glEnd();
     glBegin(GL_QUADS); //7
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3-1, 0.31 , -0.3 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3-1, 0.31, -0.3);

        glTexCoord2f(1, 1);
        glVertex3f(0.3-1,0.31,0.3);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3-1, 0.31,0.3);
    glEnd();
    glBegin(GL_QUADS); //8
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3, 0.31 , -0.3 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3, 0.31, -0.3);

        glTexCoord2f(1, 1);
        glVertex3f(0.3,0.31,0.3);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3, 0.31,0.3);
    glEnd();
    glBegin(GL_QUADS); //9
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3+1, 0.31 , -0.3 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3+1, 0.31, -0.3);

        glTexCoord2f(1, 1);
        glVertex3f(0.3+1,0.31,0.3);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3+1, 0.31,0.3);
    glEnd();
     glBegin(GL_QUADS); //10
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3+2, 0.31 , -0.3 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3+2, 0.31, -0.3);

        glTexCoord2f(1, 1);
        glVertex3f(0.3+2,0.31,0.3);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3+2, 0.31,0.3);
    glEnd();
    glBegin(GL_QUADS); //11
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3+3, 0.31 , -0.3 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3+3, 0.31, -0.3);

        glTexCoord2f(1, 1);
        glVertex3f(0.3+3,0.31,0.3);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3+3, 0.31,0.3);
    glEnd();
     glBegin(GL_QUADS); //12
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3+3, 0.31 , -0.3+1 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3+3, 0.31, -0.3+1);

        glTexCoord2f(1, 1);
        glVertex3f(0.3+3,0.31,0.3+1);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3+3, 0.31,0.3+1);
    glEnd();
    glBegin(GL_QUADS); //13
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3+3, 0.31 , -0.3+2 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3+3, 0.31, -0.3+2);

        glTexCoord2f(1, 1);
        glVertex3f(0.3+3,0.31,0.3+2);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3+3, 0.31,0.3+2);
    glEnd();
    glBegin(GL_QUADS); //14
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3+3, 0.31 , -0.3+3 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3+3, 0.31, -0.3+3);

        glTexCoord2f(1, 1);
        glVertex3f(0.3+3,0.31,0.3+3);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3+3, 0.31,0.3+3);
    glEnd();
    glBegin(GL_QUADS); //15
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3+3, 0.31 , -0.3+4 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3+3, 0.31, -0.3+4);

        glTexCoord2f(1, 1);
        glVertex3f(0.3+3,0.31,0.3+4);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3+3, 0.31,0.3+4);
    glEnd();
    
    
    
    glBindTexture(GL_TEXTURE_2D, 0);
    /***** Postavljanje teksture na pocetno polje *******/
    glBindTexture(GL_TEXTURE_2D, names[1]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-0.3-3, 0.31 , -0.3+5 );

        glTexCoord2f(1, 0);
        glVertex3f(0.3-3, 0.31, -0.3+5);

        glTexCoord2f(1, 1);
        glVertex3f(0.3-3,0.31,0.3+5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.3-3, 0.31,0.3+5);
    glEnd();

    //iskljucujemo aktivnu teksturu
    glBindTexture(GL_TEXTURE_2D, 0);
}
