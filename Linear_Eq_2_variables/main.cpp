#include "linear_eq_2_vars.h"

int main (int argc, char **argv) {
	int x;
	int y;
	int c;
	int m;

	int hom_sol1 = 0;
	int hom_sol2 = 0;
	int sol1 = 0;
	int sol2 = 0;

	cout << "\nThis program solve linear equations in 2 variables." << endl;

	cout << "\n\nFirst of all, insert three integer numbers: " << endl;

	cin >> x;
	cin >> y;
	cin >> c;
	
	while (!cin || x < 0 || y < 0 || c < 0) {
		cout << "Error input." << endl;
		cin.clear();
		cin.ignore(10000000, '\n');
		cin >> x;
		cin >> y;
		cin >> c;
	}

	cout << "\n" << x << "X + " << y << "Y = " << c << endl;
	m = greatest_common_divisor(x, y);

	if (c%m != 0) {
		cout << "\nThe equation has no solution." << endl;
		return 0;
	}

	cout << "\nThe Greatest Common Divisor between X and Y is "<< m << "." << endl;

	cout << "\nComputing the Bezout Identity..." << endl;
	bezout_identity(x, y, sol1, sol2);
	cout << "\t(" << sol1 << ", " << sol2 << ")" << endl;

	cout << "\nComputing singular solution..." << endl;
	singular_solution(sol1, sol2, m, c);
	cout << "\t(" << sol1 << ", " << sol2 << ")" << endl;
	
	cout << "\nCalculating solutions of homogeneous equation..." << endl;
	homogeneous_equation(x, y, m, hom_sol1, hom_sol2);
	cout << "\t(" << hom_sol1 << "t, " << hom_sol2 << "t)\t t€Z" << endl;

	cout << "\nThe General solution of the given equation is:" << endl;
	if (hom_sol1 > 0 && hom_sol2 > 0)
		cout << "\t (x,y) = (" << sol1 << " + " << hom_sol1 << "t, " << sol2 << " + " << hom_sol2 << "t)    t€Z\n" << endl;
	else if (hom_sol1 > 0 && hom_sol2 < 0)
		cout << "\t (x,y) = (" << sol1 << " + " << hom_sol1 << "t, " << sol2 << " - " << -hom_sol2 << "t)    t€Z\n" << endl;
	else if (hom_sol1 < 0 && hom_sol2 > 0)
		cout << "\t (x,y) = (" << sol1 << " - " << -hom_sol1 << "t, " << sol2 << " + " << hom_sol2 << "t)    t€Z\n" << endl;
	else if (hom_sol1 < 0 && hom_sol2 < 0)
		cout << "\t (x,y) = (" << sol1 << " - " << -hom_sol1 << "t, " << sol2 << " - " << -hom_sol2 << "t)    t€Z\n" << endl;
	
	return 0;
}
