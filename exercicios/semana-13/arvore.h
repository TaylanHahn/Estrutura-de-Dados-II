#ifndef ARVORE_H
#define ARVORE_H

#include <string.h>

#define MAX 64

// definicao da struct
typedef struct Nodo {
        struct Nodo *esq;
        char nome [MAX];
        int matricula;
        struct Nodo *dir;
} No;

typedef No Arvore;

// funcao de criar no
Arvore *Cria(No*esq, char*nome, int matricula, No*dir){
        Arvore *p;

        p = (Arvore*) malloc(sizeof(Arvore));
        if (p == NULL){
           printf("ERRO: sorry bro, sem memoria.\n");
           getchar();
           exit(0); 
        } else {
          p->esq = esq;
          strcpy(p->nome, nome);
          p->matricula = matricula;
          p->dir = dir;
        }
        return p;
}

// testa se esta vazia
int Vazia(Arvore *a){
 if (a == NULL)
     return(1);
 else
     return(0);
}


// funcao de desmatamento (alo IBAMA)
Arvore *Destroi(Arvore *a){
        if (!Vazia(a)){
           Destroi(a->esq); 
           Destroi(a->dir); 
           free(a);         
        }
        return(NULL);
}

// 1. funcao pra inserir [OK]
Arvore *insere(Arvore *a, char *nome, int matricula) {
    if (a == NULL) {
          a = Cria(NULL, nome, matricula, NULL);
       } else if (strcmp(nome, a->nome) < 0) {
              a->esq = insere(a->esq, nome, matricula);
          } else {
                 a->dir = insere(a->dir, nome, matricula);
          }
    return a;
}

// 2. funcao de remover
Arvore *remover(Arvore*a, char *valor){
     if(a==NULL)
          return 0;
     
     if(strcmp(valor, a->nome) < 0)
              a->esq = remover(a->esq, valor);
     else if(strcmp(valor, a->nome) > 0)
          a->dir = remover(a->dir, valor);
     else{
          // caso 1 - sem filhos
          if(a->esq == NULL && a->dir == NULL){ 
                    free(a);
                    return NULL;
          // caso 2 - apenas filho direito
          } else if(a->esq == NULL){
                 No*temp = a->dir;
                 free(a);
                 return temp;
          // apenas filho esquedo
          } else if(a->dir == NULL){
                 No*temp = a->esq;
                 free(a);
                 return temp;
          // caso 3 - dois filhos
          } else {
                 No*temp = a->dir;
                 // procuro o menor da direita
                    while(temp->esq!=NULL) temp = temp->esq;
                 
                 // troco os dados
                 strcpy(a->nome, temp->nome);
                 a->matricula = temp->matricula;
                 
                 // faco a remocao
                 a->dir = remover(a->dir, temp->nome);
          }
     }
     return a;
}


// 3. funcao de pesquisa [OK]
void pesquisaValor(Arvore*a, char*nome){
     if(a == NULL){
          printf("Estudante nao encontrado(a) :(\n");
          return;
     } else if (strcmp(nome, a->nome) < 0){ // se menor -> esq
            pesquisaValor(a->esq, nome);
     } else if (strcmp(nome, a->nome) > 0){ // se maior -> dir
            pesquisaValor(a->dir, nome);
     } else { // se igual, achou
            printf("\tEncontrado!\n Nome: %s | Matricula: %d\n", a->nome, a->matricula);
     }
}

// 4. funcao de imprimir (esq -> raiz -> dir) [OK]
void imprimeArvore(Arvore *a){
     if (!Vazia(a)){
        imprimeArvore(a->esq);     
        printf("Nome: %s | Matricula: %d\n", a->nome, a->matricula); 			
        imprimeArvore(a->dir);     
     }
}

#endif



