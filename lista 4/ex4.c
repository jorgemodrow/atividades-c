#include <stdio.h>

// Faça uma função que receba 3 números inteiros como parâmetro,
// representando horas, minutos e segundos, e os converta em segundos.

int qtdSegundos(int horas, int minutos, int segundos) {
    minutos += horas*60;
    segundos += minutos*60;
    return segundos;
}

void main() {
    int h,m,s;
    printf("Digite a quantidade de horas => ");
    scanf("%d", &h);
    printf("Digite a quantidade de minutos => ");
    scanf("%d", &m);
    printf("Digite a quantidade de segundos => ");
    scanf("%d", &s);

    s = qtdSegundos(h,m,s);
    printf("Quantidade de segundos total => %d", s);
}
