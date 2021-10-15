#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese_Brasil");
	printf ("\n\n");
	float poupanca = 789.54;
	poupanca += (poupanca*0.0056);
	poupanca += 303.2;
	poupanca += (poupanca*0.0056);
	poupanca -= 58.25;
	poupanca += (poupanca*0.0056);
	printf ("A conta terá: R$ %.2f \n\n", poupanca);
	/*
	Uma conta poupança foi aberta com um depósito de R$789,54, com rendimentos de 0.56% de juros ao mês. 
	No segundo mês, R$303,20 reais foram depositados nessa conta poupança. No terceiro mês, R$58,25 reais 
	foram retirados da conta. Implemente um programa que imprime quanto haverá nessa conta no quarto mês.

	Resposta: A conta terá R$1050,91 no quarto mês.
	*/
	
	return 0;
}