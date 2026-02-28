#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void main(){
char nome[23]; 
int idade;

FILE * txt;

if((txt = fopen("nomes.txt", "r")) == NULL) {
    printf("Erro ao abrir o arquuivo nomes.txt");
} else {
    while(!feof(txt)){
        fscanf(txt, "%22c %d\n", nome, &idade);
        printf("%-22s%d\n", nome, idade);
    }
    fclose(txt);
}
    system("pause");

}


    
