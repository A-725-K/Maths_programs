#include <iostream>
#include <math.h>

using namespace std;

int main() {
	//matricola = 4086006
	int d0 = 6, d1 = 0;
	double a, b, c;
	b = (0 + 1) * pow(10, 20);	//b = (d1 + 1) · 10^20
	c = -b;
	
	for (int i = 0; i <= 6; i++) {
		a = (6 + 1) * pow(10, i);	//a = (d0 + 1) · 10^i con i=1,...,6
		cout << "Per i = " << i << ":" << endl;
		cout << "(a + b) + c = " << (a + b) + c << endl;		//la cancellazione avviene dopo
		cout << "a + (b + c) = " << a + (b + c) << endl << endl;	//la cancellazione avviene prima
	}
		
	return 0;
}
