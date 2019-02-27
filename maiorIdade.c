#include <stdio.h>
#include <stdlib.h>

int main()
{
  char * nome;
  int * idade;

  nome = malloc(sizeof(char)*100);
  idade = malloc(sizeof(int));

  scanf("%s\n", nome);
  scanf("%d\n", idade);

  if(idade >= 18)
    printf("%s Maior de idade\n", nome);
  else
    printf("%s Menor de idade\n", nome);

  return 0;
}
