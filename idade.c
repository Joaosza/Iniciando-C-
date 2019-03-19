#include <stdio.h>
#include <stdlib.h>


int main () 
{
	char *nome;
	int *idade;
	
	nome = malloc(sizeof(char)*100);
	idade = malloc(sizeof(int));
	
	scanf("%s", nome);
	scanf("%d", idade);

	
	if (*idade >= 18)
		printf("%s voce é maior de idade\n", nome);
	else
		printf("menor de idade\n");
		
	return 0;
}
