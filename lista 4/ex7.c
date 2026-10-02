#include <stdio.h>

/*

Passagem por Referencia (ponteiros) no enunciado de funções:

- a funcao vai guardar valor neles,

Passagem por Valor (Variáveis normais)

- a funcao vai apenas usá-las e nao alterá-las

*/
int testavalores(int inicio, int fim, int *pares, int *impares) {
    int i;
    *pares = 0;
    *impares = 0;

    for (i = inicio; i <= fim; i++) {
        if ((i % 2) == 0) {
            (*pares)++;
        } else {
            (*impares)++;
        }
    }

    return (*pares)+(*impares);
}

void main() {
    int menor, maior, qtdpares, qtdimpares, totalnumeros;

    printf("Digite o menor numero => ");
    scanf("%d", &menor);
    printf("Digite o maior numero => ");
    scanf("%d", &maior);

    totalnumeros = testavalores(menor,maior,&qtdpares,&qtdimpares);
    printf("Total de numeros no intervalo: %d\n", totalnumeros);
    printf("Quantidade de pares: %d\n", qtdpares);
    printf("Quantidade de impares: %d\n", qtdimpares);
}
