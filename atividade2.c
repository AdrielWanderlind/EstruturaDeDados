#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct{
	char nome[15];
	float nota1,nota2,sub;
}dados;

typedef struct apelido{
	dados dado;
	struct apelido *proximo;
}no;

no *top=NULL;
dados entrada_dados();

void imprimir();
void pop();
void push(dados info);
void inv();

int main(){
	int opcao;
	dados info;
	do{
		system("cls");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Imprimir\n");
		printf("4 - Inverter pilha\n");
		printf("5 - Sair\n");
		printf("   OPCAO: ");
		scanf("%d",&opcao);
		
		switch (opcao){
			case 1:
				info=entrada_dados();
				push(info);
				break;
			case 2:
				pop();
				break;
			case 3:
				imprimir();
				break;
			case 4:
				inv();
				break;
		}
	} while (opcao!=5);
	
}

dados entrada_dados(){
	dados dat;
	printf("Escreva seu nome: \n",dat.nome);
	scanf("%s",dat.nome);
	printf("Escreva a primeira nota: \n",dat.nota1);
	scanf("%f",&dat.nota1);
	printf("Escreva a segunda nota: \n",dat.nota2);
	scanf("%f",&dat.nota2);
	printf("Escreva a nota da sub(se houver): \n",dat.sub);
	scanf("%f",&dat.sub);
	
	return dat;
}

void push(dados info){
	printf("Empilhando...\n");
	
	no *novo=malloc(sizeof(no));
	
	novo->dado=info;
	novo->proximo=top;
	top=novo;
	
	system("pause");
}

void pop(){
	printf("Desempilhando...\n	");
	if (top==NULL) {
		printf("A pilha está vazia\n");
	} else {
		no *temp;
		temp=top;
		top=top->proximo;
		free(temp);
	}
	system("pause");	
}

void imprimir(){
	no *temp;
	temp=top;
	printf("Imprimindo pilha...\n");
	
	while (top!=NULL){
		printf("%s / %.2f / %.2f / %.2f\n",temp->dado.nome,temp->dado.nota1,temp->dado.nota2,temp->dado.sub);
		temp=temp->proximo;
	}
}

void inv(){
	no *temp;
	
}
