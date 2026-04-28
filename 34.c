#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void push(int item);
void pop();
void imprimir();
int entrada_dados();

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
}no;

no *top=NULL;

int main(){
	srand(time(NULL));
	int n,opcao;
	do{
		system("cls");
		printf("\n\nMenu\n1. Empilhar \n2. Desempilhar\n3. Imprimir \n4. Gerar 5 valores aleatorios \n5. Maior elemento e sua posicao \n6. Esvaziar \n7. Sair\n");
		printf("\nEscola uma opcao (0-6): ");
		scanf("%d",&opcao);
		
		switch (opcao){
			case 1:
				n=entrada_dados();
				push(n);
				break;
			case 2:
				pop();
				break;
			case 3:
				imprimir();
				break;
			case 4:
				gerar();
				break;
			case 5:
				maior();
				break;
			case 6:
				esv();
				break;
		}
	}while (opcao!=7);
	system("pause");
	return 0;
}
void maior(){
	no *temp;
	temp = top;
	int maior = 0;
	int cont = 1;
	int pos = 0;
		
	while(temp!=NULL){
			
		if(temp->dado > maior){
				
				maior = temp->dado;
				pos = cont;							
		}
		cont++;
		temp = temp->proximo;
	}
		
	printf("Maior elemento: %d\n", maior);
	printf("Posicao do elemento: %d\n", pos);
	system("pause");
}

void esv(){
	printf("\n------ESVAZIANDO-----\n\n");
	while(top!=NULL){
		pop();
	}
	printf("\nEsvaziado!\n");
}

void gerar(){
	int i,v;
	printf("\nGERANDO...\n");
	for (i=0;i<5;i++){
		v=rand() % (91)+10;
		push(v);
	}
}

void push(int item){
	printf("\nEMPILHANDO...\n");
	no *novo=malloc(sizeof(no));
	// necessário vericiar se há memória
	novo->dado=item;
	novo->proximo=top;
	top=novo;
	printf("\nValor %d empilhado\n",novo->dado);
	system("pause");
}


void pop(){
	printf("\DESEMPILHANDO...\n");
	if (top==NULL)
		printf("A pilha esta vazia\n");
	else{
		no *temp;
		temp=top;
		top=top->proximo;
		printf("\n%d Desempilhado com sucesso\n",temp->dado);
		free(temp);
	}
	system("pause");
}

void imprimir(){
	no *temp;
	temp=top;
	printf("\nIMPRIMINDO PILHA...\n");
	while (temp!=NULL){
		printf("%d\n", temp->dado);
		temp=temp->proximo;
	}
	system("pause");
}

int entrada_dados(){
	int valor;
	printf("\nEntre com valor a empilhar: ");
	scanf("%d",&valor);
	return valor;
}
