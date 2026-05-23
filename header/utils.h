#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

/**
 * @brief Preenche o tabuleiro com whitespaces.
 * 
 * @param tabuleiro Matriz que representa o tabuleiro.
 */
void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]);

/**
 * @brief Imprime o tabuleiro no terminal.
 * 
 * @param tabuleiro Matriz que representa o tabuleiro.
 */
void imprimirTabuleiro(char tabuleiro[SIZE][SIZE]);
  
/**
 * @brief Solicita, lê e armazena as coordenadas da jogada do usuário. 
 * 
 * @param jogador Valor que representa qual jogador tem a vez.
 * @param linha Índice da linha.
 * @param coluna Índice da coluna.
 */
void lerEntrada(int jogador, int *linha, int *coluna);

/**
 * @brief Verifica se as coordenadas informadas estão dentro do intervalo.
 *
 * @param tabuleiro Matriz que representa o tabuleiro do jogo.
 * @param linha Índice da linha.
 * @param coluna Índice da coluna.
 * 
 * @returns Verdadeiro se a entrada é válida ou falso, caso contrário.
 */
bool validarEntrada(char tabuleiro[SIZE][SIZE], int linha, int coluna);

/**
 * @brief Modifica o tabuleiro original com a jogada inserida pelo usuário. 
 * 
 * @param tabuleiro Matriz que representa o tabuleiro.
 * @param linha Índice da linha.
 * @param coluna Índice da coluna.
 * @param jogador Valor que representa qual jogador tem a vez.
 * 
 * @returns Qual jogador tem a vez.
 */
int jogar(char tabuleiro[SIZE][SIZE], int linha, int coluna, int jogador);

/**
 * @brief Verifica se há três símbolos iguais em qualquer linha do tabuleiro. 
 * 
 * @param tabuleiro Matriz que representa o tabuleiro.
 * @returns Verdadeiro se o jogo foi encerrado, falso caso contrário.
 */
bool verificarLinhas(char tabuleiro[SIZE][SIZE]);

/**
 * @brief Verifica se há três símbolos iguais em qualquer coluna do tabuleiro.
 * 
 * @param tabuleiro Matriz que representa o tabuleiro.
 * @returns Verdadeiro se o jogo foi encerrado, falso caso contrário.
 */
bool verificarColunas(char tabuleiro[SIZE][SIZE]);

/**
 * @brief Verifica se há três símbolos iguais nas diagonais do tabuleiro.
 *
 * @param tabuleiro Matriz que representa o tabuleiro do jogo.
 * @returns Verdadeiro se o jogo foi encerrado, falso caso contrário.
 */
bool verificarDiagonais(char tabuleiro[SIZE][SIZE]);

/**
 * @brief Verifica se o estado atual do tabuleiro possui um vencedor.
 *
 * @param tabuleiro Tabuleiro do jogo da velha.
 * @return true Se houver vitória em linhas, colunas ou diagonais.
 * @return false Caso contrário.
 */
bool verificarEstado(char tabuleiro[SIZE][SIZE]);

#endif