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
int throwDarts(int);

int main(void) {
	int darts_total,   // number of darts to be thrown
	    darts_inside;  // number of darts inside quadrant

	//printf("%d\n", RAND_MAX);
	printf("How many darts? ");
	scanf("%d", &darts_total);
	darts_inside=throwDarts(darts_total);
	printf ("Darts landed inside unit circle's quadrant = %d\n", darts_inside);
	float pi = ((float)darts_inside/darts_total)*4;
	printf("Approximated pi = %f\n", pi);
	return 0;
}

int throwDarts (int darts_total){
	srand(time(0));
	int lieInside=0;
	for (int i = 0; i < darts_total; i++)
	{
		float x= (float)rand()/RAND_MAX;
		//printf("%f\n", x);
		float y= (float)rand()/RAND_MAX;
		//printf("%f\n", y);
		//generate random dart
		float point = pow(x,2)+pow(y,2);
		if (point<=(1.0)){
			lieInside++;
		}
	}
	return lieInside;
}
