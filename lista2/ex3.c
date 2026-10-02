#include <stdio.h>

/*
Ler 2 notas. Calcular a média e verificar:
a. se média >= 7 imprimir APROVADO
b. se 4 <= média < 7 imprimir EXAME
c. se média < 4 imprimir REPROVADO
*/

void main() {
    int n1, n2;
    float media;

    do {
        printf("Digite a nota 1: ");
        scanf("%d", &n1);
        if (n1 < 0 || n1 > 10) {
            printf("A nota varia de 0 a 10!\n");
        }
    } while (n1 < 0 || n1 > 10);

    do {
        printf("Digite a nota 2: ");
        scanf("%d", &n2);
        if (n2 < 0 || n2 > 10) {
            printf("A nota varia de 0 a 10!\n");
        }
    } while (n2 < 0 || n2 > 10);

    media = (n1 + n2) / 2;

    if (media >= 7) {
        printf("\nAPROVADO");
    } else if (media >= 4) {
        printf("\nEXAME");
    } else {
        printf("\nREPROVADO");
    }
}
