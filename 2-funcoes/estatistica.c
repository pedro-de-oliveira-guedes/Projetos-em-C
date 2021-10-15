#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float cauchy (float x){
	float res_cauchy = 1/(M_PI*(1+x*x));
	return res_cauchy;
}

float gumbel (float x, float u, float B){
	float z = 1 * (x - u)/B;
	float res_gumbel = 1 * (exp (-1 * (z + exp (-1 * z)))/B);
	return res_gumbel;
}

float laplace (float x, float u, float b){
	float res_laplace = 1 * (exp (-1 * fabs (x - u) / b) / (2 * b));
	return res_laplace;
}