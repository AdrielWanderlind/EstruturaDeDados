#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main (){
  int x=10,y=2*x,z=5*y; 
  int *ptr1, *ptr2, *ptr3, *ptrN; // ptrN Esse ponteiro aponta a nada
  char tc='c';
  char *ptr4;   
    
  ptr1=&x;
  ptr2=&y;
  ptr3=&z;
  ptr4=&tc;
  ptrN=&x;
  
  printf(" valor x = %d\n",x);
  printf(" valor y = %d\n",y);
  printf(" valor z = %d\n",z);
  printf(" valor tc = %c\n",tc);
  printf("-----------------------------------------\n");
  printf("End. Mem. x = %p\n",&x);
  printf("End. Mem. y = %p\n",&y);
  printf("End. Mem. z = %p\n",&z);
  printf("End. Mem. tc = %p\n",&tc);
  printf("-----------------------------------------\n");
  printf("End. Mem. ptr1 = %p\n",&ptr1);
  printf("End. Mem. ptr2 = %p\n",&ptr2);
  printf("End. Mem. ptr3 = %p\n",&ptr3);
  printf("End. Mem. ptr4 = %p\n",&ptr4);
  printf("End. Mem. ptrN = %p\n",&ptrN); // 2 ponteiros ao mesmo local
  printf("-----------------------------------------\n");
  printf("Valor ptr1 = %p\n",ptr1); 
  printf("Valor ptr2 = %p\n",ptr2);
  printf("Valor ptr3 = %p\n",ptr3);
  printf("Valor ptr4 = %p\n",ptr4);
  printf("Valor ptrN = %p\n",ptrN);
  printf("-----------------------------------------\n");
  printf("Vlr. onde ptr1 aponta = %d\n",*ptr1);
  printf("Vlr. onde ptr2 aponta = %d\n",*ptr2);
  printf("Vlr. onde ptr3 aponta = %d\n",*ptr3);
  printf("Vlr. onde ptr4 aponta = %c\n",*ptr4); // É necessário colocar %c, pois o valor que o ponteiro4 aponta é para o tc, que é = C;
  printf("Vlr. onde ptrN aponta = %d\n",*ptrN);
  printf("-----------------------------------------\n");
  printf("End. Mem. onde ptr1 aponta = %p\n",&*ptr1);
  printf("End. Mem. onde ptr2 aponta = %p\n",&*ptr2);
  printf("End. Mem. onde ptr3 aponta = %p\n",&*ptr3);
  printf("End. Mem. onde ptr4 aponta = %p\n",&*ptr4);
  printf("End. Mem. onde ptrN aponta = %p\n",&*ptrN);
  printf("-----------------------------------------\n");

  char nome[40];
  printf("Informe seu nome completo: ");
  scanf("%[^\n]",nome);
  printf("%s \n",nome);

	printf("%p\n",&*nome);
	
	
	
	for (int i=0;i<strlen(nome);i++) {
		printf("%c %p \n",nome[i],&nome[i]);
	}
	
  system("pause");
  return 0;
}
