/*
Considerando que o arquivo "dados.dat" formado pela estrutura abaixo:
char [35]
int
float
Leia o conteudoo do arquivo e apresente na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct para organizar os dados
typedef struct {
	char colunaUm [35];
	int colunaDois;
	float colunaTres;
} Conteudo;

int main(void) {
    Conteudo *dados = (Conteudo*) malloc(200 * sizeof(Conteudo));
	FILE *dat;
	int cont = 0;
	
	// testo erro no malloc
	if(dados == NULL){
	    printf("Erro no malloc.");
	    return 1;
	}

    // testo erro ao abrir arquivo	
	if((dat = fopen("dados.dat","rb")) == NULL) {
		printf("Erro ao abrir arquivo");
		return 1;
	} else {
	    // laço para ler o arquivo
		while(!feof(dat)) {
			fread(&dados[cont], sizeof(Conteudo), 1, dat);
			cont++;
		}
		
		// laço para imprimir
		for(int i=0; i < cont - 1; i++){
		    printf("%-25s | %-5d | %.2f \n", dados[i].colunaUm, dados[i].colunaDois, dados[i].colunaTres);
		}
		
		fclose(dat);
	}
	free(dados);
	system("pause");
	return 0;
}