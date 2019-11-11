/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex3
 * bisection.c
 * Zhou Shikai
 * T02
 * Bisection Method:Calculate the root of a polynomial equation,
 * given 2 points on a,b on either side of the root, where a,b are not both
 * positive or both negative
 */

#include <stdio.h>
#include <math.h>

// Given function prototype must not be changed
double polynomial(double, int, int, int, int);
double root (double, double, int, int, int, int);
int positive (double);

int main(void){
	int    c3, c2, c1, c0; // coefficients of polynomial
	double a, b;           // endpoints

	double m, pM;          // midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);

	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a, &b);

	m = root(a,b,c3,c2,c1,c0);

	printf("root = %f\n", m);

	pM = polynomial(m,c3,c2,c1,c0);

	printf("p(root) = %f\n", pM);

	return 0;
}
//calulate the function value, given coefficients and point
double polynomial (double x, int c3, int c2, int c1, int c0){
	double p_value = c3*(pow(x,3))+c2*(pow(x,2))+c1*(x)+c0;
	return p_value;
}
//calulate root of equation using bisection method
//Precondition: Root is not a maximum or minimum point
double root (double a, double b, int c3, int c2, int c1, int c0){
	double midpoint, midpoint_value, a_value, b_value, difffence;

	do{
		midpoint = (a+b)/2.0;
		midpoint_value = polynomial(midpoint,c3,c2,c1,c0);
		a_value = polynomial(a,c3,c2,c1,c0);
		b_value = polynomial(b,c3,c2,c1,c0);
		difffence = fabs(a-b);
		//if midpoint is root
		if (midpoint_value == 0.0){
			break;
		}
		//replace the point with positive value if value of midpoint is positive
		//and the point with negative value if value of midpoint is negative
		else if (positive(midpoint_value) == positive(a_value)){
			a = midpoint;
		}
		else if (positive(midpoint_value) == positive(b_value)){
			b = midpoint;
		}
	}while (difffence > 0.0001);
	return midpoint;
}
//check if value is positive
int positive (double value){
	if(value>0.0){
		return 1;
	}else{
		return 0;
	}
}
