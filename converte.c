#include <stdio.h>

double f2c (double *t)
{
*t = 1.8 * *t + 32.0;
}
int main()
{

  double temp;

  printf("Qual a temperatura em F\n");
  scanf("%lf", &temp);

  f2c(&temp);

  printf("a temperatura em celsius é %.3lf\n", temp);

  return 0;
}
