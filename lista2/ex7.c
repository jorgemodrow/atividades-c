#include <stdio.h>

/*
Existem 2 candidatos para uma vaga no Senado e 20 eleitores, cada eleitor tem direito a 1 voto,
onde este pode ser:
0 - voto em branco
1 - candidato 1
2 - candidato 2
outro - voto nulo
Fazer um programa que detecte a contagem de votos, i e, quantos brancos, nulos, candidato
1 e 2.
*/

void main()
{
    char voto;
    int cand1 = 0;
    int cand2 = 0;
    int nulo = 0;
    int branco = 0;
    int i;

    for (i = 1; i <= 20; i++)
    {
        printf("\nEleitor %d\n", i);
        printf("0 - voto em branco\n");
        printf("1 - candidato 1\n");
        printf("2 - candidato 2\n");
        printf("outro caractere - voto nulo\n");

        printf("Digite o voto: ");
        scanf(" %c", &voto);

        switch (voto)
        {
            case '0':
                branco += 1;
                break;

            case '1':
                cand1 += 1;
                break;

            case '2':
                cand2 += 1;
                break;

            default:
                nulo += 1;
        }
    }

    printf("\nVotos:\n");
    printf("Candidato 1: %d\n", cand1);
    printf("Candidato 2: %d\n", cand2);
    printf("Brancos: %d\n", branco);
    printf("Nulos: %d\n", nulo);
}
