#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"portuguese");
	
	char nome[30]="Moreno", *p, **pp;
	int idade=45, *i, **ii;
	// 1º ponteiro aponta(p) para nome, e 2º ponteiro(pp) aponta para o 1º(i), que está apontado para nome(moreno)
	p = nome;
	pp = &p;
	
	// 1º ponteiro(i) aponta para idade, e 2º ponteiro(ii) aponta para o 1º(i), que está apontado para idade(45)
	i = &idade;
	ii = &i;
	
	printf("Variável nome: %s\n",nome);
	printf("Usando ponteiro: %s\n",p);
	printf("Usando ponteiro de ponteiro: %s\n\n",*pp);
	
	printf("2o. caracter usando pp com []: %c\n",(*pp)[1]);
	printf("3o. caracter usando aritmetica de de pp: %c\n\n",*(*pp+2));
	
	printf("Variável idade: %d\n",idade);
	printf("Usando ponteiro: %d\n",*i);
	printf("Usando ponteiro de ponteiro: %d\n\n",**ii);
	
	printf("End. de nome: %p\n",nome);
	printf("End. ponteiro de nome: %p\n",&p);
	printf("End. ponteiro de ponteiro de nome: %p\n\n",&pp);
	
	
	printf("End. de idade: %p\n",idade);
	printf("End. de ponteiro de idade: %p\n",i);
	printf("End. de ponteiro de ponteiro de idade: %p\n\n",ii);
	
	printf("End. ponteiro de nome aponta: %p\n",p);
	printf("End. ponteiro de ponteiro de nome aponta: %p",pp);
	
}
