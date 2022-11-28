#include <stdio.h>


int main()
{
    int nC, u, i;
    int p[10];
    
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

	printf("n\n\tSe hace el recorrido de -1 con el %cltimo d%cgito de el numero de cuenta: ", 163, 161);
    for (i = 0; i < 10; i++){
        printf(" %d ", p[i]);
    }

    return 0;
}
