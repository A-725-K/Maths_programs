#include "linear_eq_2_vars.h"

//calculate the homogeneous equation
void homogeneous_equation(int x, int y, int gcd, int& s1, int& s2) {
	x /= gcd;
	y /= gcd;

	s1 = -y;
	s2 = x;
}

//calculate the greatest common divisor between two numbers (GCD)
int greatest_common_divisor(int a, int b) {
	int q = a/b;
	int r = 1;
	int gcd;

	if (b == 0)
		return a;

	if (a == 0)
		return b;

	if (a % b == 0)
		return a/(a/b);

	while (r != 0) {
		gcd = r;		
		q = a/b;
		r = a - b*q;
		a = b;
		b = r;
	}

	return gcd;
}

//calculate the bezout identity
void bezout_identity(int x, int y, int& s1, int& s2) {
	extended_euclidean_algo a;
	extended_euclidean_algo b;
	extended_euclidean_algo sol;
	int r = 0;
	int q = 0;

	a.s = 1;
	a.t = 0;

	b.s = 0;
	b.t = 1;

	while (r != greatest_common_divisor(x, y)) {
		q = x/y;

		sol.s = a.s - q*b.s;
		sol.t = a.t - q*b.t;
		
		s1 = sol.s;
		s2 = sol.t;

		r = x - y*q;
		x = y;
		y = r;

		a.s = b.s;
		a.t = b.t;

		b.s = sol.s;
		b.t = sol.t;

	}
}

//calculate the first singular solution of the equation
void singular_solution(int& s1, int& s2, int gcd, int known_term) {
	int cost = known_term/gcd;
	
	s1 *= cost;
	s2 *= cost;
}
