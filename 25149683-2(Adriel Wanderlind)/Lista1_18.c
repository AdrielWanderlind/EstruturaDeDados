#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{

int valor;

struct no *prox;

}No;

void inserir(
No **ini,
No **fim,
int valor
){

No *novo=
malloc(
sizeof(No)
);

novo->valor=
valor;

novo->prox=
NULL;

if(*fim)
(*fim)->prox=
novo;

else
*ini=
novo;

*fim=
novo;

}

void remover5(
No **ini,
No **fim
){

No *at=
*ini;

No *ant=
NULL;

while(at){

if(
at->valor
%
5
==
0
){

if(ant)
ant->prox=
at->prox;

else
*ini=
at->prox;

No *aux=
at;

at=
at->prox;

free(aux);

}

else{

ant=
at;

at=
at->prox;

}

}

}

void mostrar(
No *ini
){

while(ini){

printf(
"%d\n",
ini->valor
);

ini=
ini->prox;

}

}

int main(){

srand(
time(NULL)
);

No *ini=
NULL;

No *fim=
NULL;

for(
int i=0;
i<20;
i++
)

inserir(
&ini,
&fim,
rand()%100+1
);

remover5(
&ini,
&fim
);

mostrar(
ini
);

}
