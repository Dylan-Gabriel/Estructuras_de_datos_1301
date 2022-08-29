#include <stdio.h>

int main(int argc, char *argv[]){
	
	int num=0, resultado=1, i=0;
	
	printf("\n\t\tEscribe un numero entero cualquiera: ");
	scanf("%d", &num);
	
	for(i=1; i<=num; i++){
		resultado= resultado*i;
	}
	
	printf("\n\t\t\t%d! es: %d", num, resultado);
	printf("\n\n\t");
	
	system("pause");
	return 0;
}