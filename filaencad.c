#include <stdio.h>
#include <stdlib.h>
#include <time.h>

no();

//------------------------------
int main(){
	
}
//------------------------------
typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
}no;  //Nó
//--------------------------
void inserir_ini(no **lista, int num){
	no *novo=malloc(sizeof(no));
	
	if(novo){
		novo->dado=num;
		novo->proximo=*lista;
		*lista=novo;
	}else 
	printf("Erro ao alocar memória \n");
}

void inserior_fim(no **lista, int num){
	no *aux, *novo=malloc(sizeof(no));
	
	if(novo){
		novo->dado=num;
		novo->proximo=NULL;
		
		if (*lista==NULL)
			*lista=novo;
		else {
			aux=*lista;
			while(aux->proximo)
				aux=aux->proximo;
			aux->proximo=novo;
		}
		
	} 
	else
		printf("Erro ao alocar a memória \n");
}

void inserir_meio(no **lista, int num, int ant){
	no *aux, *novo=malloc(sizeof(no));
	
	if(novo){
		novo->dado=num;
	}
}
