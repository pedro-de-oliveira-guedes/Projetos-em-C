#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "estatistica.h"

int main(){
	float x, u, B, b, res_cauchy, res_gumbel, res_laplace;
	
	x = -2;
	
	res_cauchy = cauchy (x);
	printf ("\n\n********************************************************\n\n");
	printf ("A densidade de probabilidade em Cauchy eh de: %f", res_cauchy);
	printf ("\n\n********************************************************\n\n");
	
	x = 0;
	
	u = 0.5;
	
	B = 2;
	
	res_gumbel = gumbel (x, u, B);
	printf ("\n\n********************************************************\n\n");
	printf ("A densidade de probabilidade em Gumbel eh de: %f", res_gumbel);
	printf ("\n\n********************************************************\n\n");
	
	x = -6;
	
	u = -5;
	
	b = 4;
	
	res_laplace = laplace (x, u, b);
	printf ("\n\n********************************************************\n\n");
	printf ("A densidade de probabilidade em Cauchy eh de: %f", res_laplace);
	printf ("\n\n********************************************************\n\n");
	
	return 0;
}