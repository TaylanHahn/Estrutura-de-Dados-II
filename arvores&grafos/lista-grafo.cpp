#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// --- ESTRUTURAS DE DADOS ---

// Estrutura para os nós da lista encadeada
typedef struct No {
    int vertice;
    struct No* prox;
} No;

// Estrutura para o Grafo (Vetor de Listas)
typedef struct Grafo {
    int numVertices;
    No* listasAdjacencia[MAX_VERTICES];
} Grafo;

// --- FUNÇÕES DE CRIAÇÃO ---

// Inicializa o grafo com as listas vazias
Grafo* criarGrafo(int vertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        grafo->listasAdjacencia[i] = NULL;
    }
    return grafo;
}

// Cria um novo nó para a lista encadeada
No* criarNo(int v) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->vertice = v;
    novoNo->prox = NULL;
    return novoNo;
}

// Adiciona uma aresta (Neste caso, Direcionada)
void adicionarAresta(Grafo* grafo, int origem, int destino) {
    // Adiciona o destino no início da lista da origem
    No* novoNo = criarNo(destino);
    novoNo->prox = grafo->listasAdjacencia[origem];
    grafo->listasAdjacencia[origem] = novoNo;
    
    // Se o grafo fosse Não-Direcionado, você repetiria o processo invertendo origem e destino aqui.
}

// --- PERCURSOS (DFS E BFS) ---

// Busca em Profundidade (DFS) Recursiva
void dfs(Grafo* grafo, int verticeAtual, int visitados[]) {
    visitados[verticeAtual] = 1;
    printf("%d ", verticeAtual);

    // Percorre a lista encadeada do vértice atual
    No* temp = grafo->listasAdjacencia[verticeAtual];
    while (temp != NULL) {
        int vizinho = temp->vertice;
        if (!visitados[vizinho]) {
            dfs(grafo, vizinho, visitados);
        }
        temp = temp->prox; // Pula para o próximo vizinho da lista
    }
}

// Busca em Largura (BFS) Iterativa
void bfs(Grafo* grafo, int verticeInicial) {
    int visitados[MAX_VERTICES] = {0};
    int fila[MAX_VERTICES], inicioFila = 0, fimFila = 0;

    visitados[verticeInicial] = 1;
    fila[fimFila++] = verticeInicial;

    while (inicioFila < fimFila) {
        int verticeAtual = fila[inicioFila++];
        printf("%d ", verticeAtual);

        // Percorre a lista encadeada do vértice atual
        No* temp = grafo->listasAdjacencia[verticeAtual];
        while (temp != NULL) {
            int vizinho = temp->vertice;
            if (!visitados[vizinho]) {
                fila[fimFila++] = vizinho;
                visitados[vizinho] = 1;
            }
            temp = temp->prox;
        }
    }
}

// --- FUNÇÃO PRINCIPAL E LEITURA DE ARQUIVO ---

int main() {
    FILE *arquivo = fopen("grafo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: Arquivo grafo.txt nao encontrado!\n");
        return 1;
    }

    int numVertices, numArestas;
    // Lê a primeira linha: quantidade de vértices e arestas
    fscanf(arquivo, "%d %d", &numVertices, &numArestas);

    Grafo* grafo = criarGrafo(numVertices);

    // Lê o restante do arquivo para criar as conexões
    for (int i = 0; i < numArestas; i++) {
        int origem, destino;
        fscanf(arquivo, "%d %d", &origem, &destino);
        adicionarAresta(grafo, origem, destino);
    }
    fclose(arquivo);

    printf("Grafo carregado com sucesso!\n\n");

    // Vetor de visitados para o DFS
    int visitadosDFS[MAX_VERTICES] = {0};

    printf("Caminhamento DFS (iniciando no 0): ");
    dfs(grafo, 0, visitadosDFS);
    printf("\n");

    printf("Caminhamento BFS (iniciando no 0): ");
    bfs(grafo, 0);
    printf("\n");

    return 0;
}
