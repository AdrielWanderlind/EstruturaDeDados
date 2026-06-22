#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

void inserir(No **ini, No **fim,int n){

    No *novo=malloc(sizeof(No));

    novo->valor=n;
    novo->prox=NULL;

    if(*fim)
        (*fim)->prox=novo;

    else
        *ini=novo;

    *fim=novo;
}

void removerImpares(No **ini,No **fim){

    No *at=*ini;
    No *ant=NULL;

    while(at){

        if(at->valor%2!=0){

            if(ant)
                ant->prox=at->prox;

            else
                *ini=at->prox;

            if(at==*fim)
                *fim=ant;

            No *aux=at;

            at=at->prox;

            free(aux);
        }

        else{

            ant=at;

            at=at->prox;
        }
    }
}

void mostrar(No *ini){

    while(ini){

        printf("%d\n",ini->valor);

        ini=ini->prox;
    }
}

int main(){

    srand(time(NULL));

    No *ini=NULL;
    No *fim=NULL;

    for(int i=0;i<20;i++)
        inserir(&ini,&fim,rand()%116+10);

    removerImpares(&ini,&fim);

    mostrar(ini);

    return 0;
}
