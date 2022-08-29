#include <stdio.h>

int main(int argc, char *argv[]){
	
	int num=0, resultado=1, n=0;
	
	printf("\n\t\tEscribe un numero entero cualquiera: ");
	scanf("%d", &num);
	
	for(n=1; n<=num; n++){
		resultado= resultado*i;
	}
	
	printf("\n\t\t\t%d! es: %d", num, resultado);
	printf("\n\n\t");
	
	system("pause");
	return 0;
}

//LA COMPLEJIDAD ES DE 0(2n-1)
