#include <iostream>
#include <cmath>

#define N 5

using namespace std;

//Calcola il fattoriale del parametro n
double fattoriale(int n) {
	double fact = 1;
	
	for (int i = 1; i <= n; i++)
		fact *= i;
		
	return fact;
}

int main() {
	int indexN[N] = {3, 10, 50, 100, 150};	//#Valori in input
	double x1 = 0.5, x2 = 30, taylor1 = 0, taylor2 = 0, taylor3 = 0, taylor4 = 0;
	
	cout << endl << "Valori di e^x calcolati con la funzione exp di cmath:" << endl << endl;
	
	cout << "\tx = " << x1 << "\t\te^x = " << exp(x1) << endl;			//Valore corretto (a meno della precisione di macchina) della funzione
	cout << "\tx = " << x2 << "\t\te^x = " << exp(x2) << endl << endl;	//e^x che si trova in cmath

	cout << "\tx = " << -x1 << "\te^x = " << exp(-x1) << endl;
	cout << "\tx = " << -x2 << "\t\te^x = " << exp(-x2) << endl << endl;
	cout << "_____________________________________________________________________________\n\n\n";

	cout << "Per calcolare errore relativo ed errore assoluto nel seguito utilizzeremo le seguenti formule:" << endl;
	cout << "\t€[ass] = fn(x) - f(x)\n\t€[rel] = |fn(x) - f(x)|/f(x)" << endl<< endl;	//In seguito utilizzeremo la funzione abs contenuta in cmath

	cout << "_____________________________________________________________________________\n\n\n";

	for (int i = 0; i < N; i++) {
		cout << "Per N = " << indexN[i] << ":" << endl << endl << endl;	//#Input

		cout << "---Algoritmo 1:" << endl << endl;	//Sviluppo della serie di Taylor
		
		for (int j = 0; j < indexN[i]; j++) {	//Calcolo
			taylor1 += pow(x1, j)/fattoriale(j);	
			taylor2 += pow(x2, j)/fattoriale(j);
			taylor3 += pow(-x1, j)/fattoriale(j);
			taylor4 += pow(-x2, j)/fattoriale(j);
		}
		
		//x = 0.5
		cout << "\t>> x = " << x1 << "\t\tfn(x) ~= " << taylor1 << "\t\tf(x) = " << exp(x1) << endl;
		cout << "\n\t\t€[ass] = " << taylor1 - exp(x1) << "\n\t\t€[rel] = " << fabs(taylor1 - exp(x1))/exp(x1) << endl << endl;

		//x = 30.0
		cout << "\t>> x = " << x2 << "\t\tfn(x) ~= " << taylor2 << "\t\tf(x) = " << exp(x2) << endl;
		cout << "\n\t\t€[ass] = " << taylor2 - exp(x2) << "\n\t\t€[rel] = " << fabs(taylor2 - exp(x2))/exp(x2) << endl << endl;

		//x = -0.5
		cout << "\t>> x = " << -x1 << "\t\tfn(x) ~= " << taylor3 << "\t\tf(x) = " << exp(-x1) << endl;
		cout << "\n\t\t€[ass] = " << taylor3 - exp(-x1) << "\n\t\t€[rel] = " << fabs(taylor3 - exp(-x1))/exp(-x1) << endl << endl;

		//x = -30.0
		cout << "\t>> x = " << -x2 << "\t\tfn(x) ~= " << taylor4 << "\t\tf(x) = " << exp(-x2) << endl;	
		cout << "\n\t\t€[ass] = " << taylor4 - exp(-x2) << "\n\t\t€[rel] = " << fabs(taylor4 - exp(-x2))/exp(-x2) << endl << endl;

		cout << "---Algoritmo 2:" << endl << endl;	//Reciproco della serie di Taylor
		
		//x = -0.5
		cout << "\t>> x = " << -x1 << "\t\tfn(x) ~= " << 1/taylor1 << "\t\tf(x) = " << exp(-x1) << endl;
		cout << "\n\t\t€[ass] = " << 1/taylor1 - exp(-x1) << "\n\t\t€[rel] = " << fabs(1/taylor1 - exp(-x1))/exp(-x1) << endl << endl;

		//x= -30.0
		cout << "\t>> x = " << -x2 << "\t\tfn(x) ~= " << 1/taylor2 << "\t\tf(x) = " << exp(-x2) << endl;		
		cout << "\n\t\t€[ass] = " << 1/taylor2 - exp(-x2) << "\n\t\t€[rel] = " << fabs(1/taylor2 - exp(-x2))/exp(-x2) << endl << endl;

		if (i < N - 1) {	//Controllo per non stamparlo in fondo all'esecuzione del programma
			cout << "_____________________________________________________________________________\n";
			cout << "_____________________________________________________________________________\n\n\n";
		}

		taylor1 = taylor2 = taylor3 = taylor4 = 0;	//A ogni ciclo devo ricordarmi di azzerare le variabili
	}
	
	return 0;
}
