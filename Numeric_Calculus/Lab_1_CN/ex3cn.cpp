#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float d0 = 0.0, sum0;
	double d1 = 0.0, sum1;
	
	sum0 = (float)1 + powf((float)2, -d0);
	while(sum0 > 1) {	//cicla fino a che non trova il corretto valore di d0 (float)
		d0++;
		sum0 = (float)1 + powf((float)2, -d0);
	}
	
	sum1 = (double)1 + pow((double)2, -d1);
	while(sum1 > 1) {	//cicla fino a che non trova il corretto valore di d1 (double)
		d1++;
		sum1 = (double)1 + pow((double)2, -d1);
	}
	
	d0--;	//dato che esce dal while incrementato di 1 di troppo lo decremento di 1
	d1--;	//dato che esce dal while incrementato di 1 di troppo lo decremento di 1	

	cout << "Il valore di d0 e' " << d0 << endl << endl;
	cout << "Il valore di d1 e' " << d1 << endl << endl;
	
	//eps = 2^−d
	float eps_int = powf((float)2, -d0);		//singola precisione
	double eps_double = pow((double)2, -d1);	//doppia precisione
	
	cout << "______________________________________________________________________________" << endl << endl;
	cout << "La precisione di macchina calcolata in singola precisione vale eps = " << eps_int << endl;
	cout << "La precisione di macchina calcolata in doppia precisione vale eps = " << eps_double << endl;
	cout << "______________________________________________________________________________" << endl << endl;

	return 0;
}
