#include <stdio.h>

/*
Faça um programa que receba dois números X e Y, sendo X < Y. Calcule e mostre:

- a soma dos números pares desse intervalo de números, incluindo os números digitados;
- a multiplicação dos números ímpares desse intervalo, incluindo os digitados
*/

int main() {
    int x;
    int y;
    int i;
    int soma = 0;
    int multiplicacao = 1;
    int qtdpar = 0;
    int qtdimpar = 0;

    printf("Digite o menor numero: ");
    scanf("%d", &x);
    printf("Digite o maior numero: ");
    scanf("%d", &y);

    for (i=x; i<=y; i++) {
        if (i % 2 == 0) {
            soma += i;
            qtdpar += 1;
        } else {
            multiplicacao *= i;
            qtdimpar += 1;
        }
    }

    if (qtdpar == 0) {
        printf("Nao ha numeros pares entre o maior e o menor numero para fazer a soma.\n");
    } else {
        printf("\nSoma dos numeros pares entre o menor e o maior numeros: %d\n", soma);
    }

    if (qtdimpar == 0) {
        printf("Nao ha numeros impares entre o maior e o menor numero para fazer o produto.\n");
    } else {
        printf("Produto dos numeros impares entre o menor e o maior numero: %d", multiplicacao);
    }
}
