#include <stdio.h>
#include <stdlib.h>
#include "Ordonancement.h"

void ScannerProcessus(donnees tab[], donnees tabTrier[]){

     
    FILE *fichier= fopen("process.txt","r");
    int caractP[4][4];
    int pid,i,j;
    int a,k=0;
    int taille=4;
    char c;
    if(fichier == NULL){ exit(1);}
    for(i=1;i<=4;i++){
      for(j=1;j<=4;j++){
        fscanf(fichier,"%d",&caractP[i][j]);
       }
    }

    fclose(fichier);
       j=1;
      while(j<5)
     {   i=1;
         k=k+1;
        tab[k].pid= caractP[i][j];
        tab[k].time_exc= caractP[i+1][j];
        tab[k].time_arv= caractP[i+2][j];
        tab[k].prio= caractP[i+3][j];
           j=j+1;
     }
      
    for (i=1; i <=4;i++){
        printf("Processus %d",tab[i].pid);
        printf("         \n");
        printf("Temps Execution: %d\n",tab[i].time_exc);  
        printf("Temps Arrivage: %d\n",tab[i].time_arv);
        printf("Priorite: %d\n",tab[i].prio);
        printf("------------------------------\n");   
    }
  
     printf(" Selectionner un trie a executer: \n");  
     printf("                  \n");
     

    printf("1-trie par FIFO\n");
    printf("\n");        
    printf("2-trie par SJF\n");         
    printf("\n");         
    printf("3-trie par Preemption\n");
    scanf("%d",&a);
      
    switch(a){

        case 1:
           tabTrier=trie_par_FIFO(tab ,taille);
        case 2:
           tabTrier=trie_par_SJF(tab,taille);
        case 3:
           tabTrier = trie_par_Premption(tab, taille);          
    }
        for (i=1; i <=4;i++)
           {
                printf("Processus %d",tabTrier[i].pid);
                printf("         \n");
                
                printf("Temps Execution: %d\n",tabTrier[i].time_exc);  
                printf("Temps Arrivage: %d\n",tabTrier[i].time_arv);
                printf("Priorite: %d\n",tabTrier[i].prio);
                printf("------------------------------\n");   
            }
    printf("*****CALCUL DES CARACTERISTIQUES DU PROCESSUS*******");
     printf("  \n");
     
    
    while(c!='q'){
            
        printf("Entrez le pid du processus a calculer:");
        scanf("%d",&pid);
        printf(" \n");
        Calcul_Processus(tab,taille,pid);

      printf("Saisissez Q pour quitter le programme..");
      scanf("%c",&c);
      printf(" \n");      

    }
      
 

}

 donnees *trie_par_FIFO(donnees tab[], int taille)
 {
     donnees tmp; 
     int arv,prior,exc,id;
    int i = 0 ;
    int j  = 0 ;
   

    for (i=0 ; i < taille+1; i++){
        for (j=i+1; j < taille; j++){
            if(tab[i].time_arv > tab[j].time_arv)
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
      }
      
    return tab; 

    
 }



 donnees* trie_par_SJF(donnees tab[],int taille){ 

    donnees tmp; 
    int arv,prior,exc,id;
    int i = 0 ;
    int j  = 0 ;

    for (i=0 ; i < taille+1; i++){
        for (j=i+1; j < taille; j++){
            if(tab[i].time_exc > tab[j].time_exc)
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }
    
      
    return tab;
}




donnees* trie_par_Premption(donnees tab[],int taille)
{
    donnees temp; 
    int arv,prior,exc,id;
    int i = 0 ;
    int j  = 0 ;

    for (i=0 ; i < 5; i++){
        for (j=i+1; j < taille; j++){
            if(tab[i].prio > tab[j].prio)
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
      
    return tab; 
}

void Calcul_Processus(donnees tab[], int taille,int id_p)
 {
         double sejour, calcul[4],sejour_moy,attent, attent_moy,som;
      int i,val,id;
        val=0;
          i=1;
          
       while(val!=1){
            if(tab[i].pid==id_p){
                id=i;
                val=1;

            } else{i=i+1;}
       }
      //temps de sejour
       sejour=tab[id].time_arv-tab[id].time_exc ;

       //temps moy de sejour
       som=0;
       for(i=1;i<=4;i++){
           som=som+tab[i].time_exc+tab[i].time_arv;
       }
          sejour_moy=som/taille;
    
      //temps attente
    attent=sejour-tab[id].time_exc;
      
      //temps moy attente
      som=0;
     for(i=1;i<=4;i++)
        {
         som=som+sejour-tab[id].time_exc;
        }
       attent_moy=som/4;

        calcul[1]=sejour;
        calcul[2]=sejour_moy;
        calcul[3]=attent;
        calcul[4]=attent_moy;   

        printf("Son sejour vaut: %f\n",calcul[1]);
        printf(" \n");
       printf("Le sejour moyenne vaut: %f\n",calcul[2]);
       printf(" \n");
       printf("Son temps d'attente vaut: %f\n",calcul[3]);
       printf(" \n");
       printf("L'attente moyenne vaut: %f\n",calcul[4]);
       printf(" \n");   
       printf(" ********************************\n");
       
      
  }