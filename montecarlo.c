/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex4
 * montecarlo.c
 * <Type your name here>
 * <Type your discussion group here>
 * <Fill in a description of this program>
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// Given function prototype must not be changed
long throwDarts(long);

int main(void) {
	long darts_total,   // number of darts to be thrown
	    darts_inside;  // number of darts inside quadrant
	srand(time(NULL));
	//printf("%d\n", RAND_MAX);
	printf("How many darts? ");
	scanf("%ld", &darts_total);
	darts_inside=throwDarts(darts_total);
	printf ("Darts landed inside unit circle's quadrant = %ld\n", darts_inside);
	float pi = ((float)darts_inside/darts_total)*4;
	printf("Approximated pi = %f\n", pi);
	return 0;
}

long throwDarts (long darts_total){
	long lieInside=0;
	for (int i = 0; i < darts_total; i++)
	{
		//generate random dart
		double x= (double)rand()/RAND_MAX;
		//printf("%f\n", x);
		double y= (double)rand()/RAND_MAX;
		//printf("%f\n", y);
		//if dart lies in area of circle
		double point = pow(x,2)+pow(y,2);
		if (point<=(1.0)){
			lieInside++;
		}
	}
	return lieInside;
}
