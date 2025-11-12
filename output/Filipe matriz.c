#include <stdio.h>

int main() {
    int matriz[3][3];  // Declaração da matriz 3x3
    int i, j;

    // Leitura da matriz
    printf("Digite os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Multiplicação dos elementos por 5
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz[i][j] *= 5;
        }
    }

    // Impressão da matriz resultante
    printf("\nMatriz resultante (elementos multiplicados por 5):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%5d", matriz[i][j]);  // Impressão com formatação
        }
        printf("\n");
    }

return 0;
}