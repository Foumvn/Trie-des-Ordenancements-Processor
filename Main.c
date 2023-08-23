#include <stdio.h>
#include <stdlib.h>
#include "Ordonancement.h"

int main(int argc ,char *argv[])
{    
  int taille;
     FILE *fichier= fopen("process.txt","r");
     fscanf(fichier,"%d",&taille);

     donnees tab[taille];
     donnees tabTrier[taille];
     int a;
    
   ScannerProcessus(tab,tabTrier);

   
    return 0;
}