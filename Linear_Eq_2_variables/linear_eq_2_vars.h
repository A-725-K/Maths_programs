#include <iostream>

using namespace std;

//data strcture to compute the extended euclideam algorithm
struct extended_euclidean_algo {
	int s;
	int t;
};

// --- FUNCTIONS --- 
void homogeneous_equation(int, int, int, int&, int&);
int greatest_common_divisor(int, int);
void bezout_identity(int, int, int&, int&);
void singular_solution(int&, int&, int, int);
