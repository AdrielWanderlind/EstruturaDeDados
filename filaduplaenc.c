#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
	struct apelido_no *ant;	
}no;

//---------------------

void inserir_ini(no **lista, int num);
void imprimir(no *lista);

//-------------------
int main(){
	setlocale(LC_ALL,"PORTUGUESE");
	srand(time(NULL));
	int op,n,ant;
	no *lista=NULL;
	
	do{
		system("cls");
		printf("- - - - - Fila duplamente encadeada - - - - -\n");
		printf("1 - Inserir no início\n");
		printf("2 - Inserir no meio\n");
		printf("3 - Imprimir\n");
		printf("4 - Encerrar\n");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				printf("Qual número?\n");
				scanf("%d",&n);
				inserir_ini(&lista, n);
				break;
			case 2:
				printf("Qual número?\n");
				scanf("%d",&n);
				printf("Depois de qual número da fila?\n");
				scanf("%d",&ant);
				inserir_meio(&lista,n,ant);
				break;
			case 3:
				imprimir(lista);
				break;
		}
	}while(op!=4);
	
	system("pause");
	return 0;
}
//------------------------
void inserir_ini(no **lista, int num){
	no *novo=malloc(sizeof(no));
	
	novo->dado=num;
	novo->ant=NULL;
	novo->proximo=*lista;
	if (*lista != NULL){
		(*lista)->ant=novo;
	}
	*lista=novo;
}

void imprimir(no *lista){
	while(lista!=NULL){
		printf("%4d",lista->dado);
		printf("\n");
		lista=lista->proximo;
	}
	printf("\n");
	system("pause");
}

void inserir_meio(no **lista,int num,int ant){
	no *aux,*novo=malloc(sizeof(no));
	
	if(novo){
		novo->dado=num;
		if(*lista=NULL){
			novo->proximo=NULL;
			*lista=novo;
		} else {
			aux=*lista;
			while(aux->dado != ant && aux->proximo)
				aux=aux->proximo;
			
		}
	} else 
	printf("Erro ao alocar memória\n");
	
}
