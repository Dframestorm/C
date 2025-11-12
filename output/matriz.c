#include<stdio.h>
#include<stdlib.h>
#define TAM 3

// Função para ler os elementos da matriz
int main() {
    int matriz[3][3];
    int numero1, numero2;
    
    //Leitura da matriz
    printf("Digite os elementos da matriz 3x3:\n");
    for (numero1 = 0; numero1 < 3; numero1++) {
        for (numero2 = 0; numero2 <3; numero2++) {
            printf("Calculo da matriz[%d][%d]: ", numero1, numero2);
            scanf("%d", &matriz[numero1][numero2]);
        }

    }
    //Impressão da matriz 
    printf("\nMatriz resultante multiplado por 5):\n");
        for (numero1 = 0; numero1 < 3; numero1++) {
           for (numero2 = 0; numero2 < 3; numero2++) {
                printf("%d ", matriz[numero1][numero2] * 5);
            }
            printf("\n");
        }
    
    //Pausa o programa
    system("pause");    
    // Finaliza o programa
    return 0;
}

