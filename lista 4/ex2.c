#include <stdio.h>
#include <string.h>
// L4E2

float maior(float a, float b) {
    float c;

    if (a > b)
        return a;
    else
        return b;
}

void main() {
    float n1,n2,n3;
    n1 = 0; n2 = 0; n3 = 0;

    printf("Digite um numero => ");
    scanf("%f", &n1);
    printf("Digite outro numero => ");
    scanf("%f", &n2);

    n3 = maior(n1,n2);

    printf("Maior numero => %f", n3);
}
