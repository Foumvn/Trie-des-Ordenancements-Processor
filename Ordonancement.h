#ifndef ORDONANCEMENT_H
#define ORDONANCEMENT_H

typedef struct donnees{

    int pid;
    int time_exc;
    int time_arv;
    int prio;

}donnees;

 void ScannerProcessus();
void AfficherProcessus();
donnees *trie_par_FIFO(donnees tab[], int taille);
donnees *trie_par_SJF(donnees tab[], int taille);
donnees *trie_par_Premption(donnees tab[],int taille);
void Calcul_Processus(donnees tab[], int taille,int id_p);


#endif