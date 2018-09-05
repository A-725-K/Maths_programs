#include "funzioni_matrici.h"

/***************************** FUNZIONI AUSILIARIE *********************************/

//fattoriale ricorsivo
float fact (int n) {
	if (n <= 1)
		return 1;
	
	return n*fact(n-1);
}

//cancella tutti i riferimenti dei puntatori
void libera_memoria(float** & m, float* & b, float* & x, int dim) {
	delete [] b;
	b = NULL;

	delete [] x;
	x = NULL;

	for (int i = 0; i < dim; i++)
		delete [] m[i];

	delete [] m;
	m = NULL;
}

/***************************FINE FUNZIONI AUSILIARIE *******************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/************************* FUNZIONI MATRICI DINAMICHE ******************************/

//calcola il pivoting parziale
float pivot_parziale (int n, float **m, float *b, int k) {
	float pv = m[k][k], swap[n];
	int indexMax = k;
	
	for (int i = k+1; i < n; i++) //ricerca del pivot maggiore
		if (fabs(m[i][k]) > fabs(pv)) {	//utilizzo la funzione fabs poiche' tratto dei float
			pv = m[i][k];
			indexMax = i;
		}

	for (int i = 0; i < n; i++) {	//swap tra la riga che voglio analizzare e quella con il pivot maggiore 
		swap[i] = m[indexMax][i];
		m[indexMax][i] = m[k][i];
		m[k][i] = swap[i];
	}

	//swap nel termine noto
	swap[0] = b[k];
	b[k] = b[indexMax];
	b[indexMax] = swap[0];

	return pv;
}

//stampa una matrice
void stampa_matrice (float **m, int dim) {
	for (int i = 0; i < dim; i++) {
		cout << "\t";
		for (int j = 0; j < dim; j++)
			cout << m[i][j] << "\t";
		cout << endl;
	}
}

//stampa la matrice ridotta poi | e il termine noto ridotto
void stampa_matrice_ridotta (float **m, float *b, int dim) {
	for (int i = 0; i < dim; i++) {
		cout << "\t";
		for (int j = 0; j < dim; j++)
			cout << m[i][j] << "\t";
		cout << "\t|\t" << b[i] << endl;
	}
}

//svolge l'eliminazione gaussiana
void eliminazione_gaussiana (float **m, float *b, int dim) {
	float perno, mult;	

	for (int k = 0; k < dim; k++) {
		perno = pivot_parziale(dim, m, b, k);	//pivoting parziale
		for (int i = k+1; i < dim; i++) {
			mult = m[i][k]/perno; 
			b[i] -= mult*b[k];
			for(int j = k; j < dim; j++)
				m[i][j] -= mult*m[k][j];
		}
	}
}

//svolge l'eliminazione gaussiana all'indietro
bool eliminazione_gaussiana_indietro (float **m, float *b, int dim) {
	if (m[dim-1][dim-1] != 0) {
		float perno, mult;	

		for (int i = dim-1; i > 0; i--) {
			perno = m[i][i];
			for (int j = i-1; j >= 0; j--) {
				mult = m[j][i]/perno;
				m[j][i] -= mult*perno;			
				b[j] -= mult*b[i];
			}
		}

		return true;
	} else
		return false;
}

//calcola il termine noto di una matrice
void calcola_termine_noto (float **m, float *x, float *b, int dim) {
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			b[i] += m[i][j]*x[j];
}

//stampa un vettore
void stampa_vettore (float *b, int dim) {
	for (int i = 0; i < dim; i++)
		cout << "\t" << b[i] << endl;
}

//inizializza i vettori
void crea_vettori (int dim, float* & x, float* & b) {
	x = new float[dim];
	b = new float[dim];
	
	for (int i = 0; i < dim; i++) {
		x[i] = 1.0;		//vettore x composto da soli 1
		b[i] = 0.0;		//vettore b composto da soli 0
	}
}

