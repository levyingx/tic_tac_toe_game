#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utils.h"

#define SIZE 3

int main() {
    int linha, coluna, jogador, jogadas, input;
    bool ganhou = false;
    char tabuleiro[SIZE][SIZE];

    do {
        jogador = 1;
        ganhou = false;
        jogadas = 0;

        inicializarTabuleiro(tabuleiro);

        do {            
            imprimirTabuleiro(tabuleiro);

            while (true) {
                printf("\nJOGADOR 1 = O\nJOGADOR 2 = X\n");
                lerEntrada(jogador, &linha, &coluna);

                if (!validarEntrada(tabuleiro, linha, coluna)) {
                    printf("Os valores devem ser entre 0 e 2.\n");
                    lerEntrada(jogador, &linha, &coluna);                    
                } else {
                    break;
                }
            }

            jogador = jogar(tabuleiro, linha, coluna, jogador);
            jogadas++;
            ganhou = verificarEstado(tabuleiro);
        } while (!ganhou && jogadas < 9);

        imprimirTabuleiro(tabuleiro);

        if (!ganhou) {
            printf("\nO jogo finalizou sem ganhador!\n");
        }

        printf("\nDigite 1 para jogar novamente: \n");
        scanf("%d", &input);

    } while(input == 1);
    return 0;
}