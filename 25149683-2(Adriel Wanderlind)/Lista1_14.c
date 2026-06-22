int maiores50(No *topo){

int cont=0;

while(topo){

if(topo->valor>50)
cont++;

topo=topo->prox;

}

return cont;

}
