#include <iostream>
#include <cmath>

#define M 4
#define N 10

using namespace std;

//fattoriale
double fact (int n) {
	if (n <= 1)
		return 1;
	
	return n*fact(n-1);
}

int main () {
	//numero di matricola: 4185248 utilizzato per il punto C)
	int d0 = 8, d1 = 4;
	int n = (d1 + 1)*10 + d0;

	cout << "Il numero di matricola considerato e' 4185248 percio' avremo d0 = " << d0 << " e d1 = " << d1 << endl << endl;

	int matrix1[M][M] = {{3,1,-1,0}, {0,7,-3,0}, {0,-3,9,-2}, {0,0,4,-10}}, 
		matrix2[M][M] = {{2,4,-2,0}, {1,3,0,1}, {3,-1,1,2}, {0,-1,2,1}},
		rawSum1 = 0, rawSum2 = 0, norma1 = 0, norma2 = 0,
		pascal[N][N], norma_pascal = 0, tridiagonale[n][n], norma_trid = 0;

	//calolo della norma per le 2 matrici di partenza
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			rawSum1 += abs(matrix1[i][j]);
			rawSum2 += abs(matrix2[i][j]);
		}
		
		if (norma1 < rawSum1)
			norma1 = rawSum1;

		if (norma2 < rawSum2)
			norma2 = rawSum2;

		rawSum1 = rawSum2 = 0;
	}	

	//inizializzazione e calcolo della norma della matrice di Pascal	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			pascal[i][j] = fact((i+1) + (j+1) - 2)/(fact((i+1) - 1)*fact((j+1) - 1));
			rawSum1 += pascal[i][j];	//non uso il valore assoluto perche' gli indici sono positivi e crescono sempre
		}
		
		if (norma_pascal < rawSum1)
			norma_pascal = rawSum1;
	
		rawSum1 = 0;
	}	

	//inizializzazione e calcolo della norma della matrice tridiagonale
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++) {
			if (i == j)
				tridiagonale[i][j] = 2;
			else if (abs(i-j) == 1)
				tridiagonale[i][j] = -1;
			else
				tridiagonale[i][j] = 0;

			rawSum2 += abs(tridiagonale[i][j]);						
		}
	
		if (norma_trid < rawSum2)
			norma_trid = rawSum2;

		rawSum2 = 0;
	}

	cout << "La norma infinita di matrix1 e' " << norma1 << endl;
	cout << "La norma infinita di matrix2 e' " << norma2 << endl; 
	cout << "La norma infinita della matrice di Pascal e' " << norma_pascal << endl;
	cout << "La norma infinita della matrice tridiagonale di dimensione " << n << " e' " << norma_trid << endl << endl;

	return 0;
}
