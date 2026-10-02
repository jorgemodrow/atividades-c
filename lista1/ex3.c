#include <stdio.h>

/* Fazer um programa no qual o usuário vai entrando sucessivamente com valores positivos.
Quando o usuário entrar com um valor negativo o programa pára de pedir valores e calcula a
média dos valores já fornecidos. */

void main()
{
    int valor[50];
    int i = 0;
    int soma = 0;
    int qtdvalores = 0;
    float media;

    do {
        printf("Digite um valor: ");
        scanf("%d", &valor[i]);
        qtdvalores = i;
        i += 1;
    } while (valor[qtdvalores] >= 0);

    if (qtdvalores == 0) {
        printf("Erro! Nao foi digitado nenhum numero valido");
    }

    else {
        for (i = 0; i<qtdvalores; i++) {
            soma = soma + valor[i];
        }

        media = (float) soma / qtdvalores;
        printf("Quantidade de valores digitados: %d\n", qtdvalores);
        printf("Media dos valores: %.2f", media);
    }
}
