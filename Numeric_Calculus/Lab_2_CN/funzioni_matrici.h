#include <iostream>
#include <cmath>

#define M 4
#define N 10

//#define float double

using namespace std;

//funzioni ausiliarie
float fact (int);	//calcola il fattoriale di un numero
void libera_memoria(float** &, float* &, float* &, int);	//libera la memoria usata dai puntatori una volta finiti di usare

//funzioni sulle matrici
float pivot_parziale (int, float**, float*, int);	//esegue il pivoting parziale
void stampa_matrice (float**, int);	//stampa la matrice su standard output
void stampa_matrice_ridotta (float**, float*, int);	//stampa la matrice ridotta su standard output
void eliminazione_gaussiana (float**, float*, int);	//riduce la matrice con l'algoritmo dell'eliminazione gaussiana
bool eliminazione_gaussiana_indietro (float**, float*, int);	//se ci sono soluzioni le trovo eseguendo l'eliminazione gaussiana all'indietro
void calcola_termine_noto (float**, float*, float*, int);	//trovo il termine noto b data una matrice A di coefficienti e un vettore x di soluzioni
void stampa_vettore (float*, int);	//stampo un vettore su standard output
void crea_vettori (int, float* &, float* &);	//inizializza i vettori		
float** inizializza_matrice (int, float **, char);	//inizializza la matrice secondo diversi criteri
float norma_inf_vettore (int, float*);	//calcola la norma infinita di un vettore
void crea_vettore_perturbazione (int, float* &, float);	//crea il vettore perturbato come dalle specifiche <-----------------SERVE SOLO PER L'ESERCIZIO 3
void somma_vettori(int, float*, float*, float* &);	//somma due vettori
void sottrai_vettori(int, float*, float*, float* &); //sottrae due vettori
void calcolo_x_tilde(int, float**, float*, float* &);	//trovo la soluzione x per matrici con termini noti perturbati
