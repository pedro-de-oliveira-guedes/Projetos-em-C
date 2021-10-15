#include <stdio.h>
#include <math.h>

float paraMetrosPorSegundo(float v){
	return v/3.6;
}

float areaCirculo(float raio){
	return M_PI * pow(raio, 2);
}

int maior3(int n1, int n2, int n3){
	if (n1 > n2 && n1 > n3) return n1;
	
	if (n2 > n1 && n2 > n3) return n2;
	
	if (n3 > n1 && n3 > n2) return n3;
}

int ehPar(int n){
	return (n%2 == 0);
}

int ehDivisivelPor3ou5(int n) {
	if (n%3 == 0 && n%5 == 0) return 0;
	
	if (n%3 == 0 || n%5 == 0) return 1;
	
	return 0;
}

float pesoIdeal(float h, char sexo){
	if (sexo == 'M') return (72.7 * h) - 58;

	if (sexo == 'F') return (62.1 * h) - 44.7;

return 0;
}

float peso (float p, float h, char sexo){
	return pesoIdeal (h, sexo) - p;
}

int somaImpares(int N){
	int soma = 0;
	for (int i = 0; i <= N; ++i){
		if (i%2 == 1) soma += i;
	}
	return soma;
}

double fatorial(int N){
	double uiui = 1;
	
	for	(int i = 1; i <= N; i++){
		uiui = uiui * i;
	}
	return uiui;
}

int somaNumerosDiv3ou5(int N){
	int soma = 0;
	for (int i=0; i<=N; i++){
		if (i%3 == 0 || i%5 == 0) soma += i;
		
		if (i%3 == 0 && i%5 == 0) soma -= i;
	}
		return soma;
}

float calculaMedia(int x, int y, int z, int operacao) {
	if (operacao == 1){
		return pow (x*y*z, 1/3);
	} else if (operacao == 2){
		return (x + 2*y + 3*z)/6;
	} else if (operacao == 3){
		return 3/(1/x + 1/y + 1/z);
	} else if (operacao == 4){
		return (x + y + z)/3;
	} else return 0;
}