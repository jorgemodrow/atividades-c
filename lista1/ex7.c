#include <stdio.h>

void main() {

    float saldoinicial;
    float saldo;
    float valor;
    int operacao;

    printf("Saldo inicial da conta bancaria: ");
    scanf("%f", &saldoinicial);

    saldo = saldoinicial;

    do {
        printf("\nSELECIONE O TIPO DA OPERACAO\n");
        printf("\n1- DEPOSITO");
        printf("\n2- RETIRADA");
        printf("\n3- FIM\n");
        printf("\nDigite aqui >>> ");
        scanf("%d", &operacao);

        switch (operacao) {
            case 1:
                printf("\nDigite o valor do deposito: ");
                scanf("%f", &valor);
                saldo += valor;
                break;

            case 2:
                printf("\nDigite o valor da retirada: ");
                scanf("%f", &valor);
                saldo -= valor;
                break;

            case 3:
                break;

            default:
                printf("\nOperacao invalida!\n");
        }

    } while (operacao != 3);

    printf("\nSaldo inicial: %f", saldoinicial);
    printf("\nSaldo atual: %f\n", saldo);

    if (saldo == 0) {
        printf("\nCONTA ZERADA");
    } else if (saldo < 0) {
        printf("\nCONTA ESTOURADA");
    } else {
        printf("\nCONTA PREFERENCIAL");
    }
}
