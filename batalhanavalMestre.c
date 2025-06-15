#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HABIL 5

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Horizontal
    for (int j = 0; j < 3; j++)
        tabuleiro[1][2 + j] = 3;

    // Vertical
    for (int i = 0; i < 3; i++)
        tabuleiro[5 + i][6] = 3;

    // Diagonal ↘
    for (int i = 0; i < 3; i++)
        tabuleiro[i][i] = 3;

    // Diagonal ↙
    for (int i = 0; i < 3; i++)
        tabuleiro[i][9 - i] = 3;
}

void criarMatrizCone(int matriz[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            matriz[i][j] = (i >= j - 2 && i >= 2 - j) ? 1 : 0;
        }
    }
}

void criarMatrizCruz(int matriz[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            matriz[i][j] = (i == TAM_HABIL / 2 || j == TAM_HABIL / 2) ? 1 : 0;
        }
    }
}

void criarMatrizOctaedro(int matriz[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            matriz[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int matriz[TAM_HABIL][TAM_HABIL], int origemX, int origemY) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (matriz[i][j] == 1) {
                int x = origemX - 2 + i;
                int y = origemY - 2 + j;

                if (x >= 0 && x < TAM && y >= 0 && y < TAM && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5; // marca área de efeito
                }
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            switch (tabuleiro[i][j]) {
                case 0: printf("~ "); break; // água
                case 3: printf("N "); break; // navio
                case 5: printf("* "); break; // área de habilidade
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HABIL][TAM_HABIL], cruz[TAM_HABIL][TAM_HABIL], octaedro[TAM_HABIL][TAM_HABIL];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Octaedro

    exibirTabuleiro(tabuleiro);

    return 0;
}
