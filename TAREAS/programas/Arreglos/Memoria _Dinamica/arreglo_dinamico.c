#include <stdio.h>
#include <stdlib.h>

typedef struct Datos{
	char nombre[25];
	int edad; 
	int calificacion; 
}Datos;

int main(){
	
	Datos *arreglo;	
	int n;
	int i;
	int suma=0;
	int suma1=0;
	float promedio;
	float promedio1;
	char respuesta;
	
	printf("Cuantos alumnos deseas ingressar: ");
	scanf("%d", &n);
	printf("\n");
	arreglo=(Datos*)calloc(n, sizeof (Datos));

	if (arreglo==NULL){
		printf("Error");
	}
	
	
	
	for (i=0; i<n;i++){
		printf("%d\t", i);
		fflush(stdin);
		printf("Nombre: ");
		gets(arreglo[i].nombre);
		printf("\tEdad: ");
		scanf("%d", &arreglo[i].edad);
		printf("\tCalificacion: ");
		scanf("%d",&arreglo[i].calificacion);
		printf("\n");
	}
		
		
		printf("\n\n|     Nombre     | Edad | Calificacion |\n");
		printf("-----------------------------------------\n");
	
//	for (i=0; i<n;i++)
	for(i=n-1; i>=0;i--)
		
		printf("|      %s        %d       %d      \n", arreglo[i].nombre, arreglo[i].edad, arreglo[i].calificacion);
			
		printf("-----------------------------------------\n");

    for (i=0; i<n; i++){
    	
    	suma1=suma1+arreglo[i].edad;
    }
    promedio1=suma1/n;
    printf("\n\nEl Promedio de las edades es: %f\n\n", promedio1);		
			
    for (i=0; i<n; i++){
    	suma=suma+arreglo[i].calificacion;
    }
    promedio=suma/n;
    printf("El Promedio de las calificaciones es: %f", promedio);
    
	free(arreglo);		
}
