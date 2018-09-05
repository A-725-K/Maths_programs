#include "funzioni_matrici.h"

int main() {
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

			float **matrix;	//matrice di partenza
			float *b, *x, *db, *term_noto_pert, *xt, norma;	//termine noto, vettore delle soluzioni, vettore di perturbazione, termine noto perturbato, soluzione perturbata e norma del termine noto
			int dim;			
	
			cout << "\nInserire le dimensioni della matrice:\n---> n = ";
			cin >> dim;

			//controllo sull'input dell'utente
			while(!cin || dim < 0) {
				cout << "Dimensione non accettabile. Re-inserire il valore >> ";
				cin >> dim;
			}

			//creazione vettore termine noto perturbato e x tilde
			crea_vettori(dim, term_noto_pert, xt);

			//creazione della matrice da parte dell'utente
			matrix = inizializza_matrice(dim, matrix, 'i');

			//stampa della matrice inserita dall'utente
			cout << "La matrice che hai inserito e':" << endl;
			stampa_matrice(matrix, dim);			

			//creo il vettore b con tutti 0 per evitare errori nei calcoli e il vettore x con 1 come da richiesta
			crea_vettori(dim, x, b);

			//calcolo del termine noto
			calcola_termine_noto(matrix, x, b, dim);		

			//stampa del termine noto
			cout << "\nIl termine noto e':" << endl;
			stampa_vettore(b, dim);	

			//calcolo la norma del vettore b e la stampo
			norma = norma_inf_vettore(dim, b);
			cout << "\nLa norma del vettore b:\n\t|| b || = " << norma << endl;	

			//inizializza il vettore perturbazione e lo stampo
			crea_vettore_perturbazione(dim, db, norma);		
			cout << "\nIl vettore perturbazione e':" << endl;
			stampa_vettore(db, dim);	

			//ottengo il termine noto perturbato
			somma_vettori(dim, b, db, term_noto_pert);

			//stampa del termine noto perturbato
			cout << "\nIl termine noto perturbato e':" << endl;
			stampa_vettore(term_noto_pert, dim);	

			//eliminazione Gaussiana
			eliminazione_gaussiana(matrix, term_noto_pert, dim);

			//eliminazione Gaussiana all'indietro
			if (!eliminazione_gaussiana_indietro(matrix, term_noto_pert, dim)) {
				cout << "\n**************** Matrice non risolvibile! ---> ci sono inf^n soluzioni ****************" << endl;
				return 0;
			}

			//stampa della matrice ridotta (eliminazione Gaussiana)
			cout << "\nLa matrice ridotta e':" << endl;
			stampa_matrice_ridotta(matrix, term_noto_pert, dim);

			//calcolo soluzione xt
			calcolo_x_tilde(dim, matrix, term_noto_pert, xt);

			//stampa della soluzione x tilde
			cout << "\nLa soluzione perturbata del sistema e':" << endl;
			stampa_vettore(xt, dim);	

			//calcolo e stampo l'errore sulla soluzione
			cout << "\nErrore sulla soluzione del sistema:" << endl;
			sottrai_vettori(dim, x, xt, term_noto_pert);	
			stampa_vettore(term_noto_pert, dim);

			//libero la memoria per non sprecare spazio
			libera_memoria(matrix, x, b, dim);
			delete [] db;
			db = NULL;
			delete [] xt;
			xt = NULL;
			delete [] term_noto_pert;
			term_noto_pert = NULL;
			
			break;
		}
		case 2:
		{	
			int d0 = 8, d1 = 4;
			int n = (d1 + 1)*10 + d0;
	
			float ** matrix;	//matrice dinamica			
			float *b, *x, *db, *term_noto_pert, *xt, norma;	//termine noto, vettore delle soluzioni, vettore di perturbazione, termine noto perturbato, soluzione perturbata e norma del termine noto

			cout << "_____________________________________________________________________________\n\n";

/*---------------------------------------------------- MATRICE A -----------------------------------------------------------*/

			//creazione vettore termine noto perturbato e x tilde
			crea_vettori(M, term_noto_pert, xt);

			//creazione della matrice A
			matrix = inizializza_matrice(M, matrix, 'a');

			//stampa della matrice A
			cout << "Matrice A :" << endl;
			stampa_matrice(matrix, M);		

			//creo il vettore b con tutti 0 per evitare errori nei calcoli e il vettore x con 1 come da richiesta
			crea_vettori(M, x, b);

			//calcolo del termine noto
			calcola_termine_noto(matrix, x, b, M);		

			//stampa del termine noto
			cout << "\nIl termine noto e':" << endl;
			stampa_vettore(b, M);	

			//calcolo la norma del vettore b e la stampo
			norma = norma_inf_vettore(M, b);
			cout << "\nLa norma del vettore b:\n\t|| b || = " << norma << endl;		

			//inizializza il vettore perturbazione e lo stampo
			crea_vettore_perturbazione(M, db, norma);		
			cout << "\nIl vettore perturbazione e':" << endl;
			stampa_vettore(db, M);	

			//ottengo il termine noto perturbato
			somma_vettori(M, b, db, term_noto_pert);

			//stampa del termine noto perturbato
			cout << "\nIl termine noto perturbato e':" << endl;
			stampa_vettore(term_noto_pert, M);	

			//eliminazione Gaussiana
			eliminazione_gaussiana(matrix, term_noto_pert, M);

			//eliminazione Gaussiana all'indietro
			if (!eliminazione_gaussiana_indietro(matrix, term_noto_pert, M)) {
				cout << "\n**************** Matrice non risolvibile! ---> ci sono inf^n soluzioni ****************" << endl;
				return 0;
			}

			//stampa della matrice ridotta (eliminazione Gaussiana)
			cout << "\nLa matrice ridotta e':" << endl;
			stampa_matrice_ridotta(matrix, term_noto_pert, M);

			//calcolo soluzione xt
			calcolo_x_tilde(M, matrix, term_noto_pert, xt);

			//stampa della soluzione x tilde
			cout << "\nLa soluzione perturbata del sistema e':" << endl;
			stampa_vettore(xt, M);	

			//calcolo e stampo l'errore sulla soluzione
			cout << "\nErrore sulla soluzione del sistema:" << endl;
			sottrai_vettori(M, x, xt, term_noto_pert);	
			stampa_vettore(term_noto_pert, M);

			//libero la memoria per non sprecare spazio
			libera_memoria(matrix, x, b, M);
			delete [] db;
			db = NULL;
			delete [] xt;
			xt = NULL;
			delete [] term_noto_pert;
			term_noto_pert = NULL;
			cout << endl;
			cout << "_____________________________________________________________________________\n\n";

/*---------------------------------------------------- MATRICE B -----------------------------------------------------------*/

			//creazione vettore termine noto perturbato e x tilde
			crea_vettori(M, term_noto_pert, xt);

			//creazione della matrice B
			matrix = inizializza_matrice(M, matrix, 'b');

			//stampa della matrice B
			cout << "Matrice B :" << endl;
			stampa_matrice(matrix, M);		

			//creo il vettore b con tutti 0 per evitare errori nei calcoli e il vettore x con 1 come da richiesta
			crea_vettori(M, x, b);

			//calcolo del termine noto
			calcola_termine_noto(matrix, x, b, M);		

			//stampa del termine noto
			cout << "\nIl termine noto e':" << endl;
			stampa_vettore(b, M);	

			//calcolo la norma del vettore b e la stampo
			norma = norma_inf_vettore(M, b);
			cout << "\nLa norma del vettore b:\n\t|| b || = " << norma << endl;		

			//inizializza il vettore perturbazione e lo stampo
			crea_vettore_perturbazione(M, db, norma);		
			cout << "\nIl vettore perturbazione e':" << endl;
			stampa_vettore(db, M);	

			//ottengo il termine noto perturbato
			somma_vettori(M, b, db, term_noto_pert);

			//stampa del termine noto perturbato
			cout << "\nIl termine noto perturbato e':" << endl;
			stampa_vettore(term_noto_pert, M);	

			//eliminazione Gaussiana
			eliminazione_gaussiana(matrix, term_noto_pert, M);

			//eliminazione Gaussiana all'indietro
			if (!eliminazione_gaussiana_indietro(matrix, term_noto_pert, M)) {
				cout << "\n**************** Matrice non risolvibile! ---> ci sono inf^n soluzioni ****************" << endl;
				return 0;
			}

			//stampa della matrice ridotta (eliminazione Gaussiana)
			cout << "\nLa matrice ridotta e':" << endl;
			stampa_matrice_ridotta(matrix, term_noto_pert, M);

			//calcolo soluzione xt
			calcolo_x_tilde(M, matrix, term_noto_pert, xt);

			//stampa della soluzione x tilde
			cout << "\nLa soluzione perturbata del sistema e':" << endl;
			stampa_vettore(xt, M);	

			//calcolo e stampo l'errore sulla soluzione
			cout << "\nErrore sulla soluzione del sistema:" << endl;
			sottrai_vettori(M, x, xt, term_noto_pert);	
			stampa_vettore(term_noto_pert, M);

			//libero la memoria per non sprecare spazio
			libera_memoria(matrix, x, b, M);
			delete [] db;
			db = NULL;
			delete [] xt;
			xt = NULL;
			delete [] term_noto_pert;
			term_noto_pert = NULL;
			cout << endl;
			cout << "_____________________________________________________________________________\n\n";

/*------------------------------------------------ MATRICE DI PASCAL -----------------------------------------------------------*/
			
			//creazione vettore termine noto perturbato e x tilde
			crea_vettori(N, term_noto_pert, xt);

			//creazione della matrice di Pascal
			matrix = inizializza_matrice(N, matrix, 'p');

			//stampa della matrice di Pascal
			cout << "Matrice di Pascal :" << endl;
			stampa_matrice(matrix, N);		

			//creo il vettore b con tutti 0 per evitare errori nei calcoli e il vettore x con 1 come da richiesta
			crea_vettori(N, x, b);

			//calcolo del termine noto
			calcola_termine_noto(matrix, x, b, N);		

			//stampa del termine noto
			cout << "\nIl termine noto e':" << endl;
			stampa_vettore(b, N);	

			//calcolo la norma del vettore b e la stampo
			norma = norma_inf_vettore(N, b);
			cout << "\nLa norma del vettore b:\n\t|| b || = " << norma << endl;		

			//inizializza il vettore perturbazione e lo stampo
			crea_vettore_perturbazione(N, db, norma);		
			cout << "\nIl vettore perturbazione e':" << endl;
			stampa_vettore(db, N);	

			//ottengo il termine noto perturbato
			somma_vettori(N, b, db, term_noto_pert);

			//stampa del termine noto perturbato
			cout << "\nIl termine noto perturbato e':" << endl;
			stampa_vettore(term_noto_pert, N);	

			//eliminazione Gaussiana
			eliminazione_gaussiana(matrix, term_noto_pert, N);		

			//eliminazione Gaussiana all'indietro
			if (!eliminazione_gaussiana_indietro(matrix, term_noto_pert, N)) {
				cout << "\n**************** Matrice non risolvibile! ---> ci sono inf^n soluzioni ****************" << endl;
				return 0;
			}

			//stampa della matrice ridotta (eliminazione Gaussiana)
			cout << "\nLa matrice ridotta e':" << endl;
			stampa_matrice_ridotta(matrix, term_noto_pert, N);

			//calcolo soluzione xt
			calcolo_x_tilde(N, matrix, term_noto_pert, xt);

			//stampa della soluzione x tilde
			cout << "\nLa soluzione perturbata del sistema e':" << endl;
			stampa_vettore(xt, N);	

			//calcolo e stampo l'errore sulla soluzione
			cout << "\nErrore sulla soluzione del sistema:" << endl;
			sottrai_vettori(N, x, xt, term_noto_pert);	
			stampa_vettore(term_noto_pert, N);

			//libero la memoria per non sprecare spazio
			libera_memoria(matrix, x, b, N);
			delete [] db;
			db = NULL;
			delete [] xt;
			xt = NULL;
			delete [] term_noto_pert;
			term_noto_pert = NULL;
			cout << endl;
			cout << "_____________________________________________________________________________\n\n";

/*------------------------------------------------ MATRICE TRIDIAGONALE -----------------------------------------------------------*/

			//creazione vettore termine noto perturbato e x tilde
			crea_vettori(n, term_noto_pert, xt);

			//creazione della matrice tridiagonale
			matrix = inizializza_matrice(n, matrix, 't');

			/*//stampa della matrice tridiagonale
			cout << "Matrice Tridiagonale :" << endl;
			stampa_matrice(matrix, n);*/

			//creo il vettore b con tutti 0 per evitare errori nei calcoli e il vettore x con 1 come da richiesta
			crea_vettori(n, x, b);

			//calcolo del termine noto
			calcola_termine_noto(matrix, x, b, n);		

			/*//stampa del termine noto
			cout << "\nIl termine noto e':" << endl;
			stampa_vettore(b, n);*/

			//stampa del termine noto della matrice tridiagonale
			cout << "\nIl termine noto della matrice tridiagonale e':" << endl
				 << "\t1\n\t0\n\n\t.\n\t.\t" << n-2 << " zeri\n\t.\n\n\t0\n\t1\n";

			//calcolo la norma del vettore b e la stampo
			norma = norma_inf_vettore(n, b);
			cout << "\nLa norma del vettore b:\n\t|| b || = " << norma << endl;		

			//inizializza il vettore perturbazione e lo stampo
			crea_vettore_perturbazione(n, db, norma);		
			cout << "\nIl vettore perturbazione e':" << endl;
			stampa_vettore(db, n);	

			//ottengo il termine noto perturbato
			somma_vettori(n, b, db, term_noto_pert);

			//stampa del termine noto perturbato
			cout << "\nIl termine noto perturbato e':" << endl;
			//stampa_vettore(term_noto_pert, n);	
			cout <<  term_noto_pert[0] << endl << term_noto_pert[1] << endl << term_noto_pert[2] << "\n\n.\n.\n.\n\n" << term_noto_pert[n-3] << endl << term_noto_pert[n-2] << endl << term_noto_pert[n-1] << endl;

			//eliminazione Gaussiana
			eliminazione_gaussiana(matrix, term_noto_pert, n);

			//eliminazione Gaussiana all'indietro
			if (!eliminazione_gaussiana_indietro(matrix, term_noto_pert, n)) {
				cout << "\n**************** Matrice non risolvibile! ---> ci sono inf^n soluzioni ****************" << endl;
				return 0;
			}

			/*//stampa della matrice ridotta (eliminazione Gaussiana)
			cout << "\nLa matrice ridotta e':" << endl;
			stampa_matrice_ridotta(matrix, term_noto_pert, n);*/

			//calcolo soluzione xt
			calcolo_x_tilde(n, matrix, term_noto_pert, xt);

			//stampa della soluzione x tilde
			cout << "\nLa soluzione perturbata del sistema e':" << endl;
			stampa_vettore(xt, n);

			//calcolo e stampo l'errore sulla soluzione
			cout << "\nErrore sulla soluzione del sistema:" << endl;
			sottrai_vettori(n, x, xt, term_noto_pert);	
			stampa_vettore(term_noto_pert, n);

			//libero la memoria per non sprecare spazio
			libera_memoria(matrix, x, b, n);
			delete [] db;
			db = NULL;
			delete [] xt;
			xt = NULL;
			delete [] term_noto_pert;
			term_noto_pert = NULL;
			cout << endl;
			cout << "_____________________________________________________________________________\n\n";

			break;
		}
		default:
			break;	
	}
	
	return 0;
}
