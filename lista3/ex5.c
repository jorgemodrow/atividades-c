#include <stdio.h>
#include <string.h>

void main() {
    char nomes[40][50], busca[50], opcao;
    int i = 0, encontrados = 0;

    // INSERIR NOMES

    for (i=0; i<=39; i++) {
        printf("Insira o nome do aluno %d => ", i+1);
        fgets(nomes[i], 50, stdin);

        if (nomes[i][strlen(nomes[i]) - 1] == '\n') {
            nomes[i][strlen(nomes[i]) - 1] = '\0';
        }

        printf("\nDeseja inserir mais um nome na lista?\n[s] Sim | [n] Nao");

        do {
            printf("\nDigite aqui a opcao desejada => ");
            scanf(" %c", &opcao);
            getchar();
            printf("\n");

            if (opcao != 's' && opcao != 'n') {
                printf("Opcao invalida!");
            }

        } while (opcao != 's' && opcao != 'n');

        if (opcao == 'n') {
            break;
        }
    }

    // BUSCA

    printf("=== BUSCA DE NOMES ===");

    do {
        printf("\nDigite o nome (ou parte do nome) a ser buscado nessa lista => ");
        fgets(busca, 50, stdin);
        encontrados = 0;

        for (i=0; i<=39; i++) {

            if (busca[strlen(busca) - 1] == '\n') {
                busca[strlen(busca) - 1] = '\0';
            }

            if ( strstr(nomes[i],busca) ) {
                printf("\nNome: %s", nomes[i]);
                printf("\nLinha: %d", i);
                encontrados++;
            }

        }

        if (encontrados == 0) {
            printf("O nome nao consta na matriz!");
        }

        printf("\n\nDeseja buscar mais um nome na lista?\n[s] Sim | [n] Nao");

        do {
            printf("\nDigite aqui a opcao desejada => ");
            scanf(" %c", &opcao);
            getchar();
            printf("\n");

            if (opcao != 's' && opcao != 'n') {
                printf("Opcao invalida!");
            }

        } while (opcao != 's' && opcao != 'n');

    } while (opcao == 's');

}
