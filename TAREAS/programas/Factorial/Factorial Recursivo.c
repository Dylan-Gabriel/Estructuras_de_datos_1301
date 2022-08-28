#include <stdio.h>

int fact (int num){
	if(num <1){
		return 0;
	}else if(num ==1){
		return 1;
	}else{
		return num*fact(num-1);
	}
}

int main(int arg, char *argv[]){
	
	int num, resultado;
	
	printf("\n\tEscribe un numero entero que desees: ");
	scanf("%d", &num);
	resultado=fact(num);
	printf("\n\t\t%d! es: %d\n\n", num, resultado);
	
	return 0;
	
}
