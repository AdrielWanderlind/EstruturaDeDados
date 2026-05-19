#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

void enqueue(int item);
void dequeue();
void imprimir();
int entrada_dados();
void reds();

typedef struct apelido{
	int dado;
	struct apelido *proximo;
}no;

no *inicio = NULL;
no *final = NULL;
no *inicio2 = NULL;
no *final2 = NULL;
no *inicio3 = NULL;
no *final3 = NULL;

int main(){
	srand(time(NULL));
	setlocale(LC_ALL,"portuguese");
	int n,opcao;
	do{
		system("cls");
		printf(" - - - FILA - - - \n");
		printf("\n\nMenu\n1. Enfileirar \n2. Desenfileirar \n3. Imprimir \n4. Gerar 4 valores aleatorios \n5. Maior elemento e sua posicao \n6. Esvaziar toda a fila \n7. Redistribuir\n8. Sair");
		printf("\nEscola uma opcao (0-6): ");
		scanf("%d",&opcao);
		
		switch (opcao){
			case 1:
				n=entrada_dados();
				enqueue(n);
				break;
			case 2:
				dequeue();
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
			case 7:
				reds();
				esv();
				break;
		}
	}while (opcao!=8);
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
		dequeue();
	}
	printf("\nEsvaziado!\n");
	system("pause");
}

void gerar(){
	int i,v;
	printf("\nGERANDO...\n");
	for (i=0;i<5;i++){
		v=rand() % (91)+10;
		enqueue(v);
	}
}

void enqueue(int item){
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

void enqueue2(int item){
	no *novo=malloc(sizeof(no));
	novo->dado=item;
	novo->proximo=NULL;
		if (inicio2==NULL){
		inicio2 = novo;
		final2 =novo;
	}else{
		final2->proximo = novo;
		final2 = novo;
	}
	
}

void enqueue3(int item){
	no *novo=malloc(sizeof(no));
	novo->dado=item;
	novo->proximo=NULL;
	if (inicio3==NULL){
		inicio3 = novo;
		final3 =novo;
	}else{
		final3->proximo = novo;
		final3 = novo;
	}
}

void reds(){
	no *temp = inicio;
    int pos = 1;

    while(temp != NULL){

        if(pos % 2 != 0){
            enqueue2(temp->dado);
        }else{
            enqueue3(temp->dado);
        }

    temp = temp->proximo;
    pos++;
    }
	 printf("Redistribuição concluída\n");
	 system("pause");
}

void dequeue(){
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
	printf("\nIMPRIMINDO fila 1...\n");
	while (temp!=NULL){
		printf("%4d ", temp->dado);
		temp=temp->proximo;
	}
	printf("\n");
	printf("\nIMPRIMINDO fila 2...\n");
	temp=inicio2;
	while (temp!=NULL){
		printf("%4d ", temp->dado);
		temp=temp->proximo;
	}
	printf("\n");
	printf("\nIMPRIMINDO fila 3...\n");
	temp=inicio3;
	while (temp!=NULL){
		printf("%4d ", temp->dado);
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
