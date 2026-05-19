#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void enqueue(int item);
void dequeue();
void imprimir();
int entrada_dados();

typedef struct apelido{
	int dado;
	struct apelido *proximo;
}no;

no *inicio = NULL;
no *final = NULL;

int main(){
	srand(time(NULL));
	int n,opcao;
	do{
		system("cls");
		printf(" - - - FILA - - - \n");
		printf("\n\nMenu\n1. Enfileirar \n2. Desenfileirar \n3. Imprimir \n4. Gerar 5 valores aleatorios \n5. Maior elemento e sua posicao \n6. Esvaziar \n7. Sair\n");
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
	temp = inicio;
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
	printf("\nESVAZIANDO...\n\n");
	while(inicio!=NULL){
		pop();
	}
	printf("\nEsvaziado!\n");
	system("pause");
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
	printf("\nENFILEIRANDO...\n");
	no *novo=malloc(sizeof(no));
	// necessário vericiar se há memória
	novo->dado=item;
	novo->proximo=NULL;
	if (inicio==NULL){
		inicio = novo;
		final=novo;
	}else{
		final->proximo = novo;
		final = novo;
	}
	printf("\nValor %d enfileirado\n",novo->dado);
	system("pause");
}

void pop(){
	printf("\nDESENFILEIRANDO...\n");
	if (inicio==NULL)
		printf("A fila esta vazia\n");
	else{
		no *temp = inicio;
		inicio = inicio->proximo;	
		printf("\n%d Desenfileirado com sucesso\n",temp->dado);
		free(temp);
		if(inicio == NULL){
            final = NULL;
        }
	}
	system("pause");
}

void imprimir(){
	no *temp = inicio;
	printf("\nIMPRIMINDO fila...\n");
	while (temp!=NULL){
		printf("%4.d ", temp->dado);
		temp=temp->proximo;
	}
	system("pause");
}

int entrada_dados(){
	int valor;
	printf("\nEntre com valor a enfileirar: ");
	scanf("%d",&valor);
	return valor;
}
