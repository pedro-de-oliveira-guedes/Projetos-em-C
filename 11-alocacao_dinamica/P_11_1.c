#include <stdio.h>
#include <stdlib.h>

float **aloca_matriz (int tam){
	float **M = (float**) malloc (tam * sizeof (float*));

	for (int i = 0; i < tam; i++){
		M[i] = (float *) malloc (tam * sizeof (float));
	}

	return M;
}

void libera (float **v, int tam){
	for (int i = 0; i < tam; i++){
		free (v[i]);
	}
	free (v);
}

void preenche_Matriz (float **M, int tam){
	for (int i = 0; i < tam; i++){
		for (int j = 0; j < tam; j++){
			M[i][j] = 0.0;
		}
	}
}

void imprime_Matriz (float **M, int tam){
	for (int i = 0; i < tam; i++){
		for (int j = 0; j < tam; j++){
			printf (" %.1f |", M[i][j]);
		}
		printf ("\n");
	}
}

int main()
{
	int n = 0;
	float **M = NULL;

	printf ("Digite o tamanho da matriz: ");
	scanf ("%d", &n);

	M = aloca_matriz (n);

	preenche_Matriz (M, n);

	imprime_Matriz (M, n);

	libera (M, n);

	return 0;
}