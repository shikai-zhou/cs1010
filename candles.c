/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex1
 * candles.c
 * Calculate the total number of candles burnt given initial number
 * of candles, and no. of residual to make a new candle
 * Zhou Shikai
 * T02
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
// This program will calculate the total number of candles burnt
// Precondition: no. of residual to make new candle > 1
int calculate (int candles, int residual){
	int remainder, burnt = 0;// burnt: candles burnt , remainder: left over candles
	
	while(candles/residual != 0){
		remainder = candles%residual;	
		burnt += candles-(remainder);//add the candles burnt to total
		candles = remainder+candles/residual;
		//assign the new candles made from residual and remaining candles 
		//for a new round of burning
		
	}
	return burnt + (candles%residual);	
}
