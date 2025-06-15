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

    // Posições fixas dos navios (linha, coluna iniciais)
    // Navio 1: Horizontal (↔)
    int l1 = 1, c1 = 2;

    // Navio 2: Vertical (↓)
    int l2 = 5, c2 = 6;

    // Navio 3: Diagonal ↘ (linha++, coluna++)
    int l3 = 0, c3 = 0;

    // Navio 4: Diagonal ↙ (linha++, coluna--)
    int l4 = 0, c4 = 9;

    // Verificações simples de espaço antes de posicionar

    // Navio 1: horizontal
    int sobrepoe = 0;
    for (int j = 0; j < NAVIO; j++) {
        if (tabuleiro[l1][c1 + j] != 0) sobrepoe = 1;
    }
    if (!sobrepoe) {
        for (int j = 0; j < NAVIO; j++) {
            tabuleiro[l1][c1 + j] = 3;
        }
    }

    // Navio 2: vertical
    sobrepoe = 0;
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[l2 + i][c2] != 0) sobrepoe = 1;
    }
    if (!sobrepoe) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[l2 + i][c2] = 3;
        }
    }

    // Navio 3: diagonal ↘
    sobrepoe = 0;
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[l3 + i][c3 + i] != 0) sobrepoe = 1;
    }
    if (!sobrepoe) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[l3 + i][c3 + i] = 3;
        }
    }

    // Navio 4: diagonal ↙
    sobrepoe = 0;
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[l4 + i][c4 - i] != 0) sobrepoe = 1;
    }
    if (!sobrepoe) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[l4 + i][c4 - i] = 3;
        }
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
