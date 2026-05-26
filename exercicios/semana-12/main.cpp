#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

#define MAX 32

int main(void){
    char nome[MAX];
    int i = 0;
    int op;
    int matricula;

 // criacao da raiz
 Arvore *raiz = NULL;
 
 // abro o arquivo pra leitura
 FILE *arq;
 if((arq = fopen("dados.txt", "r")) == NULL){
        printf("bah, deu ladaia no arquivo :(");
        return 1;
 }
 
 // funcao a insercao na arvore
 while(fscanf(arq, "%d %[^\n]", &matricula, nome) != EOF){
   raiz = insere(raiz, matricula, nome);
 } printf("dados inseridos na arvore"); fclose(arq);
 
 // menu
        do{
           printf("\t\t\n============ MENU ============== \n");
           printf("1. Buscar estudante por matricula \n");
           printf("2. Listar todos os estudantes \n");
           printf("0. SAIR \n");
           printf("Escolha a opcaoo (numero): ");
           scanf("%d", &op);
           
           switch(op){
                  case 1: printf("Informe o numero da matricula:\n");
                          scanf("%d", &matricula);
                          i = 0; // zero o contador, para cada vez que a opcao 1 for escolhida
                          buscaEstudante(raiz, matricula, &i);
                       break;
                  case 2: printf("=== Lista de estudantes ===\n(por matricula):\n\n");
                          listarEstudantes(raiz);
                       break;
                  case 0: printf("\n'Hasta la vista, baby'\n” -The Terminator");
                       break;
           }            
        } while (op != 0);    
 Destroi(raiz); 

 return(0);
}

