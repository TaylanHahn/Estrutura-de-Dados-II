# Questões objetivas (1-20)

### 1. Considerando o programa abaixo, responda:
<img src="./atividades-ead/img/01.png">
Escolha uma opção:

Escolha uma opção:

a.10

b.21

c.11

d.91

e.30 ✅

---

### 2. Considerando a estrutura Pessoa, como é possível acessar via ponteiro a propriedade nome?
<img src="./atividades-ead/img/02.png">

a. aluno.nome

b. Cpessoa->nome

c. aluno->nome

d. Cpessoa.nome

e. paluno->nome ✅

---

### 3. Conhecendo parte da implementação do Código abaixo, Qual é o método de inserção de um Novo Nó a lista?

````c
Lista * set_lista(Lista * l, int a, char s[50]) {
 Lista * novo = (Lista *) malloc (sizeof(Lista));
 novo->matricula = a; 
 strcpy (novo->pessoa, s );
 novo->proximo = l;
 novo->anterior = NULL;
   if (l != NULL)
   l->anterior = novo;
return(novo);
}

void view_lista(Lista * l){
Lista * pl;
   for (pl = l; pl != NULL; pl = pl->proximo){
   printf("No %x Proximo: %x Anterior: %x \n", pl, pl->proximo, pl->anterior);
   }
}

int verifica_lista(Lista * l){
    if (l == NULL) 
     printf("\nLista Vazia\n"); 
    else
     printf("\nLista nao Vazia\n"); 
    }

Lista * find_lista(Lista * l, int argumento){
 Lista * pl;
   for (pl = l; pl != NULL; pl = pl->proximo) {
       if (pl->matricula == argumento)
       return (pl);    
   }
 return(NULL);
}

Lista * delete_elemento(Lista * pl, int argumento){
 Lista * anterior = NULL;
 Lista * atual = pl;
    while (atual != NULL && atual->matricula != argumento){
     anterior = atual;
     atual = atual->proximo;
   }

 if (atual == NULL) {
     printf ("Elemento noo localizado!\n"); 
     return(pl);
 }

 if (anterior == NULL){
       pl = pl->proximo; 
  } else  {
       anterior->proximo = atual->proximo;
  }
 free(atual);
 return(pl);
}

void free_lista(Lista ** pl){
 while (*pl != NULL){
     Lista * t = (*pl)->proximo;
     *pl = NULL;
     free(*pl);
     *pl = t;
 }
 }

void imprime_circular_rev (Lista* l){
   Lista* p = l; 
if (p) { 
     do {
         printf("Matricula: %d Nome: %s\n", p->matricula, p->pessoa) ; 
         p = p->proximo;
     }
     while (p != NULL);
    } 
}
````
Escolha uma opção:

a.Inserção no inicio da lista, retornando último Nó

b. Nenhuma das Alternativas.

c.Inserção no final de lista, retornando o primeiro Nó

d.Inserção no final de lista, retornando o último Nó

e.Inserção no inicio da lista, retornando o primeiro Nó ✅


