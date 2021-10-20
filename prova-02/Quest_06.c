#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//=*=*=*=*=*=*=QUESTÃO 06=*=*=*=*=*=*=*=
typedef struct Ponto {
	float x, y;
} Ponto;

typedef struct Circulo {
	Ponto centro;
	float raio;
} Circulo;

typedef struct Triangulo {
	Ponto sup, base_esq, base_dir;
} Triangulo;
//=*=*=*=*=*=*=QUESTÃO 06=*=*=*=*=*=*=*=


//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 06=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

float dist_Pontos (Ponto a, Ponto b){
	return sqrt (pow (a.x - b.x, 2) + pow (a.y - b.y, 2));
}

int estaContidoCirculoTriangulo(Circulo cir, Triangulo tri){
	Ponto centro_triangulo;

	centro_triangulo.x = (tri.sup.x + tri.base_dir.x + tri.base_esq.x)/3;
	centro_triangulo.y = (tri.sup.y + tri.base_dir.y + tri.base_esq.y)/3;

	if (dist_Pontos (centro_triangulo, cir.centro) < cir.raio){
		if (dist_Pontos (cir.centro, tri.sup) <= cir.raio && 
			dist_Pontos (cir.centro, tri.base_esq) <= cir.raio && 
			dist_Pontos (cir.centro, tri.base_dir) <= cir.raio){
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 06=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

int main()
{
	Circulo c;
	Triangulo t;

	c.centro.x = 11;
	c.centro.y = 12;
	c.raio = 3.5497;

	t.sup.x = 10.7;
	t.sup.y = 10.31;

	t.base_dir.x = 12.08;
	t.base_dir.y = 12.98;

	t.base_esq.x = 6.89;
	t.base_esq.y = 11.19;

	printf("%d ", estaContidoCirculoTriangulo (c, t));

	return 0;
}