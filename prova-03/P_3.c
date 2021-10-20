#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_TAM 100

FILE *arq;

//-----------------------------Questão 01-----------------------------
float somaSaldo(char nome_arquivo[], int filial, int ini, int fim){

	int i = 1;
	float valor_atual = 0, saldo = 0;
	char buf [MAX_TAM];

	arq = fopen (nome_arquivo, "r");

	if (arq == NULL || (filial < 1 || filial > 5) || fim < ini){

		printf ("Erro!");
		fclose (arq);
		return 0;
	}

	if (ini < 1)
		ini = 1;

	while (i <= fim){

		while (i < ini){

			fgets (buf, MAX_TAM, arq);
			i++;
		}
		fgets (buf, MAX_TAM, arq);
		for (int j = 1; j <= 5; j++){

			fscanf (arq, "%f", &valor_atual);
			if (j == filial){

				saldo += valor_atual;
				printf ("\n%.2f", saldo);
			}
		}

		if (feof (arq))
			break;

		i++;
	}

	fclose (arq);
	return saldo;
}


//-----------------------------Questão 02-----------------------------
float **carregaLista(char nome_arquivo[]){

	int num_linhas = 0, ano = 0, num_colunas = 0;
	int i = 0, j = 0;
	char mes [9];

	arq = fopen (nome_arquivo, "r");

	if (arq == NULL){

		fclose (arq);
		return NULL;
	}

	fscanf(arq, "%d\n", &num_linhas);
	float **M = (float**) malloc ((num_linhas + 1) * sizeof (float*));

	for (i = 0; i < num_linhas; i++){

		fscanf (arq, "%s", mes);
		fscanf (arq, "%d", &ano);
		fscanf (arq, "%d", &num_colunas);

		M[i] = (float *) malloc ((num_colunas + 1) * sizeof (float));

		for (j = 0; j < num_colunas; j++){

			fscanf (arq, "%f", &M[i][j]);
			printf ("%.2f |", M[i][j]);
		}

		M [i][num_colunas + 1] = 0;
		printf ("%.2f |", M[i][num_colunas + 1]);
		printf ("\n");
	}

	M[num_linhas+1] = NULL;
	printf ("%p", M[num_linhas+1]);

	fclose (arq);

	return M;
}


//-----------------------------Questão 03-----------------------------
float total_mensal (float *gastos){

	float total_mes = 0;

	if (*gastos == 0){
		return 0.0;
	}
	total_mes = *gastos + total_mensal (gastos+1);
	return total_mes;
}

float gasto_Mensal (float **gastos){

	float mes_um = 0;
	float mes_dois = 0;

	if (!(*gastos == NULL)){
		mes_um = total_mensal (*gastos);

		mes_dois = gasto_Mensal (gastos + 1);

		if (mes_um > mes_dois)
			return mes_um;
		else
			return mes_dois;
	}

	else
		return 0.0;	
}

float maiorGasto (float **gastos){

	return gasto_Mensal (gastos);
}


//-----------------------------Questão 04-----------------------------
typedef struct Empresa {
  float juros;
  float taxa;
}Empresa;

float juros_Compostos (float valor, int mes_atual, int total_meses, Empresa empresa){
	float juros_atual = 0, total_juros = 0;

	if (mes_atual == total_meses){
		valor *= empresa.juros;
		return valor;
	}

	juros_atual = valor*empresa.juros;

	total_juros = juros_atual + juros_Compostos (valor + juros_atual, mes_atual + 1, 
													total_meses, empresa);
	return total_juros;
}


float valorTotalEmprestimo(float valor, int m, Empresa empresa){

	int total_meses = m, mes_atual = 1;
	float novo_valor = 0;

	valor += empresa.taxa;

	novo_valor = valor + juros_Compostos (valor, mes_atual, total_meses, empresa);
	return novo_valor;
}


//-----------------------------Questão 05-----------------------------
int conta_abre_chaves (char *c, int abre_chaves){

	if (*c == '\0'){
		return 0;
	}

	abre_chaves += conta_abre_chaves (c + 1, abre_chaves);

	if (*c == '{')
		return abre_chaves + 1;

	return abre_chaves;
}

int conta_fecha_chaves (char *c, int fecha_chaves){

	if (*c == '\0'){
		return 0;
	}

	fecha_chaves += conta_fecha_chaves (c + 1, fecha_chaves);

	if (*c == '}')
		return fecha_chaves + 1;

	return fecha_chaves;
}

int diferencaChaves(char *programa){

	int abre_chaves = 0, fecha_chaves = 0;

	abre_chaves = conta_abre_chaves (programa, abre_chaves);
	fecha_chaves = conta_fecha_chaves (programa, fecha_chaves);

	return abre_chaves - fecha_chaves;
}

//-------------------------Imprimir Matriz------------------------------
void imprime_Matriz (float **M){
	int i = 0, j = 0;
	while (M[i] != NULL){
		while (M[i][j] != 0){
			printf (" %.1f |", M[i][j]);
			j++;
		}
		i++;
		printf ("\n");
	}
}


//-----------------------------Chamada das funções-----------------------------
int main(int argc, char const *argv[])
{

	//--------------------Questão 01-------------------------
	int filial = 0, ini = 0, fim = 0;

	printf ("\nDigite o numero da filial: ");
	scanf ("%d", &filial);
	printf ("\nDigite o dia inicial para o calculo: ");
	scanf ("%d", &ini);
	printf ("\nDigite o dia final para o calculo: ");
	scanf ("%d", &fim);

	printf("\n\nA soma dos saldos eh: %.2f\n\n\n\n", somaSaldo ("q_1.txt", filial, ini, fim));

	//--------------------Questão 02-------------------------
	float **M_gastos = NULL;

	M_gastos = carregaLista ("teste.txt");

	printf ("\n\n\n");
	imprime_Matriz (M_gastos);

	//--------------------Questão 03-------------------------
	float maior_Gasto = 0;

	maior_Gasto = maiorGasto (M_gastos);

	printf ("\n\nRodou!\n\n");
	printf ("\n\nOla: %.2f", maiorGasto (M_gastos));


	//--------------------Questão 04-------------------------
	float valor = 0;
	int meses = 0;
	Empresa empresa;

	printf ("Qual o valor voce gostaria de pedir de emprestimo? ");
	scanf ("%f", &valor);
	printf ("\nPretente pagar em quantos meses? ");
	scanf ("%d", &meses);
	printf ("\nQual a taxa cobrada pelo banco? ");
	scanf ("%f", &empresa.taxa);
	printf ("\nQual o percentual de juros cobrado pelo banco? ");
	scanf ("%f", &empresa.juros);

	printf ("\n\nO valor total do emprestimo eh: %.2f", valorTotalEmprestimo(valor, meses, empresa));

	//--------------------Questão 05-------------------------
	char *programa = "i{aa  {{ bcd}";

	printf ("\n\nA diferenca de chaves eh: %d", diferencaChaves (programa));

	return 0;
}