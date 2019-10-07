/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex2
 * square_free.c
 * Zhou Shikai
 * T02
 * Discription: Given 2 ranges calculate which range has more
	*square-free numbers
 */

#include <stdio.h>
#include <math.h> // optional, please remove if you are not using it

int squarefree (int ,int);

int main(void) {
	int lower1, upper1, lower2, upper2, range1, range2;

	printf("Enter four positive integers: ");
	scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);

	range1=squarefree(lower1, upper1);
	range2=squarefree(lower2, upper2);

	if (range1 == range2) {
		//if both ranges have the same no. of square free numbers
		printf("Both ranges have the same number of square-free numbers: %d\n"
		,range1);
	}
	else if (range1 > range2) {
		//if both range1 have more square free numbers
		printf("Range [%d, %d] has more square-free numbers: %d\n"
		,lower1, upper1, range1);
	}else	{
		//if both range2 have more square free numbers
		printf("Range [%d, %d] has more square-free numbers: %d\n"
		,lower2, upper2, range2);
}

	return 0;
}

// Count the number of square free integers in the range [lower, upper]
int squarefree (int lower, int upper){
	int isSquareFree = 0, i, j, jsquared;
	//loop the integers in range [lower, upper]
	for (i = lower; i <= upper; i++) {
		//check if the integer i is a squarefree number
		//special case: 1
		if (i == 1) {
			isSquareFree++;
		//for 2 onwards
		}else{
			for (j = 2; j <= i; j++) {

				jsquared = j*j;

				//case 1: integer is a mulitiple of a square number
				if(i%jsquared == 0){
					break;
				//case 2: integer is square free
				}else if(j == i){
					isSquareFree++;
				}
			}
		}
	}
	return isSquareFree;
}
