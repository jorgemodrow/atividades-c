#include <stdio.h>

// Calcular e imprimir o total da soma obtida dos cem primeiros números inteiros
// (1+2+3+...+98+99+100).

void main() {

    int i, soma;

    for (i = 1; i <= 100; i++) {
        soma += i;
    }

    printf("Soma dos cem primeiros numeros inteiros: %d", soma);
}
