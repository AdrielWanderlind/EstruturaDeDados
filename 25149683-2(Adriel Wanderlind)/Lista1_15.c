#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{

char *nome;

int idade;

struct no *prox;

}No;

void inserir(No **ini, No **fim){

No *novo=malloc(sizeof(No));

char temp[100];

printf("Nome: ");
scanf(" %[^\n]",temp);

novo->nome=
malloc(
strlen(temp)+1
);

strcpy(
novo->nome,
temp
);

printf("Idade: ");

scanf("%d",
&novo->idade);

novo->prox=NULL;

if(*fim)
(*fim)->prox=novo;

else
*ini=novo;

*fim=novo;

}

void remover(
No **ini,
No **fim
){

if(*ini==NULL)
return;

No *aux=*ini;

*ini=
aux->prox;

if(*ini==NULL)
*fim=NULL;

free(aux->nome);

free(aux);

}

void imprimir(
No *fila
){

while(fila){

printf(
"%s - %d\n",
fila->nome,
fila->idade
);

fila=
fila->prox;

}

}

int main(){

No *ini=NULL;

No *fim=NULL;

int op;

do{

printf(
"\n1 Inserir"
"\n2 Remover"
"\n3 Mostrar"
"\n0 Sair\n"
);

scanf("%d",&op);

switch(op){

case 1:
inserir(
&ini,
&fim
);
break;

case 2:
remover(
&ini,
&fim
);
break;

case 3:
imprimir(
ini
);

}

}while(op!=0);

}
