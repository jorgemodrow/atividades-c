#include <stdio.h>
#include <string.h>
// L4E1

void exclamacoes(int qtd, char saida[][100]) {
    int i, linha;
    for (i = 1; i <= qtd; i++) {
        saida[i-1][0] = '\0';
        for (linha = 1; linha <= i; linha++) {
            strcat(saida[i-1], "!");
        }
    }
}

void main() {
    int num, i;
    char saida[100][100];
    printf("Digite um valor: ");
    scanf("%d", &num);

    exclamacoes(num, saida); // funcao

    for (i = 1; i <= num; i++)
        printf("%s\n", saida[i-1]);
}
