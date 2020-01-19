#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include "osvetljenje.h"


void postavi_osvetljenje(){
    
    //pozicija svetla
    GLfloat light_position[] = {0,5,2.5, 0 };

    //ambijentalna komponenta svetlosti
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1 };

    //difuzna komponenta svetlosti
    GLfloat light_diffuse[] = { 1, 1, 1, 1 };
    
    //spekularna komponenta svetlosti
    GLfloat light_specular[] = { 0.8, 0.8, 0.2, 1 };
   // GLfloat light_specular[] = {1, 1, 1, 1,};

    //koeficijenti ambijentalne refleksije materijala
    GLfloat ambient_coeffs[] = { 0.1, 0.1, 0.1, 1 };

    //koeficijenti difuzne refleksije materijala
    GLfloat diffuse_coeffs[] = { 0.7, 0.7, 0.7, 1 };

    //koeficijenti spekularne refleksije materijala
    GLfloat specular_coeffs[] = { 1, 1, 1, 0 };

    //koeficijent glatkosti materijala
    GLfloat shininess = 30;

    //brise se prethodni sadrzaj prozora
    

    //ukljucuje se osvetljenje i podesavaju parametri svetla
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    //podesavaju se parametri materijala
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    glEnable(GL_COLOR_MATERIAL); 
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
 
}
