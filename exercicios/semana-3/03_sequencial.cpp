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

int buscaSequencial(int v[], int n, int chave, int *acessos){		//vetor, tamanho do vetor, valor procurado, contador de acessos

    for(int i = 0; i < n; i++){					//verifica elemento por elemento
        (*acessos)++;

        if(v[i] == chave)
            return i;						//retorna o indice da posicao
    }

    return -1;								//se nao encontra
}

int main(){

    int *v = carregarArquivo();			//chama a funcao que le o arquivo

    int valores[] = {7341488,85,265654,732765,8313596,45744};
    int qtdvalores = 6;
    int totalAcessos = 0;

    printf("Busca sequencial\n");

    for(int i = 0; i < qtdvalores; i++){

        int acessos = 0;				//zera os acessos a cada vez (pode ser até 1000000)

        buscaSequencial(v, TAM, valores[i], &acessos);
        
        totalAcessos = totalAcessos + acessos;

        printf("Valor %d - %d acessos\n", valores[i], acessos);
    }
    
    printf("Total de acessos: %d", totalAcessos);
    
    free(v);

    return 0;
}
