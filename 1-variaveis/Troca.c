#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese_Brasil");
	printf ("\n\n");
	float a = 3.14159, b = 2.71828;
	float c;
	c=a;
	a=b;
	b=c;
	printf("\nPI = %f", b);
	printf("\nEULER = %f", a);
	return 0;
}