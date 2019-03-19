#include <stdio.h>

void f2c (double *t)
{
	*t = 1.8 * *t + 32.0;
}

int main ()
{
	double temp;
	
	printf("qual a temp em f?\n");
	scanf("%lf", &temp);
	
	f2c(&temp);
	
	printf("a temp em c é %.3lf\n", temp);
	
	return 0;
}
