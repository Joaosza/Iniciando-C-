#include <stdio.h>

double div (int a, int b)
{
	return (double)a / (double)b;
}

int main ()
{
	printf("a/b = %.3f\n", div(5, 2));
	
	return 0;
}
