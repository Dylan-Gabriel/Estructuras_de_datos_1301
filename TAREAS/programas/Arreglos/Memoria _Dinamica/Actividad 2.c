#include <stdio.h>
#include <stdlib.h>


int main(){
    int nC, u, i;
    int *p = calloc(10, sizeof(int));

    if(p == NULL){
        return -1;
    }
    
    for(i = 0; i < 10; i++){
        p[i] = (i+1)*2;
    }
    
	    printf("\n\n\tEsta es la sucesi%cn n%cmerica de pares:",162, 163 );
    
	for(i = 9; i >= 0; i--){    
    
        printf(" %d ", p[i]);
    }

    printf("\n\n\tIngresa tu n%cmero de cuenta: ", 163);
    scanf("\n\t%d", &nC);

    u = nC % 10;

    p[u] = -1;

/*printf("Aqu% se modifica el valor almacenado en el %cndice correspondiente al %cltimo d%gito de su n%cmero cuenta por -1: ", 161, 161, 163, 161, 163);*/
	printf("n\n\tSe hace el recorrido de -1 con el %cltimo d%cgito de el numero de cuenta: ", 163, 161);	
    for (i = 0; i < 10; i++){
        printf(" %d ", p[i]);
    }

    p = NULL;
    free(p);

    return 0;
}
