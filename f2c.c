#include <stdio.h>

double f2c (double t)
{
	return 1.8*t + 32.0;
}

int main ()
{
	double temp;
	
	printf("qual a temp em f?\n");
	scanf("%lf", &temp);
	
	printf("a temp em c é %.3lf\n", f2c(temp));
	
	return 0;
}
