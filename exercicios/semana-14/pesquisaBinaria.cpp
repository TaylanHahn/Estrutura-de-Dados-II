#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX 3000

typedef struct {
    int matricula;
    char nome[128];
} Aluno;

// função de ORDERNAÇÃO quicksort 
int particaoHoare(Aluno v[], int inicio, int fim){
    char pivot[128];
    strcpy(pivot, v[inicio].nome); 
    
    int i = inicio - 1;
    int j = fim + 1;
    
    while(1){
        do { i++; } while(strcmp(v[i].nome, pivot) < 0);
        
        do { j--; } while(strcmp(v[j].nome, pivot) > 0);
        
        if(i>=j) return j; 
        
        Aluno temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

void quicksort(Aluno v[], int inicio, int fim){
    if(inicio < fim){
        int p = particaoHoare(v, inicio, fim);
        quicksort(v, inicio, p);
        quicksort(v, p+1, fim);
    }
}

// função de BUSCA BINÁRIA
int buscaBinaria(Aluno v[], int n, const char texto[], int *contAc){
    int inicio = 0, fim = n - 1;
    
    while(inicio <= fim){
        (*contAc)++; // incrementa o contador de acessos
        int meio = (inicio + fim) / 2;
        
        int conteudo = strcmp(texto, v[meio].nome);
        
        if(conteudo == 0)
            return meio;
        else if(conteudo < 0)
            fim = meio - 1;
        else 
            inicio = meio + 1;
    }
    return -1;
}



int main(){
    setlocale (LC_ALL, "Portuguese");
    clock_t inicio = clock(); // inicio o cronometro
    Aluno alunos[MAX];
    int contAc = 0;
    int qtd = 0;
    
    FILE *arq = fopen("dados.txt", "r");
    
    if(arq == NULL){
        printf("Erro ao abrir dados.txt\n");
        return 1;
    }
    
    // leitua do arquivo
    while(qtd < MAX && fscanf(arq, "%d %[^\n]", &alunos[qtd].matricula, alunos[qtd].nome) == 2){
        qtd++;
    }
    fclose(arq);
    
    // ordenação
    if (qtd > 0) // so ordena se leu alguma coisa
        quicksort(alunos, 0, qtd - 1);
    
    // busca 
    int busca = buscaBinaria(alunos, qtd, "Valentina Moura", &contAc);
    
    clock_t fim = clock(); // finalizo o cronometro
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    // impressoes
    if(busca != -1){
        printf("Aluno(a) encontrado(a) :)\n");
        printf("%s | matricula: %d\n", alunos[busca].nome, alunos[busca].matricula);
    } else {
        printf("Aluno(a) não encontrado(a).\n");
    }
    
    printf("Número de acessos: %d\n", contAc);
    printf("Tempo gasto na execução: %f segundos\n", tempo_gasto);
    
    return 0;
}
