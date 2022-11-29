#include <stdio.h>
#include <stdlib.h>

int main(){
		
	int n=3;
	int i;
	char nombre[n][25];
	int edad[n]; 
	int calificacion[n];	
	int suma=0;
	int suma1=0;
	float promedio;
	float promedio1;
	char respuesta;

	for (i=0; i<n;i++){
		printf("%d\t", i);
		fflush(stdin);
		printf("Nombre: ");
		gets(nombre[i]);
		printf("\tEdad: ");
		scanf("%d", &edad[i]);
		printf("\tCalificacion: ");
		scanf("%d",&calificacion[i]);
		printf("\n");
	}
		
		
		printf("\n\n|     Nombre     | Edad | Calificacion |\n");
		printf("-----------------------------------------\n");
	
	
	for(i=n-1; i>=0;i--)
		
		printf("|      %s        %d       %d      \n", nombre[i], edad[i],calificacion[i]);
			
		printf("-----------------------------------------\n");
		
	

    for (i=0; i<n; i++){
    	
    	suma1=suma1+edad[i];
    }
    promedio1=suma1/n;
    printf("\n\nEl Promedio de las edades es: %f\n\n", promedio1);		
			
    for (i=0; i<n; i++){
    	suma=suma+calificacion[i];
    }
    promedio=suma/n;
    printf("El Promedio de las calificaciones es: %f", promedio);
    
		
}
