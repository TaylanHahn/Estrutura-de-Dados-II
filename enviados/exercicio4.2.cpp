#include <stdio.h>
#include <stdlib.h>

int main(){
char caractere; 

FILE *original = fopen("arquivo_texto.txt", "r");
FILE *alterado = fopen("arquivo_alterado.txt", "w");

if(original != NULL && alterado!= NULL){
    while(!feof(original)){
        
        caractere = fgetc(original);
        
        if(caractere == 'a'){
            printf("A");
            fprintf(alterado, "A");
        } else if(caractere == 'e'){
            printf("E");
            fprintf(alterado, "E");
        } else if(caractere == 'i'){
            printf("I");
            fprintf(alterado, "I");
        } else if(caractere == 'o'){
            printf("O");
             fprintf(alterado, "O");
        } else if(caractere == 'u'){
            printf("U");
             fprintf(alterado, "U");
        } else {
            printf("%c", caractere);
            fprintf(alterado, "%c", caractere);
        }
    }
} else {
    printf("Erro ao abrir arquivo_texto.txt");
    return 1;
}
fclose(original);
fclose(alterado);
system("pause"); 
}

