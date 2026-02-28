#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void main(){
char cidade[MAX][20]; 
int populacao[MAX]; 
char uf[MAX][3]; // 2 pra UF +1 pro null terminator

int i = 0;
FILE *txt;

if((txt = fopen("cidades.txt","r")) == NULL){
        printf("Erro ao abrir arquivo");
    } else {
        while (!feof(txt)) {
            fscanf(txt, "%s %d %s", cidade[i], &populacao[i], uf[i]);
            i++;
        }

        int lista = i;
        fclose(txt);

        for(i=lista - 1; i >= 0; i--){
            printf("\t %-10s %-10d %-15s\n", cidade[i], populacao[i], uf[i]);
        }
      }
system("pause"); 

}


    
