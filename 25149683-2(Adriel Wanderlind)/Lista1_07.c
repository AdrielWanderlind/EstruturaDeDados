#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

void push(No **topo, int n){
    No *novo = malloc(sizeof(No));

    novo->valor=n;
    novo->prox=*topo;

    *topo=novo;
}

void imprimir(No *topo){
    while(topo){
        printf("%d\n",topo->valor);
        topo=topo->prox;
    }
}

void removerImpares(No **topo){

    No *atual=*topo;
    No *ant=NULL;

    while(atual){

        if(atual->valor%2!=0){

            if(ant==NULL)
                *topo=atual->prox;

            else
                ant->prox=atual->prox;

            No *aux=atual;
            atual=atual->prox;

            free(aux);
        }

        else{
            ant=atual;
            atual=atual->prox;
        }
    }
}

void liberar(No **topo){

    while(*topo){

        No *aux=*topo;

        *topo=(*topo)->prox;

        free(aux);
    }
}

int main(){

    srand(time(NULL));

    No *topo=NULL;

    for(int i=0;i<20;i++)
        push(&topo,rand()%116+10);

    removerImpares(&topo);

    printf("Pilha final:\n");

    imprimir(topo);

    liberar(&topo);

    return 0;
}
