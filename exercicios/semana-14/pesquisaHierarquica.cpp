#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "arvore.h"

int main(){
    setlocale (LC_ALL, "Portuguese"); 
    clock_t inicio = clock(); // inicio o cronometro
   
    int contAc = 0; // contador de acessos
    int matricula;
    char nome[128];
    
    No *raiz = NULL; // crio a raiz nula
    
    FILE *arq = fopen("dados.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir dados.txt\n");
        return 1;
    }
    
    // leitura do arquivo 
    while(fscanf(arq, "%d %[^\n]", &matricula, nome) == 2){
       // insere na arvore
       raiz = insere(raiz, nome, matricula);
    }
    fclose(arq);
    
    
    // faz a pesquisa na arvore
    char nomeBusca[] = "Valentina Moura";
    No *pesquisa = pesquisaValor(raiz, nomeBusca, &contAc);
    
    clock_t fim = clock(); // finalizo o cronometro
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    // impressoes
    if(pesquisa != NULL){
        printf("Aluno(a) encontrado(a) :)\n");
        printf("%s | matricula: %d\n", pesquisa->nome, pesquisa->matricula);
    } else {
        printf("Aluno(a) não encontrado(a).\n");
    }
    
    printf("Número de acessos: %d\n", contAc);
    printf("Tempo gasto na execução: %f segundos\n", tempo_gasto);
    
    raiz = Destroi(raiz);
    
    return 0;
}
