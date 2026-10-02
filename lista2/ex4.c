#include <stdio.h>

// Ler 3 números e mostrá-los na ordem crescente.

void main() {
    int n1,n2,n3;
    int ordem1,ordem2,ordem3;

    printf("Digite o numero 1: ");
    scanf("%d", &n1);

    printf("Digite o numero 2: ");
    scanf("%d", &n2);

    printf("Digite o numero 3: ");
    scanf("%d", &n3);

    if (n1 <= n2 && n1 <= n3) {
        ordem1 = n1;

        if (n2 <= n3) {
            ordem2 = n2;
            ordem3 = n3;
        } else {
            ordem2 = n3;
            ordem3 = n2;
        }

    } else if (n2 <= n1 && n2 <= n3) {
        ordem1 = n2;

        if (n1 <= n3) {
            ordem2 = n1;
            ordem3 = n3;
        } else {
            ordem2 = n3;
            ordem3 = n1;
        }

    } else {
        ordem1 = n3;

        if (n1 <= n2) {
            ordem2 = n1;
            ordem3 = n2;
        } else {
            ordem2 = n2;
            ordem3 = n1;
        }
    }

    printf("%d < %d < %d", ordem1, ordem2, ordem3);

}
