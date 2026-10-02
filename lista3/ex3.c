#include <stdio.h>
#include <string.h>

void main() {

    char s1[21], s2[21], s3[42],opcao,caractere,c1,c2; // máximo é 20 porém tem o /0
    int i,tam,resultado,possub,tamsub,cont = 0;

    printf("Digite uma frase S1 => ");
    fgets(s1,21,stdin);
    s1[strcspn(s1, "\n")] = '\0';

    printf("Selecione uma opcao\n");
    printf("\n(a) Ler uma string S1 (tamanho maximo 20 caracteres);");
    printf("\n(b) Imprimir o tamanho da string S1; ");
    printf("\n(c) Comparar a string S1 com uma nova string S2 fornecida pelo usuario e imprimir o resultado da comparacao;");
    printf("\n(d) Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da concatenacao");
    printf("\n(e) Imprimir a string S1 de forma reversa");
    printf("\n(f) Contar quantas vezes um dado caractere aparece na string S1. Esse caractere desse ser informado pelo usuario;");
    printf("\n(g) Substituir a primeira ocorrencia do caractere C1 da string s1 pelo caractere C2. Os caracteres C1 e C2 serao lidos pelo usuario;");
    printf("\n(h) Verificar se uma string s2 e substring de s1. A string s2 deve ser informada pelo usuario");
    printf("\n(i) Retornar uma substring da string s1. Para isso o usuario deve informar a partir de qual posicao deve ser criada a substring e qual e o tamanho da substring.");

    printf("\n\nDigite a opcao => ");
    scanf("%c", &opcao);
    printf("\n");

    switch(opcao) {

        case 'a':
            printf("String S1: ");

            for ( i = 0; s1[i] != '\0' ; i++) {
                printf("%c", s1[i]);
            }

            break;

        case 'b':
            tam = strlen(s1);
            printf("Tamanho da string S1 => %d", tam);
            break;

        case 'c':
            getchar();
            printf("Digite uma frase S2 => ");
            fgets(s2, 21, stdin);
            s2[strcspn(s2, "\n")] = '\0';

            resultado = strcmp(s1,s2);

            if (resultado == 0) {
                printf("As duas strings sao iguais");
            } else {
                printf("As duas strings sao diferentes");
            }

            break;

        case 'd':
            getchar();
            printf("Digite uma frase S2 => ");
            fgets(s2, 21, stdin);
            s2[strcspn(s2, "\n")] = '\0';

            s3[0] = '\0';
            strcat(s3, s1);
            strcat(s3, " ");
            strcat(s3, s2);

            printf("Nova frase:");
            printf(" %s",s3);
            break;

        case 'e':
            for ( i = (strlen(s1)-1) ; i >= 0 ; i--) {
                printf("%c", s1[i]);
            }
            break;

        case 'f':
            printf("Digite um caractere: ");
            scanf(" %c", &caractere);

            for (i=0 ; i < strlen(s1) ; i++)
                if(s1[i] == caractere)
                    cont++;

            printf("O caracter '%c' apareceu %d vezes na frase", caractere, cont);
            break;

        case 'g':
            printf("Digite o caracter C1 => ");
            scanf(" %c", &c1);
            printf("Digite o caracter C2 => ");
            scanf(" %c", &c2);

            for (i=0 ; i < strlen(s1) ; i++) {
                if(s1[i] == c1) {
                    s1[i] = c2;
                    break;
                }

            }

            printf("%s", s1);
            break;

        case 'h':
            getchar();
            printf("Digite uma frase S2 => ");
            fgets(s2, 21, stdin);
            s2[strcspn(s2, "\n")] = '\0';

            if (strstr(s1,s2) != NULL) {
                printf("S2 e uma substring de S1");
            } else {
                printf("S2 nao e uma substring de S1");
            }
            break;

        case 'i':
            do {
            printf("Digite a posicao inicial da substring de S1: ");
            scanf(" %d", &possub);
            printf("Digite o tamanho desejado para a substring: ");
            scanf(" %d", &tamsub);
            } while (possub >= 0 && tamsub >= 0)

            if ( possub + tamsub <= strlen(s1) ) {
                for ( i = 0; i < tamsub ; i++)
                    s3[i] = s1[possub+i];

                s3[tamsub] = '\0';
                printf("\n%s", s3);
            } else {
                printf("\nNao ha caracteres suficientes");
            }
    }
}
