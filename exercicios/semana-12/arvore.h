#ifndef ARVORE_H
#define ARVORE_H

#define MAX 32

// definicao da struct
typedef struct Nodo {
        struct Nodo *esq;
        int matricula;
        char nome [MAX];
        struct Nodo *dir;
} No;

typedef No Arvore;

// funcaoo de criar no
Arvore *Cria(No*esq, int matricula, char*nome, No*dir){
        Arvore *p;

        p = (Arvore*) malloc(sizeof(Arvore));
        if (p == NULL){
           printf("ERRO: sorry bro, sem memória.\n");
           getchar();
           exit(0); 
        } else {
          p->esq = esq;
          p->matricula = matricula;
          strcpy(p->nome, nome);
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

// funcao pra inserir 
Arvore *insere(Arvore *a, int matricula, char *nome) {
    if (a == NULL) {
        a = Cria(NULL, matricula, nome, NULL);
    } else if (matricula < a->matricula) {
        a->esq = insere(a->esq, matricula, nome);
    } else if (matricula > a->matricula) {
        a->dir = insere(a->dir, matricula, nome);
    }
    return a;
}

// esq -> raiz -> dir
void listarEstudantes(Arvore *a){
     if (!Vazia(a)){
        listarEstudantes(a->esq);     
        printf("%d - %s\n", a->matricula, a->nome); 			
        listarEstudantes(a->dir);     
     }
}

// funcao pra achar o estudante no arvoredo
void buscaEstudante(Arvore*a, int matricula, int*i){
     (*i)++; // acessa diretamente o contador e incrementa
     
     if(a == NULL){
          printf("Estudante não encontrado(a) :(\n");
          return;
     } else if (matricula < a->matricula){ // se menor -> esq
            buscaEstudante(a->esq, matricula, i);
     } else if (matricula > a->matricula){ // se maior -> dir
            buscaEstudante(a->dir, matricula, i);
     } else { // se igual -> achou
            printf("Estudante encontrado(a).\n %d - %s\n", a->matricula, a->nome);
            printf("Total de acessos: %d\n", *i);
     }
}

#endif



