//biblioteca padrao de entrada e saida
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao principal
int main(){
    //variaveis do tipo inteiro
        int numero, i, contador = 0;
    
        // solicita ao usuário que insira um número
        printf("Digite um numero: ");
        scanf("%d", &numero);

        // verifica se o número inserido é par ou ímpar
        if (numero % 2 == 0) {
            printf("O numero %d e par.\n", numero);
        } else {
            printf("O numero %d e impar.\n", numero);
        }

        // utiliza um laço ''for'' para contar quantos números pares existem até o número inserido
        for (i = 2; i <= numero; i++) {
            if (i % 2 == 0) {
                contador++;
            }
        }
    
        // imprime o resultado
        printf("Existem %d numeros pares ate %d.\n", contador, numero);
    
    
    //pausa o programa
    system("pause");
   
    //retorno da funcao
	return 0;
}


