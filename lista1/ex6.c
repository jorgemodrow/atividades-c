#include <stdio.h>

/*
Escreva um programa em C para validar um lote de cheques. O programa deverá inicialmente
solicitar a soma do lote e o numero de cheques. A seguir deverá ler o valor de cada cheque
calculando a soma total. Após a digitação de todos os cheques o programa deverá imprimir as
seguintes mensagens: LOTE OK se a soma informada for igual a soma calculada. Diferença
negativa se a soma calculada for menor que a informada. Diferença positiva se a soma
calculada for maior que a informada. Observação: O valor da diferença deve ser impresso
(caso exista).
*/

void main() {

    float somainformada;
    float somacalculada = 0;
    int quantidade;
    int i;
    float valor[50];

    printf("Digite a soma, em reais, do lote de cheques: ");
    scanf("%f", &somainformada);

    printf("Digite a quantidade de cheques no lote: ");
    scanf("%d", &quantidade);

    for (i=0; i <= quantidade-1; i++) {
        printf("\nDigite o valor do cheque %d: ", i+1);
        scanf("%f", &valor[i]);

        somacalculada += valor[i];
    }

    printf("\nSoma informada: %.2f\n", somainformada);
    printf("Soma calculada: %.2f\n", somacalculada);

    if (somainformada == somacalculada) {
        printf("\nLOTE OK");
    } else if (somacalculada < somainformada) {
        printf("\nDIFERENCA NEGATIVA");
    } else {
        printf("\nDIFERENCA POSITIVA");
    }
}
