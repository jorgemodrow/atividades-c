#include <stdio.h>

/*
Escreva um programa em C que leia as notas das 2 avaliações normais e a nota da avaliação
optativa. Caso o aluno não tenha feito a optativa deve ser fornecido um valor negativo.
Calcular a média do semestre considerando que a prova optativa substitui a nota mais baixa
entre as 2 primeiras avaliações. Escrever a média e uma mensagem que indique se o aluno foi
aprovado, reprovado ou está em exame.
*/

int main() {

    int n1;
    int n2;
    int nopt;
    float media;

    printf("Sua nota da prova 1: ");
    scanf("%d", &n1);

    printf("\nSua nota da prova 2: ");
    scanf("%d", &n2);

    printf("\nSua nota da prova optativa (caso nao tenha feito, escrever numero negativo): ");
    scanf("%d", &nopt);

    if (nopt >= 0) {
        if (n1 < n2) {
            n1 = nopt;
        } else {
            n2 = nopt;
        }
    }

    media = (float) (n1+n2) / 2;

    printf("\nSua media foi: %.2f\n", media);

    if (media >= 70) {
        printf("Voce foi aprovado!");
    } else if (media >= 40) {
        printf("Voce esta em exame!");
    } else {
        printf("Voce foi reprovado!");
    }
}
