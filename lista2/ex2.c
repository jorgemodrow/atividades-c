#include <stdio.h>

/* Faça um programa contendo um menu com as seguintes opções:
S - soma
P - produto
U - subtração
D - divisão
Q - sair
Utilize a estrutura switch-case. Quando o usuário teclar Q o programa deve terminar. */

void main() {

    char opcao;

    do {
        printf("S - soma\n");
        printf("P - produto\n");
        printf("U - subtracao\n");
        printf("D - divisao\n");
        printf("Q - sair\n");

        printf("Digite uma opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'S':
                printf("Soma\n");
                break;

            case 'P':
                printf("Produto\n");
                break;

            case 'U':
                printf("Subtracao\n");
                break;

            case 'D':
                printf("Divisao\n");
                break;

            case 'Q':
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");

        }
    } while (opcao != 'Q');
}
