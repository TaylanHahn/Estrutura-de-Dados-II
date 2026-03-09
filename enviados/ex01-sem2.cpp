#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 100

int main (void) {
	char *frase = (char*) malloc(tamanho * sizeof(char));

	// teste de erro
	if(frase == NULL) {
		printf("Erro na alocação de memória");
		return 1;
	}

	strcpy(frase, "IFRS - Instituto Federal de Educação Tecnologica \n");

	int i = 0;

	while(*(frase + i) != '\n') {
		printf("%c", *(frase + i));
		i++;
	}
	
	free(frase);

	return 0;
}