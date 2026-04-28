#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define tot 2
	
void EntPessoa();
void SaiPessoa();
void ClassNome();

int main(){
	EntPessoa();
	SaiPessoa();
	ClassNome();
	system("pause");
	return 0;
	
}

struct pessoa{
	char nome[50];
	int idade;
	char telefone[11];
};

struct pessoa p[tot];
	
void EntPessoa(){
	
	for (int x=0;x<tot;x++){

		printf("Pessoa %d \n",x+1);
		printf("Nome: ");
		fgets(p[x].nome,50,stdin);
		fflush(stdin);
		
		printf("Telefone: ");
		scanf("%s",&p[x].telefone);
		fflush(stdin);
		
		printf("Idade: ");
		scanf("%d",&p[x].idade);
		fflush(stdin);
		
		printf("------------\n");
	}
}

void SaiPessoa(){
	
	for (int x=0;x<tot;x++){
		printf("Pessoa %d \n",x+1);
		printf ("Nome: %s",p[x].nome);
		printf("Telefone: %s \n",p[x].telefone);
		printf("Idade: %d \n",p[x].idade);
	
	printf("------------\n");
	}
	
}

void ClassNome(){
	pessoa tmp;
	
	for (int x=0; x<tot-1; x++){
		for (int y=x-1; y<tot; y++)
			if (strcmp(p[y].nome,p[x].nome)==-1){
				tmp=p[y];
				p[y]=p[x];
				p[x]=tmp;
		}
	}
}


