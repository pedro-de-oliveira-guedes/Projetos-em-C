#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


#define MAX_TAM 100


//=*=*=*=*=*=*=QUESTÕES 01 A 04=*=*=*=*=*=*=*=
typedef struct Xis {
	int linha, coluna, tam;
} Xis;
//=*=*=*=*=*=*=QUESTÕES 01 A 04=*=*=*=*=*=*=*=

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


//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 01=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

void matrizIdentidade(int M[][MAX_TAM], int n){
	int i, j;

	if (n < 1 || n > MAX_TAM)
		return;

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			M [i][j] = 0;
		}
		M [i][i] = 1;
	}
}

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 01=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*


//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 02=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

int insereXis(int M[][MAX_TAM], int n, Xis x){
	int i_inicial = x.linha - ((x.tam - 1)/2);
	int j_inicial = x.coluna - ((x.tam - 1)/2);
	int i_final = x.linha + ((x.tam - 1)/2);
	int j_final = x.coluna + ((x.tam - 1)/2);

	if (i_inicial < 0 || j_inicial < 0 || 
		i_final >= n || j_final >= n ||
		x.tam % 2 == 0)
		return 0;

	//Estes laços zeram toda a área da submatriz x 
	for (int i = i_inicial; i < x.tam + i_inicial; i++){
		for (int j = j_inicial; j < x.tam + j_inicial; j++){
			M [i] [j] = 0;
		}
	}
	//Estes laços zeram toda a área da submatriz x

	//Este laço preenche a diagonal principal da submatriz
	for (int i = 0; i < x.tam; i++){
		M [i_inicial + i] [j_inicial + i] = 1;
	}
	//Este laço preenche a diagonal principal da submatriz

	//Este laço preenche a diagonal secundária da submatriz
	for (int i = 0; i < x.tam; i++){
		M [i_inicial + i] [j_final - i] = 1;
	}
	//Este laço preenche a diagonal secundária da submatriz

	return 1;
}

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 02=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*


//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 03=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

int verifica_Xis (int M [][MAX_TAM], Xis aux, int j_final){
	int cont = 0;

	for (int i = aux.linha; i < aux.tam + aux.linha; i++){
		if (M[i][aux.coluna + cont] == 0 || M[i][j_final - cont] == 0){
			return 0;
		}

		for (int j = aux.coluna; j < aux.tam + aux.coluna; j++){
			if (j == aux.coluna + cont || j == j_final - cont)
				continue;
			if (M[i][j] != 0){
				return 0;
			}
		}
		cont++;
	}
	return 1;
}

Xis maiorXis(int M[][MAX_TAM], int n, int i, int j){
	//Variáveis para descobrir maior Xis possível com as coordenadas "i" e "j":
	int i_maximo = n - i, j_maximo = n - j, maior_tam;

	Xis maior_Xis, aux;

	maior_Xis.linha = i;
	maior_Xis.coluna = j;

	//Verifica se as coordenadas centrais do Xis foram passadas fora do limite de tamanho da matriz M
	if (i_maximo <= 0 || j_maximo <= 0){
		maior_Xis.tam = 0;
		return maior_Xis;
	}
	//Retorna que o maior Xis possível de ser contruído é zero nesse caso.

	maior_Xis.tam = 1;

	//Verifica se há um elemento nulo nas coordenadas centrais do Xis
	if (M [i] [j] == 0){
		maior_Xis.tam = 0;
		return maior_Xis;
	}
	//Retorna 0 caso haja um elemento nulo.

	//Condições para descobrir maior Xis possível com as coordenadas "i" e "j"
	if (i_maximo <= j_maximo){
		maior_tam = 2 * (i_maximo) - 1;
	}
	else{
		maior_tam = 2 * (j_maximo) - 1;
	}
	//Condições para descobrir maior Xis possível com as coordenadas "i" e "j"

	//Se o maior tamanho possível para a submatriz for 1, não há mais nada a ser feito
	if (maior_tam == 1)
		return maior_Xis;
	//O maior Xis possível é retornado.

	//A função começa do menor tamanho possível, 1, até encontrar uma situação desfavorável
	aux.tam = 1;
	aux.linha = i - ((aux.tam - 1)/2);
	aux.coluna = j - ((aux.tam - 1)/2);
	
	int j_final = aux.coluna + aux.tam - 1;

	maior_tam = 1;

	while (verifica_Xis (M, aux, j_final)){

		maior_tam += 2;
		aux.tam += 2;
		aux.linha = i - ((aux.tam - 1)/2);
		aux.coluna = j - ((aux.tam - 1)/2);
		j_final = aux.coluna + aux.tam - 1;

		if (!verifica_Xis(M, aux, j_final)){
			maior_tam -= 2;
			break;
		}

	}

	maior_Xis.tam = maior_tam;

	return maior_Xis;

}

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 03=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*


