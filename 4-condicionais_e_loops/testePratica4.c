#include <stdio.h>
#include <math.h>
#include "pratica4.h"

int main (){
	printf ("3km/h em m/s eh: %.2f\n\n\n", paraMetrosPorSegundo(3));
	printf ("A area do circulo de raio 2 eh: %.2f\n\n\n", areaCirculo(2));
	printf ("O maior numero entre 1, 2 e 3 eh: %d\n\n\n", maior3 (1,2,3));
	printf ("Se o numero depois dos dois pontos for 1, entao 5 eh par: %d\n\n\n", ehPar (5));
	printf ("Se o numero depois dos dois pontos for 1, entao 15 eh divisivel por 3 ou 5 (XOR): %d\n\n\n", ehDivisivelPor3ou5 (15));
	printf ("Um homem com 1,70 precisa ter %.2f kg para estar no peso ideal\n\n\n", pesoIdeal (1.70, 'M'));
	printf ("Uma mulher com 1,70 que tem 50 kg precisa de %.2f kg para estar no peso ideal\n\n\n", peso (50, 1.70, 'M'));
	printf ("A soma dos numeros impares menores que 5 eh: %d\n\n\n", somaImpares (5));
	printf ("O fatorial de 5 eh: %.0lf\n\n\n", fatorial (5));
	printf ("A soma dos numeros menores que 20 divisiveis por 3 ou 5 (XOR) eh: %d\n\n\n", somaNumerosDiv3ou5 (20));
	printf ("A media aritmetica de 1, 2 e 3 eh: %.2f", calculaMedia (1, 2, 3, 4));
}