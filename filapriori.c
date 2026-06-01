#include <stdlib.h>
#include <stdio.h>

typedef struct apelido{
    int dado;
    struct apelido *proximo;
} no;

// FILA 1 (GERAL)
no *inicio1 = NULL;
no *final1 = NULL;

// FILA 2 (PRIORIDADE)
no *inicio2 = NULL;
no *final2 = NULL;

// Protótipos
void enqueue(int item);
void dequeue();
void dequeueFila2();
void separarFilas();
void imprimirFila1();
void imprimirFila2();
int entrada_dados();

//--------------------------------------------------
int main(){

    int n, opcao;

    do{
        system("cls");

        printf("\n=========== FILA DE PRIORIDADE ===========");
        printf("\n1. Enfileirar Fila1 (geral)");
        printf("\n2. Desenfileirar Fila1 (geral)");
        printf("\n3. Desenfileirar Fila Prioridade");
        printf("\n4. Separar Filas");
        printf("\n5. Imprimir Fila1 (Geral)");
        printf("\n6. Imprimir Fila Prioridade");
        printf("\n7. Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                n = entrada_dados();
                enqueue(n);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                dequeueFila2();
                break;

            case 4:
                separarFilas();
                break;

            case 5:
                imprimirFila1();
                break;

            case 6:
                imprimirFila2();
                break;

            case 7:
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                system("pause");
        }

    }while(opcao != 7);

    return 0;
}

//--------------------------------------------------
void enqueue(int item){

    printf("\nEnfileirando...\n");

    no *novo = (no*)malloc(sizeof(no));

    novo->dado = item;
    novo->proximo = NULL;

    // Fila vazia
    if(inicio1 == NULL){
        inicio1 = final1 = novo;
    }

    // Pessoa prioritária (60 anos ou mais)
    else if(item >= 60){

        // Entra no início se for mais velha
        if(inicio1->dado < 60 || item > inicio1->dado){

            novo->proximo = inicio1;
            inicio1 = novo;
        }
        else{

            no *atual = inicio1;

            while(atual->proximo != NULL &&
                  atual->proximo->dado >= 60 &&
                  atual->proximo->dado >= item){

                atual = atual->proximo;
            }

            novo->proximo = atual->proximo;
            atual->proximo = novo;

            if(novo->proximo == NULL){
                final1 = novo;
            }
        }
    }

    // Pessoa sem prioridade
    else{

        final1->proximo = novo;
        final1 = novo;
    }

    printf("Pessoa de %d anos inserida com sucesso!\n", item);
    system("pause");
}

//--------------------------------------------------
void dequeue(){

    if(inicio1 == NULL){

        printf("\nFila Geral vazia!\n");
    }
    else{

        no *temp = inicio1;

        inicio1 = inicio1->proximo;

        printf("\nPessoa de %d anos removida da Fila Geral.\n",
               temp->dado);

        free(temp);

        if(inicio1 == NULL){
            final1 = NULL;
        }
    }

    system("pause");
}

//--------------------------------------------------
void dequeueFila2(){

    if(inicio2 == NULL){

        printf("\nFila Prioridade vazia!\n");
    }
    else{

        no *temp = inicio2;

        inicio2 = inicio2->proximo;

        printf("\nPessoa de %d anos removida da Fila Prioridade.\n",
               temp->dado);

        free(temp);

        if(inicio2 == NULL){
            final2 = NULL;
        }
    }

    system("pause");
}

//--------------------------------------------------
void separarFilas(){

    no *atual = inicio1;
    no *anterior = NULL;

    while(atual != NULL){

        if(atual->dado >= 60){

            no *prioritario = atual;

            if(anterior == NULL){
                inicio1 = atual->proximo;
            }
            else{
                anterior->proximo = atual->proximo;
            }

            atual = atual->proximo;

            prioritario->proximo = NULL;

            // Inserir na fila 2
            if(inicio2 == NULL){
                inicio2 = final2 = prioritario;
            }
            else{
                final2->proximo = prioritario;
                final2 = prioritario;
            }
        }
        else{

            anterior = atual;
            atual = atual->proximo;
        }
    }

    if(inicio1 == NULL){
        final1 = NULL;
    }

    printf("\nPessoas prioritarias movidas para a Fila Prioridade.\n");
    system("pause");
}

//--------------------------------------------------
void imprimirFila1(){

    no *aux = inicio1;

    printf("\n========== FILA GERAL ==========\n");

    if(aux == NULL){

        printf("Fila vazia!\n");
    }
    else{

        while(aux != NULL){

            printf("%d", aux->dado);

            if(aux->proximo != NULL){
                printf(" -> ");
            }

            aux = aux->proximo;
        }

        printf("\n");
    }

    system("pause");
}

//--------------------------------------------------
void imprimirFila2(){

    no *aux = inicio2;

    printf("\n======= FILA PRIORIDADE =======\n");

    if(aux == NULL){

        printf("Fila vazia!\n");
    }
    else{

        while(aux != NULL){

            printf("%d", aux->dado);

            if(aux->proximo != NULL){
                printf(" -> ");
            }

            aux = aux->proximo;
        }

        printf("\n");
    }

    system("pause");
}

//--------------------------------------------------
int entrada_dados(){

    int valor;

    printf("\nQual a idade da pessoa que ira entrar na fila? ");
    scanf("%d", &valor);

    return valor;
}
