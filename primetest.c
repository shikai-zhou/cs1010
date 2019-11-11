#include <stdio.h>

int prime (int num){
	int flag=1, i;
	if (num == 1){
		flag = 0;
	}else{
		for(i=2; i<num; i++){
			if (num%i == 0){
				flag = 0;
				break;
			}else if(num == i){
				flag = 1;
			}
		}
	}
	return flag;
}

int main (void){
	int testnum, flag;
	printf("Enter a positive integer: ");
	scanf("%d", &testnum);
	flag = prime(testnum);
	if(flag == 1){
		printf("%d is a prime.\n", testnum);	
	}else{
		printf("%d is not a prime.\n", testnum);
	}
	return 0;
}
