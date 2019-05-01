#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* abrir_arquivo (char *fname)
{
	FILE *fp;

	fp = fopen(fname, "rb+");

	if (fp == NULL) {
		fp = fopen(fname, "wb");

		if (fp == NULL) {
			printf("impossivel criar arquivo %s\n", fname);
			exit(1);
		}

		fclose(fp);

		fp = fopen(fname, "rb+");

		if (fp == NULL) {
			printf("impossivel abrir arquivo %s\n", fname);
			exit(1);
		}
	}

	return fp;
}

void desastre ()
{
	int n;
	char d[300];

	for (n=0; n<300; n++)
		d[n] = 1;
}

void ler_escrever ()
{
	char buffer_leitura[100];
	FILE *fp;
	char str[50] = "eduardo";
	int n;

	fp = abrir_arquivo("data.dat");

	n = fread(buffer_leitura, sizeof(char), 100, fp);
	buffer_leitura[n] = 0;

	printf("%s\n", buffer_leitura);

	fclose(fp);
	fp = abrir_arquivo("data.dat");

	fwrite(str, sizeof(char), strlen(str), fp);

	fclose(fp);
}

int main ()
{
	desastre();
	ler_escrever();

	return 0;
}
