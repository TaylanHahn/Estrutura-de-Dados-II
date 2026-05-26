#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

#define MAX 64

int main(void){
    char nome[MAX];
    char novoNome[MAX];
    char pesquisa[MAX];
    char remova[MAX];
    int op;
    int matricula;
    int novaMatricula;
    

 // criacao da raiz
 Arvore *raiz = NULL;
 
 // abro o arquivo pra leitura
 FILE *arq;
 if((arq = fopen("dados.txt", "r")) == NULL){
        printf("bah, deu ladaia no arquivo :(");
        return 1;
 }
 
 // funcao a insercao na arvore (ok)
 while(fscanf(arq, "%d %[^\n]", &matricula, nome) != EOF){
   raiz = insere(raiz, nome, matricula);
 } printf("Dados inseridos na arvore\n\n"); fclose(arq);
 
 // menu
        do{
           printf("\t\t\n============ MENU ============== \n");
           printf("1. Inserir novo valor na arvore \n"); 
           printf("2. Remover valor da arvore \n");
           printf("3. Pesquisar valor na arvore \n");
           printf("4. Imprimir arvore \n");
           printf("0. SAIR \n");
           printf("Escolha a opcao (numero): ");
           scanf("%d", &op);
           
           switch(op){
                  case 1: 
                       printf("Informe o nome a ser inserido:");
                       getchar();
                       scanf("%[^\n]", novoNome);
                       printf("Informe a matricula a ser inserida:");
                       getchar();
                       scanf("%d", &novaMatricula);
                       raiz = insere(raiz, novoNome, novaMatricula);
                       break;
                       
                  case 2:
                       printf("Informe o NOME a ser removido remover:");
                       getchar();
                       scanf("%[^\n]", remova);
                       raiz = remover(raiz, remova);
                       break;
                       
                  case 3:
                       printf("Informe o NOME a ser pesquisado:");
                       getchar();
                       scanf("%[^\n]", pesquisa);
                       pesquisaValor(raiz, pesquisa);
                       break;
                  
                  case 4: 
                       printf("=== Arvore completa ===\n(impressa por nome):\n\n");
                       imprimeArvore(raiz);
                       break;
                       
                  case 0: 
                       printf("\n'Hasta la vista, baby'\n” -The Terminator");
                       break;
           }            
        } while (op != 0);    
 Destroi(raiz); 

 return(0);
}

