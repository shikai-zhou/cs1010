/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex1
 * candles.c
 * <Fill in a description of this program>
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>

// Write your function prototype below (and remove this comment!)
int calculate (int, int);
int main(void) {
	int candles, residual;

	printf("Enter number of candles and \n");
	
	printf("number of residuals to make a new candle: ");

	scanf("%d %d", &candles, &residual);
	int result=calculate(candles, residual);

	printf("Total candles burnt = %d\n", result);

	return 0;
}

// Add your function below (and remove this comment!)
// Every function should be preceded with a comment
// that describes what the function does.
// Precondition: no. of residual to make new candle != 0
int calculate (int candles, int residual){
	int remainder, burnt=0;// burnt: candles burnt , remainder: left over candles
	remainder = candles%residual);
	while(candles/residual!=0){	
		burnt += candles-(remainder);
		candles = remainder+candles/residual;//assign the new candles made from residual and remaining candles for a new round of burning
		calculate(candles,residual);// recursive burning of candles
	}
	return burnt + (candles%residual);	
}