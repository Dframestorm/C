#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero >= 10 && numero <= 20) {
        printf("O numero %d esta entre 10 e 20\n", numero);
    } else {
        printf("O numero %d nao esta entre 10 e 20\n", numero);
    }
    //pausa o programa
    system("pause");

    //retorno da funcao
    return 0;
}