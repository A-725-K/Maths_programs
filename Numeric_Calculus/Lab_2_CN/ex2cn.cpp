#include "funzioni_matrici.h"

int main () {
	int scelta;
	
	cout << "Vuoi inserire matrici (1), utilizzare quelle gia' predefinite(2) o uscire(0)?\n";
	cin >> scelta;
	
	//controllo sull'input dell'utente
	while(!cin || scelta < 0 || scelta > 2) {
		cout << "Scelta scorretta. Re-inserire il valore >> ";
		cin >> scelta;
	}

	switch (scelta) {
		case 1:
		{

/*---------------------------------------------------- MATRICE DELL'UTENTE -----------------------------------------------------------*/

			float **matrix;
			float *x, *b;
			int dim;

			cout << "\nInserire le dimensioni della matrice:\n---> n = ";
			cin >> dim;

			//controllo sull'input dell'utente
			while(!cin || dim < 0) {
				cout << "Dimensione non accettabile. Re-inserire il valore >> ";
				cin >> dim;
			}

			//creazione della matrice da parte dell'utente
			matrix = inizializza_matrice(dim, matrix, 'i');
		
			//creo il vettore b con tutti 0 per evitare errori nei calcoli e il vettore x con 1 come da richiesta
			crea_vettori(dim, x, b);		

			//stampa della matrice inserita dall'utente
			cout << "La matrice che hai inserito e':" << endl;
			stampa_matrice(matrix, dim);			

			//calcolo del termine noto
			calcola_termine_noto(matrix, x, b, dim);
			
			//stampa del termine noto
			cout << "\nIl termine noto e':" << endl;
			stampa_vettore(b, dim);

			//eliminazione Gaussiana
			eliminazione_gaussiana(matrix, b, dim);

			//eliminazione Gaussiana all'indietro
			if (!eliminazione_gaussiana_indietro(matrix, b, dim)) {
				cout << "\n**************** Matrice non risolvibile! ---> ci sono inf^n soluzioni ****************" << endl;
				return 0;
			}

			//stampa della matrice ridotta (eliminazione Gaussiana)
			cout << "\nLa matrice ridotta e':" << endl;
			stampa_matrice_ridotta(matrix, b, dim);

			//libero la memoria per non sprecare spazio
			libera_memoria(matrix, x, b, dim);

			break;
		}
		case 2:
		{	
			int d0 = 8, d1 = 4;
			int n = (d1 + 1)*10 + d0;
	
			float ** matrix;	//matrice dinamica			
			float *x, *b;		//vettore delle soluzioni e vettore dei termini noti

			cout << "_____________________________________________________________________________\n\n";

/*---------------------------------------------------- MATRICE A -----------------------------------------------------------*/

			//creazione della matrice A
			matrix = inizializza_matrice(M, matrix, 'a');

			//creo il vettore b con tutti 0 per evitare errori nei calcoli e il vettore x con 1 come da richiesta
			crea_vettori(M, x, b);

			//stampa della matrice A
			cout << "Matrice A :" << endl;
			stampa_matrice(matrix, M);

			//calcolo termine noto della matrice A
			calcola_termine_noto(matrix, x, b, M);

			//stampa del termine noto della matrice A
			cout << "\nIl termine noto della Matrixce A e':" << endl;
			stampa_vettore(b, M);

			//eliminazione Gaussiana sulla matrice A
			eliminazione_gaussiana(matrix, b, M);

			//eliminazione Gaussiana all'indietro sulla matrice A
			if (!eliminazione_gaussiana_indietro(matrix, b, M)) {
				cout << "\n**************** Matrice A non risolvibile! ---> ci sono inf^n soluzioni ****************" << endl;
				return 0;
			}
			
			//stampa della Matrice A ridotta (eliminazione Gaussiana)
			cout << "\nLa Matrice A ridotta e':" << endl;
			stampa_matrice_ridotta(matrix, b, M);

			//libero la memoria per fare spazio alla nuova matrice
			libera_memoria(matrix, x, b, M);
			cout << endl;
			cout << "_____________________________________________________________________________\n\n";

/*---------------------------------------------------- MATRICE B -----------------------------------------------------------*/

			//creazione della matrice B
			matrix = inizializza_matrice(M, matrix, 'b');
			
			//creo il vettore b con tutti 0 per evitare errori nei calcoli e il vettore x con 1 come da richiesta
			crea_vettori(M, x, b);

			//stampa della matrice B
			cout << "Matrice B :" << endl;
			stampa_matrice(matrix, M);

			//calcolo termine noto della Matrice B
			calcola_termine_noto(matrix, x, b, M);

			//stampa del termine noto della Matrice B
			cout << "\nIl termine noto della Matrice B e':" << endl;
			stampa_vettore(b, M);

			//eliminazione Gaussiana sulla matrice B
			eliminazione_gaussiana(matrix, b, M);

			//eliminazione Gaussiana all'indietro sulla matrice B
			if (!eliminazione_gaussiana_indietro(matrix, b, M)) {		
				cout << "\n**************** La Matrice B non risolvibile! ---> ci sono inf^n soluzioni ****************" << endl;
				return 0;
			}

			//stampa della Matrice B ridotta (eliminazione Gaussiana)
			cout << "\nLa Matrice B ridotta e':" << endl;				
			stampa_matrice_ridotta(matrix, b, M);

			//libero la memoria per fare spazio alla nuova matrice
			libera_memoria(matrix, x, b, M);
			cout << endl;
			cout << "_____________________________________________________________________________\n\n";

/*------------------------------------------------ MATRICE DI PASCAL -----------------------------------------------------------*/

			//creazione della matrice di Pascal
			matrix = inizializza_matrice(N, matrix, 'p');

			//creo il vettore b con tutti 0 per evitare errori nei calcoli e il vettore x con 1 come da richiesta
			crea_vettori(N, x, b);

			//stampa della matrice di Pascal
			cout << "Matrice di Pascal :" << endl;
			stampa_matrice(matrix, N);			
				
			//calcolo termine noto della matrice di Pascal
			calcola_termine_noto(matrix, x, b, N);

			//stampa del termine noto della matrice di Pascal
			cout << "\nIl termine noto della matrice di Pascal e':" << endl;
			stampa_vettore(b, N);

			//eliminazione Gaussiana sulla matrice di Pascal
			eliminazione_gaussiana(matrix, b, N);

			//eliminazione Gaussiana all'indietro sulla matrice di Pascal
			if (!eliminazione_gaussiana_indietro(matrix, b, N)) {
				cout << "\n**************** Matrice di Pascal non risolvibile! ---> ci sono inf^n soluzioni ****************" << endl;
				return 0;
			}
					
			//stampa della matrice di Pascal ridotta (eliminazione Gaussiana)
			cout << "\nLa Matrice di Pascal ridotta e':" << endl;			
			stampa_matrice_ridotta(matrix, b, N);

			//libero la memoria per fare spazio alla nuova matrice
			libera_memoria(matrix, x, b, N);

			cout << endl;
			cout << "_____________________________________________________________________________\n\n";
			
/*------------------------------------------------ MATRICE TRIDIAGONALE -----------------------------------------------------------*/
			
			//creazione della matrice tridiagonale
			matrix = inizializza_matrice(n, matrix, 't');

			//creo il vettore b con tutti 0 per evitare errori nei calcoli e il vettore x con 1 come da richiesta
			crea_vettori(n, x, b);

			/*//stampa della matrice tridiagonale
			stampa_matrice(matrix, n);*/
			cout << "Poiche' la matrice ha dimensione " << n << "X" << n << " non la stampo a video." << endl;
			
			//calcolo termine noto della matrice tridiagonale
			calcola_termine_noto(matrix, x, b, n);

			//stampa del termine noto della matrice tridiagonale
			cout << "\nIl termine noto della matrice tridiagonale e':" << endl
				 << "\t" << b[0] << "\n\t" << b[1] << "\n\n\t.\n\t.\t" << n-2 << " zeri\n\t.\n\n\t" << b[n-2] << "\n\t" << b[n-1] << "\n";
			
			//eliminazione Gaussiana sulla matrice tridiagonale
			eliminazione_gaussiana(matrix, b, n);
			
			//eliminazione Gaussiana all'indietro sulla matrice tridiagonale
			if (!eliminazione_gaussiana_indietro(matrix, b, n)) {
				cout << "\n**************** Matrice tridiagonale non risolvibile! ---> ci sono inf^n soluzioni ****************" << endl;
				return 0;
			}

			/*//stampa della matrice tridiagonale ridotta (eliminazione Gaussiana)
			cout << "\nLa Matrice tridiagonale ridotta e':" << endl;			
			stampa_matrice_ridotta(matrix, b, n);*/
			
			//libero la memoria per non sprecare spazio
			libera_memoria(matrix, x, b, n);
			cout << endl;

			break;
		}
		case 0:
			break;
		default:
			return -1;
	}

	return 0;
}
