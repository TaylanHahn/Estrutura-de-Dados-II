/*

Dado um vetor de 20 números inteiros, implemente em linguagem C um programa que:

1. Leia os 20 elementos do vetor.

2. Utilize funções recursivas para:

Determinar quantos elementos pares existem no vetor.
Determinar quantos elementos ímpares existem no vetor.
Exiba os resultados finais.
Requisitos:

A função recursiva deve receber como parâmetros o vetor, o índice atual e o tamanho total.
O caso base ocorre quando o índice ultrapassa o tamanho do vetor.
A cada chamada recursiva, o programa deve verificar se o elemento atual é par ou ímpar e acumular a contagem.
Não é permitido usar laços de repetição (for, while) para realizar a contagem.

****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 20

int contarPares(int v[], int i, int tam){
    
    if (i > tam){
        return 0;
    }
    
    if(v[i] % 2 == 0){
        return 1 + contarPares(v, i + 1, tam);
    } else {
        return contarPares(v, i + 1, tam);
    }
}

int main(){
   
   int v[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
   
   int pares = contarPares(v, 0, TAMANHO);
   int impares = TAMANHO - pares;
   
   printf("Total de pares: %d\n", pares - 1);
   printf("Total de impares: %d\n", impares - 1);
   
    return 0;
}







