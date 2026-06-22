#include <stdio.h>
#include <string.h>

int main(){

char palavra[50];

char pilha[50];

printf("Palavra: ");

scanf("%s",
palavra);

int tam=
strlen(
palavra
);

for(
int i=0;
i<tam;
i++
)

pilha[i]=
palavra[
tam-i-1
];

pilha[tam]=0;

if(
strcmp(
palavra,
pilha
)==0
)

printf(
"Palindromo"
);

else

printf(
"Nao e"
);

}
