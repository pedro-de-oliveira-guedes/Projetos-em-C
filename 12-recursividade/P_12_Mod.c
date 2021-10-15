#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define TAM_VETOR 20
#define TAM_MAX_STRING 100

int randomInt (int min, int max)
{
    return min + rand () % (max - min + 1);
}

unsigned int soma_n_cubos (int n)
{
	if (n == 1)
		return 1;
	return pow (n, 3) + soma_n_cubos (n - 1);
}

void imprime_zero_a_n (int n)
{
	if (n < 0)
		return;
	imprime_zero_a_n (n - 1);

	printf ("%d ", n);
}

void imprime_n_a_zero (int n)
{
	if (n < 0)
		return;
	printf ("%d ", n);

	imprime_n_a_zero (n - 1);
}

int soma_vet (int vetor [TAM_VETOR], int i)
{
	int soma = 0;

	if (i > TAM_VETOR - 1)
		return 0;

	soma = vetor [i] + soma_vet (vetor, i + 1);
	return soma;
}

float media_vet (int vetor [TAM_VETOR], int i)
{
	float media = 0;

	if (i > TAM_VETOR - 1)
		return 0;
	media = ((float)vetor [i] / TAM_VETOR) + media_vet (vetor, i + 1);
	return media;
}

unsigned int potencia (int x, int y)
{
	if (y <= 1)
		return x;

	return x * potencia (x, y - 1);
}

void frase_ao_contrario (char string [TAM_MAX_STRING], int tam)
{
	if (tam < 0)
		return;
	printf ("%c", string[tam]);
	frase_ao_contrario (string, tam - 1);
}

void num_invertido (int n){
	if (n <= 1)
	{
		if (n != 0)
		{
			printf ("%d", n);
			return;
		}
		return;
	}
	printf ("%d", n%10);
	num_invertido (n/10);
}

void dec_em_bin (int n){
	if (n <= 1)
	{
		printf ("%d", n);
		return;
	}
	dec_em_bin (n/2);
	printf ("%d", n%2);
}

int menor_elemento (int vetor [TAM_VETOR], int i)
{
	if (i >= TAM_VETOR - 1)
		return vetor [i];

	int elemento_um = vetor [i];
	int elemento_dois = menor_elemento (vetor, i + 1);

	if (elemento_um < elemento_dois)
		return elemento_um;
	else
		return elemento_dois;
}