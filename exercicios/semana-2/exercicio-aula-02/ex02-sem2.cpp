#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main (void)
{

    char * letras =  (char*) calloc(100, sizeof(char));

    strcpy(letras, "Linguagem C - Eu adoro programa em C \n")   ;

    int i=0;

    while (i< 100)
    {
        printf("%c",*letras);
        i++;
        letras++;
    }

    return 0;
}