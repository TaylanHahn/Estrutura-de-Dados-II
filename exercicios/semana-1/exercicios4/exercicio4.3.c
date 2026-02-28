#include <stdio.h>
#include <stdlib.h>

int main() {
	char caractere;

	FILE *original = fopen("arquivo_texto.txt", "r");
	FILE *alterado = fopen("arquivo_alterado2.txt", "w");

	if(original != NULL && alterado!= NULL) {
		while(!feof(original)) {

			while ((caractere = fgetc(original)) != EOF) {
				if(caractere == '\n') {
					printf("\n");
					fprintf(alterado, "\n");
				} else {
					printf("%c", caractere);
					fprintf(alterado, "%c", caractere);
				}
			}
		}
	} else {
		printf("Erro ao abrir arquivo_texto.txt");
		return 1;
	}
	fclose(original);
	fclose(alterado);
	system("pause");
	return 0;
}

