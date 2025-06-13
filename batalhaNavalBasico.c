#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Define posições iniciais dos navios diretamente
    int linhaH = 2, colunaH = 1; // navio horizontal
    int linhaV = 5, colunaV = 7; // navio vertical

    // Posiciona navio horizontal (3)
    for (int j = 0; j < NAVIO; j++) {
        tabuleiro[linhaH][colunaH + j] = 3;
    }

    // Posiciona navio vertical (3)
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Exibe o tabuleiro
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
