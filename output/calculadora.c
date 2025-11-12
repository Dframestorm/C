//biblioteca padrao de entrada e saida
#include <stdio.h>
#include <stdlib.h>

//funcao principal
int main(){
    //variaveis do tipo float
    float var1, var2, resultado;
    //variavel do tipo inteiro
    int opcao;
    
    //mensagem para o usuario
    printf("Digite a operacao desejada: \n");
    printf("1 - soma\n");
    printf("2 - subtracao\n");
    printf("3 - multiplicacao\n");
    printf("4 - divisao\n");
    scanf("%d", &opcao);

    //mensagem para o usuario
    printf("Digite o valor do primeiro numero: ");

    //entrada de dados
    scanf("%f", &var1);

    printf("Digite o valor do segundo numero: ");
    scanf("%f", &var2);
    
    //mensagem para o usuario
    if (opcao == 1){
        resultado = var1 + var2;
    } else if (opcao == 2) {
        resultado = var1 - var2;
    } else if (opcao == 3) {
        resultado = var1 * var2;
    } else if (opcao == 4) {
        resultado = var1 / var2;
    } else {
        printf("opcao invalida\n");
    }

    printf("o resultado da operacao e: %.1f\n", resultado);
    
    //pausa o programa
    system("pause");
   
    //retorno da funcao
	return 0;
}