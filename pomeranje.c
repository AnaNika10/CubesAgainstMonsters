#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "kocka.h"
#include "pomeranje.h"
#include "tabla.h"
#include "figure.h"
// Funkcija izracunava polje na koje treba da dodjemo posle bacanja kockice
int igraj(int broj,int pomeraj,int playable){
    if(playable)
    return pomeraj+=broj;
    else {
    return pomeraj;
    }
}


