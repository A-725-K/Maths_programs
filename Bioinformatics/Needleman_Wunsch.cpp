#include <iostream>
#include <cstdlib>
#include <cstring>

#define LEN_A 10
#define LEN_B 10

#define D -1

void printNW(int *nw) {
	for (int i=0; i<LEN_A+1; i++) {
		for (int j=0; j<LEN_B+1; j++)
			std::cout << nw[i*(LEN_A+1) + j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void initializeNW(int *nw) {
	memset(nw, 0, (LEN_A+1) * (LEN_B+1));

	for (int i=0; i<LEN_A+1; i++)
		nw[i*(LEN_A+1) + 0] = D*i;
	for (int i=0; i<LEN_B+1; i++)
		nw[i] = D*i;
}

int alignSequences(int *nw, char *A, char *B) {
	for (int i=1; i<=LEN_A; i++)
		for (int j=1; j<=LEN_B; j++) {
			int s = (A[i-1] == B[j-1]) ? 1 : -1;

			int match = nw[(i-1)*(LEN_A+1) + (j-1)] + s;
			int del = nw[(i-1)*(LEN_A+1) + j] + D;
			int insert = nw[i*(LEN_A+1) + (j-1)] + D;

			nw[i*(LEN_A+1) + j] += std::max(std::max(match, del), insert);
		}
	
	return nw[(LEN_A+1)*(LEN_B+1) - 1];
}

char convert(int n) {
	switch(n) {
		case 0:
			return 'A';
		case 1:
			return 'C';
		case 2:
			return 'T';
		case 3:
			return 'G';
		default:
			return '-';	// error
	}
}

int main (int argc, char **argv) {
	srand(42);
	int *nw = new int[(LEN_A+1) * (LEN_B+1)];

	char *seqA = new char[LEN_A+1];
	char *seqB = new char[LEN_B+1];

	for (int i=0; i<LEN_A; i++)
		seqA[i] = convert(rand() % 4);
	for (int i=0; i<LEN_B; i++)
		seqB[i] = convert(rand() % 4);
	seqA[LEN_A] = 0;
	seqB[LEN_B] = 0;
	
	std::cout << "A = " << seqA << std::endl << "B = " << seqB << std::endl << std::endl;

	initializeNW(nw);
	printNW(nw);
	/*std::cout << */alignSequences(nw, seqA, seqB)/* << std::endl*/;
	printNW(nw);
	
	delete[] seqA;
	delete[] seqB;
	delete[] nw;

	return 0;
}
