#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "kocka.h"
#include "pomeranje.h"
#include "tabla.h"
#include "figure.h"
int pocetna_poz=0;
int igraj(int broj,int playable){
    if(playable)
    return pocetna_poz+=broj;
    else {
    printf("BORBA\n");
    return pocetna_poz;
    }
}


