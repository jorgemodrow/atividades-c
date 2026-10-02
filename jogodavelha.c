#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char velha[3][3];
int opcao, adversario, niveljogada;

int verifica_ganhador(char jog) {
    // Checa linhas e colunas
    for(int i = 0; i < 3; i++) {
        if(velha[i][0] == jog && velha[i][1] == jog && velha[i][2] == jog) return 1;
        if(velha[0][i] == jog && velha[1][i] == jog && velha[2][i] == jog) return 1;
    }
    // Checa diagonais
    if(velha[0][0] == jog && velha[1][1] == jog && velha[2][2] == jog) return 1;
    if(velha[0][2] == jog && velha[1][1] == jog && velha[2][0] == jog) return 1;

    return 0; // Retorna 0 caso não haja vitória
}

int jogada_usuario(int lin, int col, char jog) {
    if (lin < 0 || lin > 2 || col < 0 || col > 2) {
        return 1; // 1 - posição informada é inválida (fora da matriz)
    }
    if (velha[lin][col] != ' ') {
        return 2; // 2 - posição informada já está preenchida
    }
    velha[lin][col] = jog;
    return 0; // 0 - se a jogada é válida
}

void jogada_basico(char jog) {
    int l, c;
    // O nível básico apenas escolhe uma posição vazia aleatória
    do {
        l = rand() % 3;
        c = rand() % 3;
    } while(velha[l][c] != ' ');
    velha[l][c] = jog;
}

void jogada_intermediario(char jog) {
    // O nível intermediário simula as jogadas: se puder ganhar na próxima, ele ataca.
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(velha[i][j] == ' ') {
                velha[i][j] = jog;
                if(verifica_ganhador(jog)) return; // Se ganhar com essa jogada, finaliza
                velha[i][j] = ' '; // Se não, desfaz a simulação
            }
        }
    }
    // Se não houver ataque para vencer imediatamente, faz uma jogada aleatória
    jogada_basico(jog);
}

void jogada_avancado(char jog) {
    char adv;

    // Identifica o símbolo do oponente
    if (jog == 'X') {
        adv = 'O';
    } else {
        adv = 'X';
    }

    // 1º Passo: Tenta ganhar
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(velha[i][j] == ' ') {
                velha[i][j] = jog;
                if(verifica_ganhador(jog)) return;
                velha[i][j] = ' ';
            }
        }
    }
    // 2º Passo: Tenta bloquear o adversário se ele for ganhar na próxima jogada
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(velha[i][j] == ' ') {
                velha[i][j] = adv;
                if(verifica_ganhador(adv)) {
                    velha[i][j] = jog; // Se o oponente ganharia aqui, preenche e bloqueia
                    return;
                }
                velha[i][j] = ' ';
            }
        }
    }
    // 3º Passo: Se não puder atacar nem bloquear, prioriza o centro
    if(velha[1][1] == ' ') {
        velha[1][1] = jog;
        return;
    }
    // 4º Passo: Se o centro estiver ocupado, joga em um espaço vazio aleatório
    jogada_basico(jog);
}

void jogada_computador(char jog, int nivel) {
    if (nivel == 1) {
        jogada_basico(jog);
    } else if (nivel == 2) {
        jogada_intermediario(jog);
    } else if (nivel == 3) {
        jogada_avancado(jog);
    }
}

