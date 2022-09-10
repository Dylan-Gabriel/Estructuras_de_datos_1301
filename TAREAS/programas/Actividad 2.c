#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int i, j, digit;
	int **jarray;
	char *num = argv[1];

	fprintf(stdout, "arg[1] = %s \n", argv[1]);
	
	for (i = 0; i < strlen(argv[1]); i++) {
		
		jarray = (int **) malloc(sizeof(int *) * strlen(argv[1]));
		if (jarray == NULL)
			return -1;

		digit = ((int) num[i] - 48);
		fprintf(stdout, "[%d] -> ", digit);
		
		if ( digit == 0 ) {
			jarray[i] = NULL;
			fprintf(stdout, "NULL\n");
		} else {
			jarray[i] = (int *) malloc(sizeof(int) * digit);
			
			for (j = 0; j < digit; j++) {
				jarray[i][j] = digit;
				fprintf(stdout, "%d ", jarray[i][j]);				
			}

			fprintf(stdout, "\n");
		}
	}

	for (i = 0; i < strlen(argv[1]); i++) {
		free(jarray[i]);
	}
	
	free(jarray);

	return 0;
}