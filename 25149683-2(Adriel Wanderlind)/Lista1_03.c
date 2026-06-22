#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct apelido{
	int dado;
	struct apelido *proximo;
}no;

no *inicio = NULL;
no *final = NULL;
