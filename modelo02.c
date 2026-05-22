#include <stdio.h>

int main() {
    // Contagem de elementos pares e ímpares
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int even = 0, odd = 0;
    int i, j;

    // Loop externo para as linhas
    for(i = 0; i < 3; i++) {
        // Loop interno para as colunas
        for(j = 0; j < 3; j++) {
            if(matrix[i][j] % 2 == 0) {
                // Incrementa o contador de pares
                even++;
            } else {
                // Incrementa o contador de ímpares
                odd++;
            }
        }
    }

    // Impressão da matriz
    printf("Matriz:\n");
    // Loop para imprimir cada linha
    for(i = 0; i < 3; i++) {
        // Loop para imprimir cada coluna
        for(j = 0; j < 3; j++) {
            printf("%3d ", matrix[i][j]); // %3d faz justificar a impressao dos numeros
        }
        printf("\n");
    }

    // Impressão dos resultados
    printf("Pares: %d\n", even);
    printf("Ímpares: %d\n", odd);

    return 0;
}