#include <stdio.h>

/* Escrever um programa que declara três variáveis int (a, b e c). Ler um valor maior que zero para
cada variável (se o valor digitado não é válido, mostrar mensagem e ler novamente). Exibe o
menor valor lido multiplicado pelo maior e o maior valor dividido pelo menor. */

void main() {
    int a,b,c,i,ordem1,ordem2,ordem3,valor1,valor2;

    do {
        printf("Digite o numero A: ", i);
        scanf("%d", &a);

        if (a <= 0) {
            printf("\nO numero precisa ser maior do que zero!\n");
        }
    } while (a <= 0);

    do {
        printf("Digite o numero B: ", i);
        scanf("%d", &b);

        if (b <= 0) {
            printf("\nO numero precisa ser maior do que zero!\n");
        }
    } while (b <= 0);

    do {
        printf("Digite o numero C: ", i);
        scanf("%d", &c);

        if (c <= 0) {
            printf("\nO numero precisa ser maior do que zero!\n");
        }
    } while (c <= 0);

    if (a <= b && a <= c) {
        ordem1 = a;

        if (b <= c) {
            ordem2 = b;
            ordem3 = c;
        } else {
            ordem2 = c;
            ordem3 = b;
        }

    } else if (b <= a && b <= c) {
        ordem1 = b;

        if (a <= c) {
            ordem2 = a;
            ordem3 = c;
        } else {
            ordem2 = c;
            ordem3 = a;
        }

    } else {
        ordem1 = c;

        if (a <= b) {
            ordem2 = a;
            ordem3 = b;
        } else {
            ordem2 = b;
            ordem3 = a;
        }
    }

    valor1 = ordem1 * ordem3;
    printf("Menor valor lido multiplicado pelo maior: %d\n", valor1);

    valor2 = ordem3 / ordem1;
    printf("Maior valor lido dividido pelo menor: %d", valor2);
}
