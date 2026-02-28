#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>
#define MAX 10

typedef struct{
    char nome[23];
    int idade;
} Pessoa;

int main(){

FILE *nomes = fopen("nomes.txt", "r");
FILE *lista = fopen("lista.txt", "w");

Pessoa p [50];
int i = 0;
int listaPessoas = MAX;

if(nomes != NULL && lista != NULL){
    while(i <= listaPessoas && fscanf(nomes, " %22[^0-9] %d", p[i].nome, &p[i].idade) == 2){
        fprintf(lista, "%-22s%d\n", p[i].nome, p[i].idade);
        i++;
    }
} else {
    printf("Erro: o arquivo 'nomes.txt' está vazio.");
    return 1;
}

fclose(nomes);
fclose(lista);
return 0;
}

