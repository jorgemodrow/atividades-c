#include <stdio.h>

/*
Mostrar a tabuada de um nº definido pelo usuário. A tabuada deve começar com 0 e terminar
com 10. Exemplo com o nº 2 :
2*0 = 0
2*1 = 2
.
.
.
2*10 = 20
*/

void main() {

    int numero, i;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    printf("\n");

    for (i = 1; i <= 10; i++) {
        printf("%d*%d = %d\n", numero, i, numero*i);
    }
}
