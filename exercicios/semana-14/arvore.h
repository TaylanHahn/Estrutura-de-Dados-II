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


// funcao de pesquisa
Arvore* pesquisaValor(Arvore*a, char*nome, int *contAc){
    (*contAc)++; // incrementa o contador de acessos
     if(a == NULL){
          return NULL;
     } else if (strcmp(nome, a->nome) < 0){ // se menor -> esq
            return pesquisaValor(a->esq, nome, contAc);
     } else if (strcmp(nome, a->nome) > 0){ // se maior -> dir
            return pesquisaValor(a->dir, nome, contAc);
     } else { // se igual, achou
            return a;
     }
}


#endif


