#include <stdio.h>

/* Faça o seguinte programa em C: Solicitar ao usuário que este informe a quantidade de jogos
que foram realizados pela sua equipe no campeonato nacional. Para cada um dos jogos, solicitar a
quantidade de gols marcados e a quantidade de gols sofridos. Exibir quantos jogos a
equipe do usuário ganhou, quantos perdeu e quantos empatou. Ainda para o time do usuário
em questão, exibir a média de gols sofridos e a média de gols marcados por jogo. */

int main()
{
    int qtd;
    int i;
    int golsmarcados;
    int golssofridos;

    int totalgolsmarcados = 0;
    int totalgolssofridos = 0;
    int vitorias = 0;
    int empates = 0;
    int derrotas = 0;

    float mediagolsmarcados;
    float mediagolssofridos;

    printf("Informe a quantidade de jogos que foram realizados pela sua equipe no campeonato nacional: ");
    scanf("%d", &qtd);

    for (i = 1; i <= qtd; i++)
    {
        printf("Para o jogo %d, informe:\n", i);
        printf("Quantos gols sua equipe marcou: ");
        scanf("%d", &golsmarcados);
        printf("Quantos gols sua equipe sofreu: ");
        scanf("%d", &golssofridos);
        printf("\n");
        totalgolsmarcados = totalgolsmarcados + golsmarcados;
        totalgolssofridos = totalgolssofridos + golssofridos;

        if (golsmarcados == golssofridos)
        {
            empates = empates + 1;
        }
        else if (golsmarcados > golssofridos)
        {
            vitorias = vitorias + 1;
        }
        else
        {
            derrotas = derrotas + 1;
        }
    }

    mediagolsmarcados = totalgolsmarcados / qtd;
    mediagolssofridos = totalgolssofridos / qtd;

    printf("\nResultado da sua equipe no campeonato nacional:\n");
    printf("Vitorias: %d\n", vitorias);
    printf("Empates: %d\n", empates);
    printf("Derrotas: %d\n", derrotas);
    printf("Media de gols marcados por jogo: %.2f\n", mediagolsmarcados);
    printf("Media de gols sofridos por jogo: %.2f\n", mediagolssofridos);
}
