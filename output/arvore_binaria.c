#include <stdio.h> // Para entrada e saída padrão
#include <stdlib.h> // Para alocação dinâmica de memória

/*-- Bloco 1: Definição das Estruturas --*/
struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
};

/*-- Bloco 2. Função Auxiliar: Criar Novo Nó --*/
struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    if (novoNo == NULL) { 
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL; 
    novoNo->direita = NULL;
    return novoNo;
}

/*-- Bloco 3: Incluir Nó --*/
// Usa recursão para inserir um novo valor na árvore binária de busca
struct No* incluirNo(struct No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    // Navega pela árvore para encontrar a posição correta
    if (valor < raiz->valor) {
        raiz->esquerda = incluirNo(raiz->esquerda, valor);
    // Se o valor for maior, vai para a direita.
    } else if (valor > raiz->valor) { 
        raiz->direita = incluirNo(raiz->direita, valor);
    }
    // Valores iguais não são inseridos, mantendo a propriedade da árvore
    return raiz;
}
/* -- Bloco 4. Função de Busca (Percursos) -- */
// Em ordem Raiz, Esquerda, Direita
void buscarPreOrdem(struct No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor); 
        buscarPreOrdem(raiz->esquerda);
        buscarPreOrdem(raiz->direita);
    }
}
// Em ordem Esquerda, Raiz, Direita
void buscarEmOrdem(struct No* raiz) {
    if (raiz != NULL) {
        buscarEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor); 
        buscarEmOrdem(raiz->direita);
    }
}
// Em ordem Esquerda, Direita, Raiz
// Usado por exemplo para liberar memória da árvore
void buscarPosOrdem(struct No* raiz) {
    if (raiz != NULL) {
        buscarPosOrdem(raiz->esquerda);
        buscarPosOrdem(raiz->direita);
        printf("%d ", raiz->valor); 
    }
}

/*-- Bloco 5 Função: Remover Nó --*/
// Função auxiliar para encontrar o nó com o menor valor na árvore
struct No* encontrarMenor(struct No* no) {
    struct No* atual = no; 
// O menor valor está sempre na extremidade esquerda
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}
// Função para remover um nó com um valor específico da árvore
// Caso base não encontrado
struct No* removerNo(struct No* raiz, int valor) {
// Encontrar o nó a ser removido
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = removerNo(raiz->esquerda, valor);
        // Nó encontrado (valor == raiz->valor)        
    } else if (valor > raiz->valor) {
        raiz->direita = removerNo(raiz->direita, valor);
    } else {
        // Caso 1: Nó com apenas um filho ou nenhum filho
        if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Caso 2: Nó com dois filhos
        // Encontra o sucessor em ordem (o menor nó da subárvore direita)
        struct No* temp = encontrarMenor(raiz->direita);
        // Copia o valor do sucessor para este nó
        raiz->valor = temp->valor;
        // Remove o sucessor
        raiz->direita = removerNo(raiz->direita, temp->valor);
    }
    return raiz;
}

/*-- Bloco 6. Função Auxiliar: Liberar Memória --*/
// Usa a lógica de pós-ordem para liberar a memória da árvore
void liberarArvore(struct No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita); 
        free(raiz);
    }
}

/* -- Bloco 7. Função Principal (Menu) --*/
// 'raiz' é o ponteiro para o nó raiz da árvore binária. Começa vazia (NULL).
int main() {
    struct No* raiz = NULL;
    int opcao, valor;

    do {
        // Exibe o menu
        printf("\n MENU DE OPCOES:\n");
        printf("1. Incluir no\n");
        printf("2. Remover no\n");
        printf("3. Buscar pre-ordem\n");
        printf("4. Buscar em ordem\n");
        printf("5. Buscar pos-ordem\n");
        printf("0. Encerrar\n");
        printf("Opcao [0 para encerrar]: ");
        // Lê a opção do usuário
        scanf("%d", &opcao);
        // Executa a ação correspondente à opção escolhida
        switch (opcao) {
            case 1: //Incluir
                printf("Digite o valor a INCLUIR: ");
                scanf("%d", &valor);
                raiz = incluirNo(raiz, valor);
                printf("Valor %d incluido.\n", valor);
                break;
            case 2: // Remover
                printf("Digite o valor a REMOVER: ");
                scanf("%d", &valor);
                raiz = removerNo(raiz, valor);
                printf("Valor %d removido (se existia).\n", valor);
                break;
            case 3: // Pré-Ordem
                printf("Busca PRE-ORDEM: ");
                buscarPreOrdem(raiz);
                printf("\n");
                break;
            case 4: // Em Ordem
                printf("Busca EM ORDEM: ");
                buscarEmOrdem(raiz);
                printf("\n");
                break; 
            case 5: // Pós-Ordem
                printf("Busca POS-ORDEM: "); 
                buscarPosOrdem(raiz);
                printf("\n");
                break;
            case 0: // Encerrar
                printf("Liberando memoria e encerrando... \n");
                liberarArvore(raiz); 
                break; 
// Opção inválida          
default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0); // Repete até o usuário escolher encerrar

    return 0; // Indica que o programa terminou com sucesso
}