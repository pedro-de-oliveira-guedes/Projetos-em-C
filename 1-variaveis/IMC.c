#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese_Brasil");
	printf ("\n\n");
	
	float IMC_B, Peso_IDB, IMC_O, Peso_IDO, A_B = 1.84, P_B = 122, A_O = 1.76, P_O = 45;
	
	IMC_B = P_B / (A_B*A_B);
	IMC_O = P_O / (A_O*A_O);
	
	printf ("------------------Brutus---------------------\n\n");
	
	if (IMC_B > 25){
		Peso_IDB = 24.9 * (A_B * A_B);
		Peso_IDB = P_B - Peso_IDB;
		printf ("O IMC de Brutus é: %.2f. \n\nPara ter um peso saudável, ele precisa perder, no mínimo, %.2f kg. \n\n", IMC_B, Peso_IDB);
	} 
	else{
		if (IMC_B >= 18.5){
			printf ("O IMC de Brutus é: %.2f. \n\nIsso quer dizer que ela está com um peso saudável!\n\n", IMC_B);
		}
		Peso_IDB = 18.5 * (A_B * A_B);
		Peso_IDB -= P_B;
		printf ("O IMC de Brutus é: %.2f. \n\nPara ter um peso saudável, ele precisa ganhar, no mínimo, %.2f kg. \n\n", IMC_B, Peso_IDB);
	}
	
	printf ("--------------------Olívia-----------------------\n\n");
	
	if (IMC_O > 25){
		Peso_IDO = 24.9 * (A_O * A_O);
		Peso_IDO = P_B - Peso_IDO;
		printf ("O IMC de Olivia é: %.2f. \n\nPara ter um peso saudável, ela precisa perder, no mínimo, %.2f kg. \n\n", IMC_O, Peso_IDO);
	} 
	else{
		if (IMC_O >= 18.5){
			printf ("O IMC de Olívia é: %.2f. \n\nIsso quer dizer que ela está com um peso saudável!\n\n", IMC_O);
		}
		Peso_IDO = 18.5 * (A_O * A_O);
		Peso_IDO -= P_O;
		printf ("O IMC de Olivia é: %.2f. \n\nPara ter um peso saudável, ela precisa ganhar, no mínimo, %.2f kg. \n\n", IMC_O, Peso_IDO);
	}
	return 0;
}