int menu() {
    printf("Voce deseja jogar contra:\n\n[1] Computador\n[2] Outro usuario\n");

    while (1) {
        printf("\nDigite sua opcao: ");
        scanf("%d", &opcao);
        if (opcao == 1 || opcao == 2) {
            break;
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }

    if (opcao == 1) {
        printf("\nEscolha o nivel da jogada do computador:\n\n[1] Basico\n[2] Intermediario\n[3] Avancado\n");
        while (1) {
            printf("\nDigite o nivel: ");
            scanf("%d", &niveljogada);
            if (niveljogada >= 1 && niveljogada <= 3) {
                break;
            } else {
                printf("Opção invalida! Tente novamente.\n");
            }
        }
    }
    return opcao;
}

void escolha_simb(char *jog1, char *jog2) {
    char escolha;

    while (1) {
        printf("\nJogador 1, escolha seu simbolo [X] ou [O]: ");
        scanf(" %c", &escolha);
        if (escolha == 'X' || escolha == 'x') {
            *jog1 = 'X';
            *jog2 = 'O';
            break;
        } else if (escolha == 'O' || escolha == 'o' || escolha == '0') {
            *jog1 = 'O';
            *jog2 = 'X';
            break;
        } else {
            printf("Opção invalida! Escolha apenas X ou O.\n");
        }
    }
}

void inicializa_velha() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            velha[i][j] = ' ';
        }
    }
}

void imprime_velha() { // Desenhar a matriz no console
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", velha[i][0], velha[i][1], velha[i][2]);
        if (i < 2) { printf("---|---|---\n"); }
    }
    printf("\n");
}

void main() {
    char jogador1, jogador2;
    int linha, coluna, status;
    int jogadas = 0;       // Conta até 9 para identificar empate (velha)
    int turno = 1;         // 1 = Vez do Jogador 1 | 2 = Vez do Jogador 2/PC
    int vencedor = 0;      // 0 = Ninguém | 1 = Jogador 1 | 2 = Jogador 2/PC

    srand(time(NULL));
    inicializa_velha();
    adversario = menu();
    escolha_simb(&jogador1, &jogador2);

    // O loop principal do jogo
    while (jogadas < 9 && vencedor == 0) {
        imprime_velha();

        if (turno == 1) {
            // TURNO DO JOGADOR 1
            printf("\n--- Vez do JOGADOR 1 (%c) ---\n", jogador1);
            do {
                printf("Digite a linha e a coluna (0 a 2) separadas por espaco: ");
                scanf("%d %d", &linha, &coluna);

                status = jogada_usuario(linha, coluna, jogador1);
                if (status == 1) printf("Posicao invalida! Tente novamente.\n");
                else if (status == 2) printf("Esta posicao ja esta ocupada! Tente novamente.\n");
            } while (status != 0); // Repete até a jogada ser válida

            if (verifica_ganhador(jogador1)) {
                vencedor = 1;
            } else {
                turno = 2; // Passa a vez
            }

        } else {
            // TURNO DO JOGADOR 2
            printf("\n--- Vez do JOGADOR 2 (%c) ---\n", jogador2);

            if (adversario == 1) {  // Se for contra o PC
                printf("Computador jogando...\n");
                jogada_computador(jogador2, niveljogada);

            } else { // Se for contra outro humano
                do {
                    printf("Digite a linha e a coluna (0 a 2) separadas por espaco: ");
                    scanf("%d %d", &linha, &coluna);

                    status = jogada_usuario(linha, coluna, jogador2);
                    if (status == 1) printf("Posicao invalida! Tente novamente.\n");
                    else if (status == 2) printf("Esta posicao ja esta ocupada! Tente novamente.\n");
                } while (status != 0);
            }

            if (verifica_ganhador(jogador2)) {
                vencedor = 2;
            } else {
                turno = 1; // Passa a vez de volta para o J1
            }
        }
        jogadas++; // Incrementa o total de jogadas
    }

    // RESULTADO
    imprime_velha();
    printf("\n=== FIM DE JOGO ===\n");
    if (vencedor == 1) {
        printf("Parabens! O JOGADOR 1 (%c) venceu!\n", jogador1);
    } else if (vencedor == 2) {
        if (adversario == 1) printf("O COMPUTADOR (%c) venceu!\n", jogador2);
        else printf("Parabens! O JOGADOR 2 (%c) venceu!\n", jogador2);
    } else {
        printf("Deu velha! Empate.\n");
    }
}