//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 04=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

int lerXis(Xis *x, int n){
	int cont = 1;

	int i_inicial = 0, j_inicial = 0, i_final = 0, j_final = 0;

	while (1) {
		printf ("\nDigite a posicao da linha central do X: ");
		scanf ("%d", &x->linha);
		printf ("\n\nDigite a posicao da coluna central do X: ");
		scanf ("%d", &x->coluna);
		printf ("\n\nDigite o tamanho do X: ");
		scanf ("%d", &x->tam);

		i_inicial = x->linha - ((x->tam - 1)/2);
		j_inicial = x->coluna - ((x->tam - 1)/2);
		i_final = x->linha + ((x->tam - 1)/2);
		j_final = x->coluna + ((x->tam - 1)/2);

		if (i_inicial < 0 || j_inicial < 0 || 
			i_final >= n || j_final >= n){
			printf ("\n\nDados invalidos :(\n\n\n");
			cont++;
			continue;
		}
		break;
	}
	return cont;
}

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 04=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*


//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 05=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

int numCharsRepetidos(char str[]){
	int contador [256], i = 0, cont = 0;

	for (i = 0; i < 256; i++)
		contador [i] = 0;

	i = 0;
	while (str[i] != '\0'){
		contador [toupper (str[i])]++;
		i++;
	}

	for (i = 65; i <= 90; i++){
		if (contador [i] > 1)
			cont++;
	}

	return cont;
}

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*QUESTÃO 05=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*


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


void imprime_matriz (int M[][MAX_TAM], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d ", M[i][j]);
		}
		printf ("\n");
	}
}


int main(){
	int matriz [MAX_TAM] [MAX_TAM];
	int tam_matriz = -1;
	Xis x;

	x.linha = 3;
	x.coluna = 5;
	x.tam = 5;


	matrizIdentidade (matriz, tam_matriz);
	matriz [0] [6] = 1;
	matriz [1] [5] = 1;
	matriz [2] [4] = 1;
	//Elemento estranho
	matriz [1] [3] = 5;
	matriz [0] [3] = 5;
	matriz [3] [0] = 5;
	//Elemento estranho
	matriz [3] [3] = 1;
	matriz [4] [2] = 1;
	matriz [5] [1] = 1;
	matriz [6] [0] = 1;
	imprime_matriz (matriz, tam_matriz);
	printf ("%d", insereXis (matriz, tam_matriz, x));
	printf ("\n\n\n");
	imprime_matriz (matriz, tam_matriz);


	x = maiorXis (matriz, tam_matriz, 7, 10);

	printf ("\n\n(%d, %d, %d)\n\n", x.linha, x.coluna, x.tam);

	printf ("\n\nO numero de tentativas foi: %d", lerXis(&x, tam_matriz));

	printf ("\n\nA quantidade de letras repetidas na frase:\n'1, 2, 3 TestandO o #@1!!'\nEh: %d", 
		numCharsRepetidos ("1, 2, 3 TestandO o #@1!!"));

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

	printf("\n\n%d\n\n", estaContidoCirculoTriangulo (c, t));

	return 0;
}