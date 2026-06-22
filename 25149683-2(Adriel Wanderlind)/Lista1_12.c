#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{

int valor;

struct no *prox;

}No;

void push(No **topo,int n){

No *novo=malloc(sizeof(No));

novo->valor=n;

novo->prox=*topo;

*topo=novo;

}

int existe(No *topo,int n){

while(topo){

if(topo->valor==n)
return 1;

topo=topo->prox;

}

return 0;

}

void distribuir(
No **orig,
No **pares,
No **impares
){

while(*orig){

No *aux=*orig;

*orig=aux->prox;

if(aux->valor%2==0){

aux->prox=*pares;

*pares=aux;

}

else{

aux->prox=*impares;

*impares=aux;

}

}

}

void imprimir(No *topo){

while(topo){

printf("%d\n",topo->valor);

topo=topo->prox;

}

}

int main(){

srand(time(NULL));

No *orig=NULL;

No *pares=NULL;

No *impares=NULL;

while(1){

int n=
rand()%91+10;

if(!existe(orig,n))
push(&orig,n);

int cont=0;

No *aux=orig;

while(aux){

cont++;

aux=aux->prox;

}

if(cont==15)
break;

}

distribuir(
&orig,
&pares,
&impares
);

printf("\nPares:\n");

imprimir(pares);

printf("\nImpares:\n");

imprimir(impares);

}
