#include <stdio.h>

#define TAM 8

// Define peças
char tabuleiro[TAM][TAM];

// Inicializa o tabuleiro com posições iniciais simplificadas
void inicializar_tabuleiro() {
    // Preenche tudo com espaço vazio
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';

    // Peças brancas (parte inferior)
    tabuleiro[7][0] = 'T'; // Torre
    tabuleiro[7][1] = 'C'; // Cavalo
    tabuleiro[7][2] = 'B'; // Bispo
    tabuleiro[7][3] = 'D'; // Dama
    tabuleiro[7][4] = 'R'; // Rei
    tabuleiro[7][5] = 'B';
    tabuleiro[7][6] = 'C';
    tabuleiro[7][7] = 'T';
    for (int i = 0; i < TAM; i++)
        tabuleiro[6][i] = 'P'; // Peões

    // Peças pretas (parte superior)
    tabuleiro[0][0] = 't'; // Torre
    tabuleiro[0][1] = 'c'; // Cavalo
    tabuleiro[0][2] = 'b'; // Bispo
    tabuleiro[0][3] = 'd'; // Dama
    tabuleiro[0][4] = 'r'; // Rei
    tabuleiro[0][5] = 'b';
    tabuleiro[0][6] = 'c';
    tabuleiro[0][7] = 't';
    for (int i = 0; i < TAM; i++)
        tabuleiro[1][i] = 'p'; // Peões
}

// Mostra o tabuleiro no console
void imprimir_tabuleiro() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Move uma peça (sem validação de movimento)
void mover_peca(int linha1, int col1, int linha2, int col2) {
    char peca = tabuleiro[linha1][col1];
    if (peca == '.') {
        printf("Não há peça na posição de origem.\n");
        return;
    }

    tabuleiro[linha2][col2] = peca;
    tabuleiro[linha1][col1] = '.';
}

int main() {
    int l1, c1, l2, c2;
    char col_ini, col_fim;
    int lin_ini, lin_fim;

    inicializar_tabuleiro();

    while (1) {
        imprimir_tabuleiro();

        printf("\nDigite a jogada (ex: E2 E4): ");
        scanf(" %c%d %c%d", &col_ini, &lin_ini, &col_fim, &lin_fim);

        c1 = col_ini - 'A';
        l1 = 8 - lin_ini;

        c2 = col_fim - 'A';
        l2 = 8 - lin_fim;

        mover_peca(l1, c1, l2, c2);
    }

    return 0;
}