
#include <stdio.h>

int main() {
    int tabuleiro[10][10];  // tabuleiro 10x10
    int tamanhoNavio = 3;   // cada navio ocupa 3 posições
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3]   = {3, 3, 3};
    int tamanhocone = 5;    // altura do cone

    // 1) Inicializar o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2) Posicionar navio horizontal 
    int linhaH = 9, colunaH = 0;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // 3) Posicionar navio vertical 
    int linhaV = 6, colunaV = 7;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // Navio diagonal ↘ 
    int linhaD1 = 0, colunaD1 = 0;
    for (int i = 0; i < tamanhoNavio; i++) {    
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    // Navio diagonal ↙ 
    int linhaD2 = 0, colunaD2 = 9;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }
 
    // Cone (em forma de triângulo apontando para baixo)
    int origemLinha = 0, origemColuna = 5;
    for (int i = 0; i < tamanhocone; i++) {
        for (int j = -i; j <= i; j++) {  // abre para os lados
            int x = origemLinha + i;
            int y = origemColuna + j;
            if (x >= 0 && x < 3 && y >= 0 && y < 7) {
                tabuleiro[x][y] = 5;
            }
        }
    }
  
     // Cruz
     int origemLinha1 = 5, origemColuna2 = 4;
int tamanhocruz = 1;  // ou outro tamanho que você queira


for (int i = -tamanhocruz; i <= tamanhocruz; i++) {
    int x = origemLinha1 + i;
    int y = origemColuna2;
    if (x >= 0 && x < 10 && y >= 0 && y < 10)  // supondo tabuleiro 10x10
        tabuleiro[x][y] = 5;
}

for (int j = -tamanhocruz; j <= tamanhocruz; j++) {
    int x = origemLinha1;
    int y = origemColuna2 + j;
    if (x >= 0 && x < 10 && y >= 0 && y < 10)
        tabuleiro[x][y] = 5;
}


    // 4) Exibir o tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
