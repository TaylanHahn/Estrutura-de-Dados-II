#include <stdio.h>
#include <stdlib.h>

void main(){
char cidade[20]; 
int populacao; 
char uf[2]; 

FILE *txt;

if((txt = fopen("cidades.txt","r")) == NULL){
        printf("Erro ao abrir arquivo");
    } else {
        while (!feof(txt)) {
               fscanf(txt, "%s %d %s", cidade, &populacao, uf);
               printf("\t %-10s %-10d %-15s\n", cidade, populacao, uf);
              }
          fclose(txt);
      }
system("pause"); 

}


    
