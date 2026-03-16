#include <stdio.h>
#include <stdlib.h>

#define TAM 1000000

int* carregarArquivo(){								//funcao para carregar o txt 

    FILE *arq = fopen("dados.txt","r");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1); 		//encerra o programa
    }

    int *v = (int*) malloc(TAM * sizeof(int));		//v passa a apontar p o primeiro elemento do vetor

    if(v == NULL){
        printf("Erro de alocação de memoria\n");
        exit(1);
    }

    for(int i = 0; i < TAM; i++){
        fscanf(arq,"%d",&v[i]);						//le o arquivo e guarda na posicao i do vetor
    }

    fclose(arq);

    return v;										//retorna o ponteiro p o vetor criado
}

int buscaBinaria(int v[], int n, int chave, int *acessos){

    int inicio = 0;
    int fim = n - 1;

    while(inicio <= fim){					//enquanto o intervalo for valido

        int meio = (inicio + fim) / 2;
        (*acessos)++;						//a cada meio, contabiliza um acesso

        if(v[meio] == chave)
            return meio;

        if(chave < v[meio])				//se for menor, elimina toda metade direita, desloca pra esquerda
            fim = meio - 1;
        else
            inicio = meio + 1;			//senao, elimina a metade esquerda e desloca pra direita
    }

    return -1;
}

int main(){

    int *v = carregarArquivo();			//chama a funcao que le o arquivo

    int valores[] = {7341488,85,265654,732765,8313596,45744};
    int qtdvalores = 6;
    int totalAcessos = 0;

    printf("\nBusca binaria\n");

    for(int i = 0; i < qtdvalores; i++){

        int acessos = 0;			//zera os acessos a cada vez 

        buscaBinaria(v, TAM, valores[i], &acessos);
        
        totalAcessos = totalAcessos + acessos;

        printf("Valor %d - %d acessos\n", valores[i], acessos);
    }
    
    printf("Total de acessos: %d", totalAcessos);

    free(v);

    return 0;
}
