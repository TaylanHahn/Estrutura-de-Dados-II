# Questões objetivas (1-20)

## 📌 1. Considerando o programa abaixo, responda:
![Descrição da imagem](img/01.png)

**Escolha uma opção:**

a.10

b.21

c.11

d.91

e.30 ✅

---

## 📌 2. Considerando a estrutura Pessoa, como é possível acessar via ponteiro a propriedade nome?
![Descrição da imagem](img/02.png)

a. aluno.nome

b. Cpessoa->nome

c. aluno->nome

d. Cpessoa.nome

e. paluno->nome ✅

---

## 📌 3. Conhecendo parte da implementação do Código abaixo, Qual é o método de inserção de um Novo Nó a lista?

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

**Escolha uma opção:**

a.Inserção no inicio da lista, retornando último Nó

b. Nenhuma das Alternativas.

c.Inserção no final de lista, retornando o primeiro Nó

d.Inserção no final de lista, retornando o último Nó

e.Inserção no inicio da lista, retornando o primeiro Nó ✅

---

## 📌 4. Considerando o bloco de memória com endereço inicial **0xC8** e com tamanho de cada célula de **8 bits**:

| Endereço | Dado (ASCII) ou Endereço |
|----------|--------------------------|
| 0xC8     |                          |
| 0xC9     |                          |
| 0xCA     |                          |
| 0xCB     |                          |
| 0xCC     |                          |
| 0xCD     |                          |
| 0xCE     |                          |
| 0xCF     |                          |

### 💻 Trecho do Programa

```c
char palavra[3] = {'A','B','C'}; 
char *ppalavra = palavra;
````

**Explicação:** 
- Cada char ocupa 1 byte (8 bits)
- Endereço inicial de palavra = 0xCA

**Logo:** 'A' → 0xCA  // 'B' → 0xCB  //  'C' → 0xCC

- ppalavra guarda o endereço inicial de palavra, ou seja: 0xCA
- Endereço de ppalavra = 0xCF

**Resposta:**

| Endereço | Dado (ASCII) ou Endereço |
|----------|--------------------------|
| 0xC8     |                          |
| 0xC9     |                          |
| 0xCA     | 'A'                      |
| 0xCB     | 'B'                      |
| 0xCC     | 'C'                      |
| 0xCD     |                          |
| 0xCE     |                          |
| 0xCF     | 0xCA                     |
