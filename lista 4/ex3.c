#include <stdio.h>
#include <string.h>

int verificar(float a) {

    if (a > 0) {
        return 1;
    } else if (a < 0) {
        return -1;
    } else {
        return 0;
    }
}

void main() {
    int res;
    float num;

    printf("Digite um numero => ");
    scanf("%f", &num);

    res = verificar(num);

    printf("Return: %d", res);
}
