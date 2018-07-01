// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif
 
int main (int argc, char *argv[]){
	if (argc < 2) {
	fprintf(stdout,"%s Version %d.%d\n", argv[0],
			Tutorial_VERSION_MAJOR,
			Tutorial_VERSION_MINOR);
	fprintf(stdout,"Usage: %s number\n",argv[0]);
	return 1;
	}
	// get input from arguments
	double inputValue = atof(argv[1]);
	
	// compute output from sqrt/mysqrt function of input
	#ifdef USE_MYMATH
		double outputValue = mysqrt(inputValue);
	fprintf(stdout,"My square root of %g is %g\n", inputValue, outputValue);
	#else
		double outputValue = sqrt(inputValue);
	fprintf(stdout,"STD square root of %g is %g\n", inputValue, outputValue);
	#endif

	return 0;
}
