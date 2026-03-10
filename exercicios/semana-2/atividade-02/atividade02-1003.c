/*
FaC'a um programa em C que leia o arquivo "dados.txt" (CC3digo, Produto, PreC'o e Quantidade) e mostre os dados na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define QTD_LINHAS 3750 // total de linhas, com folga de 10

typedef struct {
	int codigo;
	char produto [100];
	char categoria [20];
	float preco;
	int qtd;
} Dados;

int main() {
	setlocale(LC_ALL, "Portuguese");

	// MALLOC
	Dados *produtos = (Dados*) malloc(QTD_LINHAS * sizeof(Dados));
	if(produtos == NULL) {
		printf("Falha na alocaC'C#o de memC3ria");
		return 1;
	}

	// ABRINDO ARQUIVO
	FILE *txt;
	if((txt = fopen("dados.txt", "r")) == NULL) {
		printf("Erro ao abrir arquivo");
		free(produtos);
		return 1;
	}

	int cont = 0;
	
	// Nota: uso de IA para entender como faz a leitura das linhas com espaços
	// > Comentei mais esse trecho, para fins de estudo 
	
	char linha[256]; 
	
	while(fgets(linha, sizeof(linha), txt) != NULL){
	    // 1. recorto o codigo
	    sscanf(linha, "%d",  &produtos[cont].codigo);
	    
	    // 2. procuro o nome do produto, logo dps do primeiro espaço
	    char *inicio = strchr(linha, ' ');
	    if(inicio != NULL){
	        inicio++; // pula o espaço
	        
	        // 3. procuro o final do nome
	        char *final = strstr(inicio, "  "); // procuro dois espaços seguidos
	        if(final != NULL){
	            int tamanho_nome = final - inicio;
	            
	            // copio o resultado pra variavel produto
	            strncpy(produtos[cont].produto, inicio, tamanho_nome);
	            produtos[cont].produto[tamanho_nome] = '\0'; // coloco o fim da string
	            
	            // 4. leio o restante dos dados, a partir do *final
	            sscanf(final, "%s %f %d", 
	                produtos[cont].categoria,
	                &produtos[cont].preco,
	                &produtos[cont].qtd);
	                
	            cont++;
	        }
	    }
	    
	    	// segurança pra nao ultrapassar a qtd total
		    if(cont >= QTD_LINHAS) break;
	}
	
	fclose(txt);
	

    // impressao
	for(int i=0; i<cont; i++) {
		printf("%-6d | %-80s | %-20s | R$ %-7.2f | %-5d\n",
		       produtos[i].codigo,
		       produtos[i].produto,
		       produtos[i].categoria,
		       produtos[i].preco,
		       produtos[i].qtd);
	}

	free(produtos);
	return 0;
}

/*
- strchr: Localiza um único caráter num texto.
- strstr: Localiza um trecho de texto noutro texto.
- strncpy: Copia uma quantidade exata de letras.
- sscanf: Extrai dados e variáveis diretamente de uma string.
*/








