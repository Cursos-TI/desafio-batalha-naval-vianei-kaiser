#include <stdio.h>

// Definição do tamanho do tabuleiro
#define TAMANHO 10

// Constantes para identificar os elementos no tabuleiro
#define VAZIO 0
#define NAVIO 3
#define AFETADO 1

int main() {
    // Inicializa o tabuleiro 10x10 com zeros (posições vazias)
    int tabuleiro[TAMANHO][TAMANHO] = {VAZIO};

    // ==========================================
    // 1. POSICIONAMENTO DOS NAVIOS (Novato e Aventureiro)
    // ==========================================
    
    // Navio 1: Horizontal (Tamanho 3) - Linha 1, Colunas 2, 3, 4
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;
    tabuleiro[1][4] = NAVIO;

    // Navio 2: Vertical (Tamanho 3) - Coluna 7, Linhas 3, 4, 5
    tabuleiro[3][7] = NAVIO;
    tabuleiro[4][7] = NAVIO;
    tabuleiro[5][7] = NAVIO;

    // Navio 3: Diagonal Principal Escalonada (Tamanho 3) - Linhas 7 a 9
    tabuleiro[7][1] = NAVIO;
    tabuleiro[8][2] = NAVIO;
    tabuleiro[9][3] = NAVIO;

    // Navio 4: Diagonal Secundária Escalonada (Tamanho 3) - Linhas 7 a 9
    tabuleiro[7][8] = NAVIO;
    tabuleiro[8][7] = NAVIO;
    tabuleiro[9][6] = NAVIO;


    // ==========================================
    // 2. EXIBIÇÃO DAS COORDENADAS (Requisito Novato)
    // ==========================================
    printf("========== COORDENADAS DOS NAVIOS ==========\n");
    printf("Navio Horizontal (Linha 1): Coordenadas (1,2), (1,3), (1,4)\n");
    printf("Navio Vertical (Coluna 7): Coordenadas (3,7), (4,7), (5,7)\n");
    printf("Navio Diagonal 1: Coordenadas (7,1), (8,2), (9,3)\n");
    printf("Navio Diagonal 2: Coordenadas (7,8), (8,7), (9,6)\n\n");


    // ==========================================
    // 3. MATRIZES DE HABILIDADES ESPECIAIS (Mestre)
    // ==========================================
    
    // Matriz de Habilidade: CONE (Matriz 3x5)
    int habilidadeCone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    // Matriz de Habilidade: OCTAEDRO (Matriz 3x5)
    int habilidadeOctaedro[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Matriz de Habilidade: CRUZ (Matriz 3x5)
    int habilidadeCruz[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };


    // ==========================================
    // 4. APLICAÇÃO DAS HABILIDADES NO TABULEIRO
    // ==========================================
    
    // Vamos aplicar a habilidade CONE a partir da linha 3, coluna 1 do tabuleiro principal
    int origemLinhaCone = 3;
    int origemColunaCone = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            // Se a matriz de habilidade tiver o valor 1, aplica no tabuleiro
            if (habilidadeCone[i][j] == 1) {
                tabuleiro[origemLinhaCone + i][origemColunaCone + j] = AFETADO;
            }
        }
    }

    // Vamos aplicar a habilidade CRUZ a partir da linha 3, coluna 4 do tabuleiro principal
    // (Nota: se sobrepor um navio, a habilidade vai marcar 1 como área afetada)
    int origemLinhaCruz = 3;
    int origemColunaCruz = 4;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidadeCruz[i][j] == 1) {
                tabuleiro[origemLinhaCruz + i][origemColunaCruz + j] = AFETADO;
            }
        }
    }


    // ==========================================
    // 5. EXIBIÇÃO DO TABULEIRO COMPLETO (Aventureiro/Mestre)
    // ==========================================
    printf("========== TABULEIRO COMPLETO (10x10) ==========\n");
    printf("Legenda: 0 = Vazio | 3 = Navio | 1 = Área Afetada por Habilidade\n\n");
    
    // Loops aninhados para percorrer e exibir a matriz
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Quebra de linha ao fim de cada linha da matriz
    }

    return 0;
}