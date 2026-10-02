#include <stdio.h>

int aparicoes(char string[], char caractere) {
    int i,qtd;

    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] == caractere) {
            qtd++;
        }
    }
    return qtd;
}

void main() {
    char texto[100], caracter;
    int qtd;

    printf("Digite um texto => ");
    fgets(texto, sizeof(texto), stdin);

    printf("Digite um caracter => ");
    scanf("%c", &caracter);

    qtd = aparicoes(texto, caracter);
    printf("%d", qtd);
}
