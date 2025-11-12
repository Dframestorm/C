#include <stdio.h> // Biblioteca padrão de entrada e saída(printf, scanf)
#include <stdlib.h> // Biblioteca padrão para alocação de memória (malloc, free)


/*-- Bloco 1: Definição das Estruturas*/
/*
Estrutura No (nó)
Contém o dado (int)e um ponteiro próximo ao No*/
struct No {
    int dado;
    struct No* proximo;
};

/*Estrutura de Lista encadeadas*/

struct ListaEncadeada{
    struct No* inicio; // ponteiro para o primeiro nó da lista

};

/*-- Bloco 2: Funções das operações*/
//Função para criar uma nova lista vazia
//Ela aloca memória para a esturtura vazia

 struct ListaEncadeada* criar_lista() {
    //Aloca memória para a lista encadeada
    struct ListaEncadeada *lista = (struct ListaEncadeada*) malloc(sizeof(struct ListaEncadeada));

//Alocação for bem sucedida, define o ponteiro ''lista'' como NULL
    if (lista != NULL) {
        lista->inicio = NULL;
    }
    return lista;
}
/*-- Operação 1: Inclusão --*/
//Inserir um novo nó no início da lista
void inserir(struct ListaEncadeada *lista, int dado) {
    //Cria um novo nó
    struct No* novo_no = (struct No*) malloc(sizeof(struct No));
        if (novo_no == NULL) {
            printf("Erro de alocaçao de memorian\n");
            return; // Sai da funcção caso dê erro na alocação
        }
        //2. Definindo novo nó
        novo_no->dado = dado;
        //3. Fazendo o próximo do novo nó apontar para o início atual da lista
        novo_no->proximo = lista->inicio;
        //4. Atualizando o início da lista para o novo nó
        lista->inicio = novo_no;

        printf("Inclusao de %d realizada com sucesso!\n", dado);
    }

//-- Operação 2: Consulta --*/
//Verifica se um determinado existe na lista
//Retorna 1 (true) se encontrar, 0 (false)se não.

int consultar(struct ListaEncadeada* lista, int dado_procurado) {
    struct No* atual = lista->inicio; //Ponteiro para percorrer a lista

    while (atual != NULL) {
        if (atual->dado == dado_procurado) {
            printf("Dado %d encontrado na lista.\n", dado_procurado);
            return 1; // Dado encontrado
        }
        atual = atual->proximo; // Avança para o próximo nó
    }
    printf("Dado %d nao encontrado na lista.\n", dado_procurado);
    return 0; // Dado não encontrado
}

//-- Operação 3: Alteração --
//Procura por dado 'antigo' e substitui por um dado 'novo'
//Retorna 1 (true) se alterar, 0 (false) se não encontrar

int alterar(struct ListaEncadeada* lista, int dado_antigo, int dado_novo) {
    struct No* atual = lista->inicio; // Começar a busca pelo inicio

    while (atual != NULL) {
        if (atual->dado == dado_antigo) {
            atual->dado = dado_novo; // Encontrou e alterou
            printf("Dado '%d' alterado para '%d' com sucesso\n", dado_antigo, dado_novo);
            return 1; // Alteração bem sucedida
        }
        atual = atual->proximo; // Avança para o próximo nó
    }
    printf("Dado '%d' nao encontrado na lista. Alteracao nao realizada.\n", dado_antigo);
    return 0; // Dado antigo não encontrado
}

//-- Operação 4: Remoção --*/
//Remove a *primeira* ocorrência do 'dado_para_remover' da lista
//Retorna 1 (true) se remover, 0 (false) se não encontrar

int remover(struct ListaEncadeada* lista, int dado_para_remover) {
    struct No* atual = lista->inicio;
    struct No* anterior = NULL; // Ponteiro para o nó anterior
    // Percorre a lista procurando o nó
    while (atual != NULL && atual->dado != dado_para_remover) {
        anterior = atual;
        atual = atual->proximo;
    }
    // Se o 'atual' é NULL, o valor não foi encotrado
    if (atual == NULL) {
        printf("Dado '%d' nao encontrado. Remocao nao realizada.\n", dado_para_remover);
        return 0; // Remoção não realizada
    }
    // Caso 1; o nó a ser removido é o *incio* da lista
    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    }
    // Caso 2: o nó a ser removido não é o início
    else {
        // o 'anterior' pula o 'atual' e aponta para o próximo do 'atual'
        anterior->proximo = atual->proximo;  
    }
    // A parte mais importante em C: liberar a memória do nó removido!
    free(atual);
        printf("Dado '%d' foi removido com sucesso.\n", dado_para_remover);
        return 1; // Remoção bem sucedida
}


/*--- FUNÇÃO AUXILIAR: MOSTRAR A LISTA ---*/
//Exibe todos os valores atualmente na lista.
void mostrar_lista(struct ListaEncadeada *lista) {
    if (lista->inicio == NULL) {
        printf("Lista -> (vazia)\n");
        return;
    }
    struct No *atual = lista->inicio;
    printf("Lista -> ");
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// -- Função de Limpeza -- //
//Libera toda a memória alocada para a lista encadeada.
//Isso é ESSENCIAL em c para evitar vazamentos de memória.
void liberar_lista(struct ListaEncadeada* lista) {
    struct No* atual = lista->inicio;
    struct No* proximo_no;
    
    printf("Liberando memoria da lista\n");

    //Percorrre todos os nós e libera a memória nó por nó
    while (atual != NULL) {
        proximo_no = atual->proximo; // Armazena o próximo nó
        printf("Liberando o no com dado %d\n", atual->dado);
        free(atual); // Libera a memória do nó atual
        atual = proximo_no; // Avança para o próximo nó
    }
    //Finalmente, libera a memória da estrutura da lista em si
    free(lista);
    printf("Memoria da lista liberada com sucesso.\n");
}

//Bloco 3: Função principal (main) --*/
//Ponto de entrada do programa
//Onde testamos as funções dal lista.

int main(){
    printf("Iniciado programa de Lista Encadeada em C\n");
    struct ListaEncadeada* minha_lista = criar_lista();
    mostrar_lista(minha_lista);

    printf("\n Incluindo elementos da lista\n");
    inserir(minha_lista, 10);
    inserir(minha_lista, 20);
    inserir(minha_lista, 30);
    //Mostra a lista após as inclusões
    mostrar_lista(minha_lista);

    printf("\n Consultando elementos na lista\n");
    consultar(minha_lista, 20); // Encontrado
    consultar(minha_lista, 90); // Não encontrado

    printf("\n Alterando elementos na lista\n");
    alterar(minha_lista, 20, 25); // Alteração bem sucedida
    mostrar_lista(minha_lista);
    alterar(minha_lista, 90, 100); // Alteração não realizada

    printf("\n Mostrando lista apos remocao\n");
    remover(minha_lista, 99); //Tentativa de remoção não realizada
    remover(minha_lista, 30); // Remoção bem sucedida
    mostrar_lista(minha_lista);
    remover(minha_lista, 10); // Remoção bem sucedida
    mostrar_lista(minha_lista);
    remover(minha_lista, 25); // Remoção bem sucedida
    mostrar_lista(minha_lista); // Lista vazia

    //Limpa a memória alocada para a lista antes de sair do programa
    liberar_lista(minha_lista);

    printf("Programa finalizado\n");
    return 0;
    }
