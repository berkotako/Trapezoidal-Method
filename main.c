#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float trapez(float x,float h,int up,int us,int A[100]);
float fonk_calc(int us,float x_0,int A[100]);
int main(int argc, char *argv[]) {
	int up_val,down_val,power,division,i;
	int coef[100]={0};
	int *coef_p = &coef;
	float func_val;
	
	printf("Please enter the up_val ");
	scanf("%d",&up_val);
	printf("\nPlease enter the down_val ");
	scanf("%d",&down_val);
	printf("\nPlease enter the division(Recomended: 1000+) \n");
	scanf("%d",&division);
	printf("\nPlease enter the power \n ");
	scanf("%d",&power);
	float h = (fabs(up_val-down_val)/division);

	for(i=0;i<=power;i++){
		printf("\nEnter the value of coefficient x^(%d) :",i);
		scanf("%d",coef_p+i);
	}
	
	func_val = trapez(down_val,h,up_val,power,coef);
	printf("\nValue of Integral : %f",func_val);
	system("PAUSE");
	
	return 0;
}
//Ýts calculate ýntegral thanks to trapezoidal method
float trapez(float x,float h,int up,int us,int A[100]){
	float sum_trap;
	//F0 adding
	sum_trap += (fonk_calc(us,x,A)+fonk_calc(us,up,A))/2;
	while(x<up){
	  	x=x+h;
		sum_trap += fonk_calc(us,x,A);
	}
	return (h)*sum_trap;
}

//Ýts calculate the value of function
float fonk_calc(int us,float x_0,int A[100]){
    	float sum = 0;
    	int b;
 	for(b=0;b<=us;b++){
    	sum = sum + A[b]*pow(x_0,b);
 	}
 	return sum;
 }
