#include <stdio.h>

int compute_percentile(int,int,int);
float compute_iqscore(int,int);
int main (void){
	int verbal, math ,writing;
	printf("Enter scores:");
	scanf("%d %d %d", &verbal, &math, & writing);
	int percentile = compute_percentile(verbal,math,writing);
	printf("The SAT score is in the %d percentile.\n", percentile);
	float iq=compute_iqscore(verbal,math);
	printf("The IQ score is %.2f\n", iq);
	if((verbal>600&&math>600&&writing>600)||iq>=120.0){
	printf("Wow, this is amazing!\n");
	}
	return 0;
}

int compute_percentile (int verbal, int math, int writing){
	int percentile, total=verbal+math+writing;
	if (total>=2200){
		percentile = 99;
	}
	else if (total>=2000){
		percentile =95;
	}
	else if(total >=1500){
		percentile =50;
	}
	else{
	percentile =10;
	}
	return percentile;
}

float compute_iqscore(int verbal, int math){
	float iq;
	iq=(math*0.095)+(verbal*0.003)+50.241;
	return iq;
}
