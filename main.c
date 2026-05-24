#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "utils.h"

#define SIZE 3

void desenharGrid(char tabuleiro[SIZE][SIZE], int largura, int altura) {
    int tamanhoX = largura / 3;
    int tamanhoY = altura / 3;
    int index = 0;

    for (int i = tamanhoX; i < largura; i += tamanhoX) {
        DrawLine(i, 0, i, altura, BLACK);
        index++;
    }

    for (int i = tamanhoY; i < altura; i += tamanhoY) {
        DrawLine(0, i, largura, i, BLACK);
    }


    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            char simbolo = tabuleiro[i - 1][j - 1];
            int centroX = 150 * i;
            int centroY = 150 * j;
            int offset = 60;
            
            if (simbolo == 'O') {
                DrawCircleLines(centroX, centroY, 90, BLACK);
            } else if (simbolo == 'X') {
                DrawLine(centroX - offset, centroY - offset, centroX + offset, centroY + offset, BLACK);
                DrawLine(centroX + offset, centroY - offset, centroX - offset, centroY + offset, BLACK);
            }
        }
    }
}

int main() {
    
    char tabuleiro[SIZE][SIZE];
    const int screenWidth = 900;
    const int screenHeight = 900;
    inicializarTabuleiro(tabuleiro);

    InitWindow(screenWidth, screenHeight, "Jogo da Velha");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        desenharGrid(tabuleiro, screenWidth, screenHeight);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
