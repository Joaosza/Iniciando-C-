#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *n;

  n = malloc( sizeoff(int) );

  if(n == NULL){
    printf("Falha ao alocar memoria\n");
    exti(1);
  }

  *n = 50;

  printf("**n==%i\n", *n);

  free(n);

  return 0;
}
