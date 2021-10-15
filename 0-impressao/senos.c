#include <stdlib.h>
#include <math.h>
#include <locale.h>

void main (){
	setlocale (LC_ALL, "Portuguese_Brasil");
	float num_1, num_2;
	num_1 = sin(3.14);
	num_2 = sin(4.13);
	printf ("\n\nO seno de 3,14 é: %f \n \nO seno de 4,13 é: %f \n\nAtenção, todos os valores acima estão em radianos\n\n", num_1, num_2);
}