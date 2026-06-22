#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{

char nome[50];

int retirou;

struct pessoa *prox;

}Pessoa;

typedef struct fila{

char nome[50];

struct fila *prox;

}Fila;

typedef struct pizza{

int codigo;

struct pizza *prox;

}Pizza;

Pessoa *lista=NULL;

Fila *inicio=NULL;
Fila *fim=NULL;

Pizza *topo=NULL;

void cadastrar(){

Pessoa *novo=
malloc(sizeof(Pessoa));

printf("Nome: ");

scanf(" %[^\n]",
novo->nome);

novo->retirou=0;

novo->prox=lista;

lista=novo;

}

void entrarFila(){

Fila *novo=
malloc(sizeof(Fila));

printf("Nome: ");

scanf(" %[^\n]",
novo->nome);

novo->prox=NULL;

if(fim)
fim->prox=novo;

else
inicio=novo;

fim=novo;

}

void empilhar(){

Pizza *novo=
malloc(sizeof(Pizza));

printf("Codigo pizza: ");

scanf("%d",
&novo->codigo);

novo->prox=topo;

topo=novo;

}

void entregar(){

if(
inicio==NULL
||
topo==NULL
){

printf(
"Entrega impossivel\n"
);

return;

}

Fila *f=inicio;

inicio=
inicio->prox;

Pizza *p=
topo;

topo=
topo->prox;

Pessoa *aux=
lista;

while(aux){

if(
strcmp(
aux->nome,
f->nome
)==0
)

aux->retirou=1;

aux=
aux->prox;

}

printf(
"%s recebeu pizza\n",
f->nome
);

free(f);

free(p);

}

void mostrar(){

Pessoa *aux=
lista;

while(aux){

printf(
"%s - %s\n",
aux->nome,
aux->retirou
?
"Retirada"
:
"Pendente"
);

aux=
aux->prox;

}

}

int main(){

int op;

do{

printf(
"\n1 Cadastrar"
"\n2 Entrar fila"
"\n3 Pizza pronta"
"\n4 Entregar"
"\n5 Consultar"
"\n0 Sair\n"
);

scanf("%d",&op);

switch(op){

case 1:
cadastrar();
break;

case 2:
entrarFila();
break;

case 3:
empilhar();
break;

case 4:
entregar();
break;

case 5:
mostrar();

}

}while(op!=0);

}
