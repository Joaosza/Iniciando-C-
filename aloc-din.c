#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int *n;

	n = malloc( sizeof(int) );

	if (n == NULL) {
		printf("falha ao alocar memoria\n");
		exit(1);
	}

	*n = 50;

	printf("*n=%i\n", *n);

	free(n);

	return 0;
}
