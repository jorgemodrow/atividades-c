#include <stdio.h>

/* Elabore uma função ao que receba três notas de um aluno como parâmetros
e uma letra. Se a letra for A, a função deverá calcular a média aritmética das
notas do(a) aluno(a); se for P, deverá calcular a média ponderada, com
pesos 5, 3 e 2 */

/*
OBSERVACAO - LINHAS 17 e 20
Na linguagem C, se você divide um inteiro por outro inteiro (como 3 ou 10), o
resultado sempre será um número inteiro, e as casas decimais serão jogadas fora
Para forçar o C a entender que você quer um resultado com casas decimais (float),
basta colocar um .0 nos divisores
*/

float media(char letra, int nota1, int nota2, int nota3) {
    if (letra == 'A' || letra == 'a') {
        return ( (nota1+nota2+nota3) / 3.0 ); //
    } else {
        return ( (nota1*5 + nota2*3 + nota3*2) / 10.0 );
    }
}

void main() {

    int n1, n2, n3;
    char opcao;
    float resultado;

    printf("Digite a nota da prova 1 => ");
    scanf("%d", &n1);

    printf("Digite a nota da prova 2 => ");
    scanf("%d", &n2);

    printf("Digite a nota da prova 3 => ");
    scanf("%d", &n3);

    printf("\nConsiderando as opcoes:\n\nA = media aritmetica\nP = Media Ponderada\n\nDigite uma opcao => ");
    scanf(" %c", &opcao);

    if (opcao == 'A' || opcao == 'a' || opcao == 'P' || opcao == 'p') {
        resultado = media(opcao,n1,n2,n3);
        printf("\nMedia das notas das 3 provas: %.2f", resultado);
    } else {
        printf("\nOpcao invalida!");
    }
}
