#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {

    char data[11];
    int dia,mes,ano;

    printf("Digite a data no formato 'DD/MM/AAAA'");
    printf("\n\nDigite aqui => ");
    fgets(data, 11, stdin);

    if (
    isdigit(data[0]) &&
    isdigit(data[1]) &&
    data[2] == '/'   &&
    isdigit(data[3]) &&
    isdigit(data[4]) &&
    data[5] == '/'   &&
    isdigit(data[6]) &&
    isdigit(data[7]) &&
    isdigit(data[8]) &&
    isdigit(data[9]) ) {

        dia = ( data[0] - '0' ) * 10 + ( data[1] - '0' ); // - '0 ' converte corretamente para inteiro

        mes = ( data[3] - '0' ) * 10 + ( data[4] - '0' );

        ano = ( data[6] - '0' ) * 1000 + ( data[7] - '0' ) * 100 + ( data[8] - '0' ) * 10 + ( data[9] - '0' );

        printf("Dia: %d \nMes: %d \nAno: %d", dia,mes,ano);
    } else {
        printf("Invalido");
    }
}
