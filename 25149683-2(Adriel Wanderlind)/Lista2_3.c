void sair(){

no *temp;

while(top!=NULL){

temp=top;

top=top->proximo;

free(temp);

}

printf("Memoria liberada!\n");

}
