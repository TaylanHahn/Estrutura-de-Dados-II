## Exercício — Grafos e Matriz de Adjacência

Considere o conjunto de cidades do Rio Grande do Sul representado pelos índices abaixo:

| Índice | Cidade |
|---|---|
| 0 | Porto Alegre |
| 1 | Canoas |
| 2 | Novo Hamburgo |
| 3 | Gramado |
| 4 | Caxias do Sul |
| 5 | Passo Fundo |
| 6 | Erechim |
| 7 | Santa Maria |
| 8 | Pelotas |
| 9 | Rio Grande |

### Conexões entre as cidades

As conexões entre as cidades são dadas pelas seguintes arestas:

| Origem | Destino | Distância |
|---|---|---|
| 0 | 1 | 18 km |
| 0 | 2 | 45 km |
| 1 | 4 | 115 km |
| 2 | 3 | 75 km |
| 3 | 4 | 70 km |
| 4 | 5 | 145 km |
| 5 | 6 | 80 km |
| 4 | 7 | 290 km |
| 7 | 8 | 260 km |
| 8 | 9 | 60 km |

### Objetivo

Desenvolver um programa utilizando:

- Grafos;
- Matriz de adjacência;
- Algoritmo de busca em grafos.

O programa deve verificar se existe uma rota disponível entre duas cidades.

Caso não exista ligação entre duas cidades, o valor correspondente na matriz deve ser `0`.

### Requisitos

**a) Exibir as cidades ao usuário**: O programa deve apresentar a lista de cidades no seguinte formato:

```text
0 - Porto Alegre
1 - Canoas
2 - Novo Hamburgo
...
```

**b) Entrada de dados**: O usuário deverá informar:

- Cidade de origem;
- Cidade de destino.

Utilize os índices das cidades para entrada dos dados.

**c) Busca da rota:** Realizar a busca da rota utilizando um dos seguintes algoritmos:

- DFS (*Depth-First Search* / Busca em Profundidade);
- BFS (*Breadth-First Search* / Busca em Largura).

O algoritmo deve percorrer o grafo verificando se existe caminho entre a origem e o destino.

**d) Resultado:** O programa deve apresentar:

- Se existe rota entre as cidades;
- Ou se não existe caminho disponível.
