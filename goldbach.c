#include <stdio.h>

int prime(int number){
	int i, flag=1;
	for(i=2;i<number;i++){
		if (number%i==0){
			flag=0;
		}
	}
		return flag;
	}
	int sumprimes(int number){
		int i, j, sum =0;
		for(i=2;i<number;i++){
			if(prime(i)==1){
				for(j=2;j<number;j++){
					if(prime(j)==1&&(i+j)==number){
						sum++;
					}
				} 
			}
		}
		return sum;
	}
	int main (void)	{
		int num, sum;
		printf("Enter an even number:");
		scanf("%d", &num);
		sum=sumprimes(num);
		printf("The number of sums is %d\n", sum);
		return 0;
	}
