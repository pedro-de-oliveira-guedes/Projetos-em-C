#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "P_14_Mod.h"

#define TAM_VETOR 20
#define TAM_MAX_STRING 100

int main(int argc, char const *argv[])
{
	int n = 0;

	int vet [TAM_VETOR];

	int x = 0, y = 0;

	srand (time (NULL));

	//Primeiro exercício:
	printf ("\n\n----------------------------------------------------------------\n");
	printf ("Digite um numero para obter a soma de seus primeiros cubos: ");
	scanf ("%d", &n);
	printf("%d\n", soma_n_cubos (n));

	//Segundo exercício:
	printf ("\n\n----------------------------------------------------------------\n");
	printf ("Digite um numero para ter a sequencia de 0 a ele impressa: ");
	scanf ("%d", &n);
	imprime_zero_a_n (n);

	//Terceiro exercício:
	printf ("\n\n----------------------------------------------------------------\n");
	printf ("Digite um numero para ter a sequencia dele a 0 impressa: ");
	scanf ("%d", &n);
	imprime_n_a_zero (n);

	//Quarto exercício:
	printf ("\n\n----------------------------------------------------------------\n");
	printf ("Seja o vetor:\n");
	for (int i = 0; i < TAM_VETOR; i++){
		vet [i] = randomInt (0, 100);
		printf ("%d ", vet [i]);
	}
	printf ("\nA soma dos elementos presentes nesse vetor eh: %d", soma_vet (vet, 0));

	//Quinto exercício:
	printf ("\n\n----------------------------------------------------------------\n");
	printf ("A media dos valores presentes no mesmo vetor eh: %.2f", media_vet (vet, 0));

	//Sexto exercício:
	printf ("\n\n----------------------------------------------------------------\n");
	printf ("Digite a base da poencia: ");
	scanf ("%d", &x);
	printf ("\nDigite o expoente da potencia: ");
	scanf ("%d", &y);
	printf ("\n\nO resultado da potenciacao eh: %d", potencia (x, y));

	//Sétimo exercício:
	printf ("\n\n----------------------------------------------------------------\n");
	char string [TAM_MAX_STRING] = "Meu nome eh Pedro!";
	printf ("A frase: '%s' ao contrario eh: \n", string);
	frase_ao_contrario (string, strlen (string));

	//Oitavo exercício:
	printf ("\n\n----------------------------------------------------------------\n");
	printf ("Digite um numero para ser escrito ao contrario: ");
	scanf ("%d", &n);
	num_invertido (n);

	//Nono exercício:
	printf ("\n\n----------------------------------------------------------------\n");
	printf ("Digite um inteiro positivo: ");
	scanf ("%d", &n);
	printf ("\nEsse numero em base binaria eh: ");
	dec_em_bin (n);

	//Décimo exercício:
	printf ("\n\n----------------------------------------------------------------\n");
	printf ("Seja o vetor:\n");
	for (int i = 0; i < TAM_VETOR; i++){
		vet [i] = randomInt (0, 100);
		printf ("%d ", vet [i]);
	}
	printf ("\n\nO menor elemento presente nesse vetor eh: %d\n\n", menor_elemento (vet, 0));

	return 0;
}