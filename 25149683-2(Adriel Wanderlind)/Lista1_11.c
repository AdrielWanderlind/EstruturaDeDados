#include <stdio.h>
#include <stdlib.h>

typedef struct no{

char nome[30];

int idade;

struct no *prox;

}No;

void push(No **topo){

No *novo=malloc(sizeof(No));

printf("Nome: ");
scanf(" %[^\n]",novo->nome);

printf("Idade: ");
scanf("%d",&novo->idade);

novo->prox=*topo;

*topo=novo;

}

void pop(No **topo){

if(*topo==NULL){

printf("Pilha vazia\n");

return;

}

No *aux=*topo;

*topo=aux->prox;

free(aux);

}

void imprimir(No *topo){

while(topo){

printf("%s %d\n",
topo->nome,
topo->idade);

topo=topo->prox;

}

}

int main(){

No *topo=NULL;

int op;

do{

printf("\n1 Push");
printf("\n2 Pop");
printf("\n3 Mostrar");
printf("\n0 Sair\n");

scanf("%d",&op);

switch(op){

case 1:
push(&topo);
break;

case 2:
pop(&topo);
break;

case 3:
imprimir(topo);

}

}while(op!=0);

}
