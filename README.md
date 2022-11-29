# Estructuras_de_datos_1301
#Equipo:

-Albor Saucedo Dylan Gabriel

-Martínez Vega Brayan :v


#include <stdio.h>

int main(){
    int num;
    int n;
    int i;
    int k=[10];
    
    for(i=0; i<10; i++){
        k[i]=(i+1)*2;
    }
    
	printf("\n\n\tEsta es la sucesi%cn n%cmerica de pares:",162, 163 );
	
    for(i=9; i>=0; i--){    
        printf(" %d ", k[i]);
    }

	printf("\n\n\tIngresa tu n%cmero de cuenta: ", 163);
    scanf("\n\t%d", &num);

    n=num%10;

    k[n]=-1;

	printf("n\n\tSe hace el recorrido de -1 con el %cltimo d%cgito de el numero de cuenta: ", 163, 161);
    for (i=0; i<10; i++){
        printf(" %d ", k[i]);
    }

    return 0;
}
