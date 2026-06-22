#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{

int valor;

struct no *prox;

}No;

void push(
No **topo,
int valor
){

No *novo=
malloc(
sizeof(No)
);

novo->valor=
valor;

novo->prox=
*topo;

*topo=
novo;

}

int existe(
No *topo,
int valor
){

while(topo){

if(
topo->valor
==
valor
)

return 1;

topo=
topo->prox;

}

return 0;

}

void imprimir(
No *topo
){

while(topo){

printf(
"%d\n",
topo->valor
);

topo=
topo->prox;

}

}

int main(){

srand(
time(NULL)
);

No *topo=NULL;

while(1){

int n=
rand()%91+10;

if(
!existe(
topo,
n
)
)

push(
&topo,
n
);

int cont=0;

No *aux=
topo;

while(aux){

cont++;

aux=
aux->prox;

}

if(cont==10)
break;

}

imprimir(
topo
);

}
