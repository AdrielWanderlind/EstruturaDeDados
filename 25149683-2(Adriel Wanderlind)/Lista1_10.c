#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    char nome[30];
    int idade;

    struct no *prox;

}No;

void inserir(No **ini, No **fim){

    No *novo=malloc(sizeof(No));

    printf("Nome: ");
    scanf(" %[^\n]",novo->nome);

    printf("Idade: ");
    scanf("%d",&novo->idade);

    novo->prox=NULL;

    if(*fim)
        (*fim)->prox=novo;

    else
        *ini=novo;

    *fim=novo;
}

void mover(No **origem,No **destIni,No **destFim){

    while(*origem){

        No *aux=*origem;

        *origem=(*origem)->prox;

        aux->prox=NULL;

        if(aux->idade<=30){

            if(*destFim)
                (*destFim)->prox=aux;

            else
                *destIni=aux;

            *destFim=aux;
        }

        else{

            printf("\n%s - %d anos\n",
                   aux->nome,
                   aux->idade);

            free(aux);
        }
    }
}

void imprimir(No *fila){

    while(fila){

        printf("%s - %d\n",
               fila->nome,
               fila->idade);

        fila=fila->prox;
    }
}

int main(){

    No *fila=NULL;
    No *fim=NULL;

    No *fila2=NULL;
    No *fim2=NULL;

    for(int i=0;i<10;i++)
        inserir(&fila,&fim);

    mover(&fila,&fila2,&fim2);

    printf("\nFila até 30 anos:\n");

    imprimir(fila2);

    return 0;
}