//calcola la soluzione con il vettore perturbato
void calcolo_x_tilde(int dim, float **m, float *bt, float* & xt) {
	for (int i = 0; i < dim; i++)
		xt[i] = bt[i]/m[i][i];
}

//inizializza le matrici
float** inizializza_matrice (int dim, float **m, char nome) {
	m = new float*[dim];

	for (int i = 0; i < dim; i++)
		m[i] = new float[dim];

	switch (nome) {
		case 'a':	//inizializzazione della matrice A
			m[0][0] = 3.0;
			m[0][1] = 1.0;
			m[0][2] = -1.0;
			m[0][3] = 0.0;
			m[1][0] = 0.0;
			m[1][1] = 7.0;
			m[1][2] = -3.0;
			m[1][3] = 0.0;
			m[2][0] = 0.0;
			m[2][1] = -3.0;
			m[2][2] = 9.0;
			m[2][3] = -2.0;
			m[3][0] = 0.0;
			m[3][1] = 0.0;
			m[3][2] = 4.0;
			m[3][3] = -10.0;
			
			break;
		case 'b':	//inizializzazione della matrice B
			m[0][0] = 2.0;
			m[0][1] = 4.0;
			m[0][2] = -2.0;
			m[0][3] = 0.0;
			m[1][0] = 1.0;
			m[1][1] = 3.0;
			m[1][2] = 0.0;
			m[1][3] = 1.0;
			m[2][0] = 3.0;
			m[2][1] = -1.0;
			m[2][2] = 1.0;
			m[2][3] = 2.0;
			m[3][0] = 0.0;
			m[3][1] = -1.0;
			m[3][2] = 2.0;
			m[3][3] = 1.0;

			break;
		case 'i':	//inizializzazione della matrice da input
			cout << "\n\nInserire i valori della matrice:" << endl;

			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					cout << "matrix[" << i+1 << "][" << j+1 << "] ---> ";
					cin >> m[i][j];
					cout << endl;	
				}
			}
			break;
		case 'p':	//inizializzazione della matrice di Pascal	
			for (int i = 0; i < dim; i++)
				for (int j = 0; j < dim; j++)
					m[i][j] = fact((i+1) + (j+1) - 2)/(fact((i+1) - 1)*fact((j+1) - 1));

			break;
		case 't':	//inizializzazione della matrice tridiagonale
			for (int i = 0; i < dim; i++)
				for (int j = 0; j < dim; j++) {
					if (i == j)
						m[i][j] = 2;
					else if (abs(i-j) == 1)
						m[i][j] = -1;
					else
						m[i][j] = 0;					
				}
			
			break;
		default:
			cout << "Errore nel parametro \"nome\"!\n" << endl;
			break;
	}

	return m;		
}

//somma 2 vettori delle stesse dimensioni entrata per entrata
void somma_vettori(int dim, float *a, float *b, float* & sol) {
	for (int i = 0; i < dim; i++)
		sol[i] = a[i] + b[i];
}

//sottrae 2 vettori delle stesse dimensioni entrata per entrata
void sottrai_vettori(int dim, float *a, float *b, float* & sol) {
	for (int i = 0; i < dim; i++)
		sol[i] = a[i] - b[i];
}

//inizializza un vettore perturbato
void crea_vettore_perturbazione (int dim, float* & delta_b, float norma) {
	delta_b = new float[dim];

	for (int i = 0; i < dim; i++)
		if ((i+1) % 2 == 0)
			delta_b[i] = 0.01*norma;
		else
			delta_b[i] = -0.01*norma;
}

//calcola la norma infinita di un vettore
float norma_inf_vettore (int dim, float *b) {
	float norma = 0;

	for (int i = 0; i < dim; i++)
		if (norma <= fabs(b[i]))
			norma = fabs(b[i]);

	return norma;
}

/************************* FINE FUNZIONI MATRICI DINAMICHE *************************/
