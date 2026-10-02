#include <stdio.h>
#include <string.h>

void main() {
    char string[21], reverso[21];
    int tam, i, ir = 0, palindromo = 1;

    printf("Digite uma string (max. 20 caracteres) => ");
    fgets(string,21,stdin);
    string[strcspn(string, "\n")] = '\0';
    tam = strlen(string);

    for ( i = (tam-1) ; i >= 0 ; i--) {
        reverso[ir++] = string[i];
    }
    reverso[ir] = '\0';

    printf("String normal: %s\n", string);
    printf("String reversa: %s\n", reverso);

    for ( i = 0; i < tam; i++) {
        if (string[i] != reverso[i]) {
            palindromo = 0;
            break;
        }
    }

    printf("\n");

    if (palindromo) {
        printf("A string informada e um palindromo!\n");
    } else {
        printf("A string informada nao e um palindromo!\n");
    }
}
