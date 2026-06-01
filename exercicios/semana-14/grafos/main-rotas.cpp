#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10

// Função DFS (1-sim e 0-nao)
int buscaDFS(int grafo[MAX][MAX], int atual, int destino, int visitados[]) {
    // primeiro: se cidade atual for o destino, achou a rota
    if (atual == destino) {
        return 1; 
    }
    
    visitados[atual] = 1; 
    for (int i = 0; i < MAX; i++) {
        // se existe uma "estrada" e a cidade não foi visitada
        if (grafo[atual][i] != 0 && visitados[i] == 0) {
            if (buscaDFS(grafo, i, destino, visitados) == 1) {
                return 1; 
            }
        }
    }
    // testou todas e nenhuma chegou
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    // Vetor de strings para facilitar a impressão dos nomes
    const char *nomesCidades[MAX] = {
        "Porto Alegre", "Canoas", "Novo Hamburgo", "Gramado", "Caxias do Sul",
        "Passo Fundo", "Erechim", "Santa Maria", "Pelotas", "Rio Grande"
    };
    
    // inicializa a mtriz com zero
    int grafo[MAX][MAX] = {0}; 
    
    // populo a matriz com as distâncias, ida e volta (pq a principio é não-direcionado)
    grafo[0][1] = 18;  grafo[1][0] = 18;
    grafo[0][2] = 45;  grafo[2][0] = 45;
    grafo[1][4] = 115; grafo[4][1] = 115;
    grafo[2][3] = 75;  grafo[3][2] = 75;
    grafo[3][4] = 70;  grafo[4][3] = 70;
    grafo[4][5] = 145; grafo[5][4] = 145;
    grafo[5][6] = 80;  grafo[6][5] = 80;
    grafo[4][7] = 290; grafo[7][4] = 290;
    grafo[7][8] = 260; grafo[8][7] = 260;
    grafo[8][9] = 60;  grafo[9][8] = 60;
    
    // menu
    printf("------- Sistema de Rotas do RS ------\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d - %s\n", i, nomesCidades[i]);
    }
    
    // dados do usuario
    int origem, destino;
    printf("\nDigite o numero da cidade (ORIGEM): \n");
    scanf("%d", &origem);
    
    printf("Digite o numero da cidade (DESTINO): \n");
    scanf("%d", &destino);
    
    // validaçao de entrada do indice
    if (origem < 0 || origem > 9 || destino < 0 || destino > 9) {
        printf("Erro: numero da cidade inválido!\n");
        return 1;
    }
    
    int visitados[MAX] = {0}; 
    printf("\nBuscando rota entre %s e %s...\n", nomesCidades[origem], nomesCidades[destino]);
    
    int existeRota = buscaDFS(grafo, origem, destino, visitados);
    
    if (existeRota == 1) {
        printf("EXISTE rota disponível entre as cidades!\n");
    } else {
        printf("NÃO EXISTE caminho disponível entre estas cidades.\n");
    }
    
    return 0;
}