#include <stdio.h>
#include <string.h>
#include <ctype.h>

void minusculas(char tex[]) {
    int i;
    for (i = 0; tex[i] != '\0'; i++) {
        tex[i] = tolower(tex[i]);
    }
}

void main() {
    char texto[100];

    printf("Digite um texto para converter para minúsculo => ");
    fgets(texto, sizeof(texto), stdin);

    texto[strcspn(texto, "\n")] = '\0';

    minusculas(texto);

    printf("Resultado: %s\n", texto);
}
