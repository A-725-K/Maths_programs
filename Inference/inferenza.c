#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NRMAXTAXI 10000

#define POOLDIM 100
#define SAMPLE 1000

#define TRUE 1
#define FALSE 0
#define bool int

//This function counts how many times NRMAXTAXI is in the calulated range 
void isInRange(float low, float up, int *counter, float value) {
	if (low < value && up > value)
		(*counter)++;
}

int main() {
	int estimatedRange[SAMPLE][3];	//in this array there will be [NR of taxi seen][lower bound][upper bound] for each test

	int taxiSeen;	//a pseudo-casual value that represents the taxi seen
	int lowerBound;	//lower bound of the confidence range
	int upperBound;	//upper bound of the confidence range

	double alfa = 0.05;	//standard value for alfa
	double sigma = sqrt(pow(NRMAXTAXI, 2)/12);	//square root of variance
	double k = 1.96;		//constant
	double confidence = 1 - alfa;	//confidence of 95%
	double significativity_part2 = 0;	//significativity of the result in the asymptotic case
	int average = 0;	//average number of taxis
	double normNeg = 0, normPos = 0;	//normalized values of the range in the asymptotic case

	int i = 0,  j = 0;	//cycles' indexes 
	int counter = 0, counter2 = 0; //how many times NRMAXTAXI appears in the calculated range

	double x1 = 0, x2 = 0;	
	
	bool flag = FALSE;	//flag used to distinguish the two exercises
	
	srand(time(NULL));	//start generating pseudo-casual numbers

	for(; j < SAMPLE; j++) {
		for (i = 0;( i < POOLDIM && flag) || (i < SAMPLE && !flag); i++) {
			taxiSeen = (rand() % NRMAXTAXI) + 1;	//pick a number

//printf("%d)\tI've seen taxi nr --->\t%d...\n", i + 1, taxiSeen);
		
			estimatedRange[i][0] = taxiSeen;	//storing the number of the taxi (X)
	
			lowerBound = taxiSeen/(1 - alfa/2);	//calculating the lower bound
			upperBound = taxiSeen/(alfa/2);		//calculating the upper bound

			estimatedRange[i][1] = lowerBound;	//storing the lower bound
			estimatedRange[i][2] = upperBound;	//storing the upper bound

			isInRange(lowerBound, upperBound, &counter, NRMAXTAXI);	//decide if NRMAXTAXI is in the estimated range
		}
		
		if (!flag) {
			printf("***********************\n***** ONE  SAMPLE *****\n***********************\n");
			printf("\nThe correct number of taxis was in the range %d times with a confidence of %.2f in %d sample.\n\n\n", counter, confidence, SAMPLE);
			flag = TRUE;

			/*print the result obtained from the last computation formatted in the following way:
			NR TAXI			[MIN, MAX]*/
				/*printf("TaxiSeen\t\tRange\n\n");
				for(i = 0; i < POOLDIM; i++) {
					printf("%d\t\t\t[%d, %d]\n", estimatedRange[i][0], estimatedRange[i][1], estimatedRange[i][2]);
				}*/

			
		}

		//calculating the average
		for (i = 0; i < POOLDIM; i++) {
			average += estimatedRange[i][0];
		}
		average /= POOLDIM; 

//print the empiric average (Xn*)		
//printf("\nAverage: %d\n", average*2);

		//normalization of the range
		normPos = ((k*sigma/sqrt(POOLDIM)));
		normNeg = ((-k*sigma/sqrt(POOLDIM)));

//printf("NORMPOS: %.3f\tNORMNEG: %.3f\n",normPos,normNeg);

		isInRange(normNeg, normPos, &counter2,average-NRMAXTAXI/2);	//estabilish if the estimation is in the calculated range

		x1 = (normPos-average)/sigma;
		x2 = (normNeg-average)/sigma;

significativity_part2 = (0.5 + 0.5*erff(x1/sqrt(2)) - (0.5 + 0.5*erff(x2/sqrt(2))));	//this formula has some problems :-)
//printf("Maybe the correct nr of taxis is %d, with a confidence of %.2f\n", average * 2, significativity_part2);

//print out the result
printf("--- Range: [%d, %d], Confidence = %.2f\n",(int)(average-k*sigma/sqrt(POOLDIM)),(int)(average+k*sigma/sqrt(POOLDIM)), significativity_part2);
	
		//resetting the values in the variables for the next cycle
		average = normPos = normNeg = significativity_part2 = 0;
	}

	//print	the number of correct estimations of the NRMAXTAXI
	printf("***********************\n*** ASYMPTOTIC CASE ***\n***********************\n");
	printf("\nThe correct number of taxis was in the range %d times observing sample of %d taxis for %d times.\n",counter2, POOLDIM, SAMPLE);
	return 0;
}
