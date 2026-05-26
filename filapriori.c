//concluir um programa em linguagem C que implemente duas filas (uma geral e uma de prioridade)
//A regra para prioridade deverá ser a seguinte:
//Ao chegar a pessoa, ela deverá ser ingressada na Fila 1 (geral) mas verificando prioridade para a mesma fila.
//A prioridade ocorre para pessoas com 60 anos ou mais, obedecendo a prioridade na idade.
//Exemplo:
//chegada pessoa 40 anos   40,
//chegada pessoa 61 anos   61,40
//chegada pessoa 19 anos   61,40,19
//chegada pessoa 60 anos   61,60,40,19
//chegada pessoa 73 anos   73,61,60,40,19
//chegada pessoa 27 anos   73,61,60,40,19,27
//chegada pessoa 69 anos   73,69,61,60,40,19,27

//A funcionalidade SEPARAR FILAS deverá mover as pessoas prioritárias para uma segunda fila



#include <stdlib.h>
#include <stdio.h>

void esv1();
void enqueue(int item);
void dequeue();
void imprimir();
int entrada_dados();

typedef struct apelido{ //apelido do nó
	int dado; // dado do nó
	struct apelido *proximo; // chamando o próximo de si
}no;  // criação do nó
// ----------------------------
no *inicio1 = NULL;
no *final1 = NULL;

no *inicio2 = NULL;
no *final2 = NULL;
//----------------------------

// ---------------------------
int main(){
  int n, opcao, prioridade;
  do {
    system("cls");
    printf("\n=========== FILA DE PRIORIDADE ===========");
    printf("\n1. Enfileirar Fila1 (geral)");
    printf("\n2. Desenfileirar Fila1 (geral)");
    printf("\n3. Desenfileirar Fila Prioridade");
    printf("\n4. Separar Filas");
    printf("\n5. Imprimir Fila1 (Geral)");  
    printf("\n6. Imprimir Fila Prioridade...");
    printf("\n7. Sair");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    switch (opcao){
      case 1:
			n=entrada_dados();
 			enqueue(n);
        break;
      case 2:
 			esv1();
        break;
      case 3:
 
        break;
      case 4:
 
        break;
      case 5:
 
        break;
      case 6:
 
        break;
     }
  } while (opcao != 7);
  system("pause");
  return 0;
} 

//----------------------------------------
void enqueue(int item){
	printf("Enfileirando...\n");
	no *novo=malloc(sizeof(no));
	
	novo->dado=item;
	novo->proximo=NULL;
	
	if (inicio1==NULL){
		inicio1=novo;
		final1=novo;
	} else {
		final1->proximo=novo;
		final1 = novo;
	}
	printf("Valor %d Enfileirado\n", novo->dado);
  system("pause");
}
//----------------------------------------
void esv1(){
	while(inicio1!=NULL){
		dequeue();
	}
		printf("\nVazio!\n");
	system("pause");
}
//-------------------------------------
void dequeue(){
		if (inicio1==NULL){ 
			printf("A fila esta vazia\n");
		} else{
			no *temp=inicio1;
			inicio1=inicio1->proximo;
			printf("Valor %d desenfileirado com sucesso\n",temp->dado);
			free(temp);
			if (inicio1==NULL){
				final1=NULL;
			}
		}
  system("pause");
}
//----------------------------------------
void imprimir(){

  system("pause");
}
//----------------------------------------
int entrada_dados(){
	int valor;
	printf("Qual idade da pessoa que ira entrar na fila? \n");
	scanf("%d",&valor);
	
	return valor;
}
//----------------------------------------
