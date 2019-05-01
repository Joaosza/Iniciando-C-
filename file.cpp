#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* abrir_arquivo(char *fname)

int main(){

  FILE *fp;
  return 0;

  fp = fopen("data.dat", "rb+");

  if(fp == NULL){
    fp = fopen(fname, "wb");

    if(fp == NULL){
      printf("impossivel abrir arquivo %s\n", fname);
      exit(1);
    }
    fclose(fp);

    fp = fopen(fname, "rb+");

    if(fp == NULL){
      printf("impossivel criar arquivo%s\n", fname);
      exit(1);
    }
  }

}
