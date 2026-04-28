#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stddef.h>

typedef struct{
	int a;
	char b;
	char c;
}est1;

typedef struct{
	char b;
	int a;
	char c;
}est2;

int main(){
	
	printf("Memória usada por estrutura1: %d\n",sizeof(est1));	
	printf("Memória usada por estrutura2: %d\n\n",sizeof(est2));
	
	printf("Memoria utilizada por A em estrutura1: %d\n",offsetof(est1,a));
	printf("Memoria utilizada por B em estrutura1: %d\n",offsetof(est1,b));
	printf("Memoria utilizada por C em estrutura1: %d\n\n",offsetof(est1,c));
	
	printf("Memoria utilizada por B em estrutura2: %d\n",offsetof(est2,b));
	printf("Memoria utilizada por A em estrutura2: %d\n",offsetof(est2,a));
	printf("Memoria utilizada por C em estrutura2: %d\n\n",offsetof(est2,c));
	
	system("pause");
}
