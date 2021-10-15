#include <stdio.h>
#include <math.h>
#include <string.h>
#include "aleatorio.h"

int main(){
	int nota, cont;
	
	printf ("\n\n");
	printf ("====================Exercicio 01=======================\n\n");
	printf ("A constante de Euler eh aproximadamente: %lf\n\n\n", euler ());
	
	printf ("====================Exercicio 02=======================\n\n");
	conceito ();
	
	printf ("====================Exercicio 03=======================\n\n");
	printf ("Entre com um numero de linhas para a piramide de Floyd: ");
	printf ("\n\n");
	floyd ();
	printf ("\n\n");
	
	printf ("====================Exercicio 03.1=======================\n\n");
	printf ("Entre com um numero de linhas para a piramide de Floyd: ");
	printf ("\n\n");
	floyd_mod ();
	printf ("\n\n");

	printf ("====================Exercicio 04=======================\n\n");
	fflush (stdin);
	cont = tamanho ();
	printf ("\nA string digitada tem: %d caracteres.\n\n\n", cont);
	
	printf ("====================Exercicio 05=======================\n\n");
	fflush (stdin);
	converte ();
	printf ("\n\n");
	
	printf ("====================Exercicio 06=======================\n\n");
	fflush (stdin);
	palindromos ();
	printf ("\n\n");
	
	
	printf ("====================Exercicio 07=======================\n\n");
	fflush (stdin);
	inverte ();
	printf ("\n\n");
	
	printf ("====================Exercicio 08=======================\n\n");
	fflush (stdin);
	abrevia ();
	printf ("\n\n");
	
	printf ("====================Exercicio 09=======================\n\n");
	fflush (stdin);
	abrevia_mod ();
	printf ("\n\n");
	
	return 0;
}