#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = ' ';
        }    
    }
}

void imprimirTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("\n\n");
    printf("     0   1   2\n");
    printf("   +---+---+---+\n");

    for (int i = 0; i < SIZE; i++) {
        printf(" %d | %c | %c | %c |\n", i, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        printf("   +---+---+---+\n");
    }
    printf("\n");
}

void lerEntrada(int jogador, int *linha, int *coluna) {
    printf("\nJOGADOR %d: Digite a linha e a coluna que deseja jogar: ", jogador);
    scanf("%d%d", linha, coluna);
}

bool validarEntrada(char tabuleiro[SIZE][SIZE], int linha, int coluna) {
    if (linha == -1 || coluna == -1) {
        return false;
    } else if (linha < 0 || linha > SIZE - 1) {
        return false;
    } else if (coluna < 0 || coluna > SIZE - 1) {
        return false;
    } else if (tabuleiro[linha][coluna] != ' ') {
        return false;
    } 

    return true;
}

int jogar(char tabuleiro[SIZE][SIZE], int linha, int coluna, int jogador) {
    if (jogador == 1) {
        tabuleiro[linha][coluna] = 'O';
        return 2;
    } else {
        tabuleiro[linha][coluna] = 'X';
        return 1;
    }
}

bool verificarLinhas(char tabuleiro[SIZE][SIZE]) {
    if(tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O' ||
        tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O' ||
        tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O'){
        printf("\nParabéns! O jogador 1 venceu por linha!\n");
        return true;
    }

    if(tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X' ||
        tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X' ||
        tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X'){
        printf("\nParabéns! O jogador 2 venceu por linha!\n");
        return true;
    }

    return false;
}

bool verificarColunas(char tabuleiro[SIZE][SIZE]) {
    if(tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O' ||
        tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O' ||
        tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O'){
        printf("\nParabens! O jogador 1 venceu por coluna!\n");
        return true;
    }
    if(tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X' ||
        tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X' ||
        tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X'){
        printf("\nParabens! O jogador 2 venceu por coluna!\n");
        return true;
    }

    return false;
}

bool verificarDiagonais(char tabuleiro[SIZE][SIZE]) {
    if(tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'){
        printf("\nParabens! O jogador 1 venceu na diag. principal!\n");
        return true;
    }
    if(tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X'){
        printf("\nParabens! O jogador 2 venceu na diag. principal!\n");
        return true;
    }

    if(tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O'){
        printf("\nParabens! O jogador 1 venceu na diag. secindaria!\n");
        return true;
    }
    if(tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X'){
        printf("\nParabens! O jogador 2 venceu na diag. secundaria!\n");
        return true;
    }

    return false;
}

bool verificarEstado(char tabuleiro[SIZE][SIZE]) {
    if (verificarLinhas(tabuleiro)) return true;
    if (verificarColunas(tabuleiro)) return true;
    if (verificarDiagonais(tabuleiro)) return true;
    return false;
}