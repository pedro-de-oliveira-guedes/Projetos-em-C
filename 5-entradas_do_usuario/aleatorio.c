#include <stdio.h>
#include <math.h>
#include <string.h>

double fatorial(int i){
	double fact = 1;
	
	for	(int j = 1; j <= i; j++){
		fact = fact * j;
	}
	
	return fact;
}

double euler (){
	double e = 1, e_aux = 1, limite = pow (10, -6);
	int i = 0;
	
	while (e_aux > limite){
		i++;
		e_aux = 1 / fatorial (i);
		e += e_aux;
	}
	
	return e;
}

void conceito (){
	int nota;
	char letra;
	
	printf ("Qual a nota do aluno?");
	scanf ("%d", &nota);
	
	switch (nota){
		case 0: 
			letra = 'F';
			break;
		case 1:  
			letra = 'F';
			break;
		case 2: 
			letra = 'F';
			break;
		case 3: 
			 letra = 'F';
			 break;
		case 4: 
			letra = 'F';
			break;
		case 5: 
			letra = 'E';
			break;
		case 6: 
			letra = 'D';
			break;
		case 7: 
			letra = 'C';
			break;
		case 8: 
			letra = 'B';
			break;
		case 9: 
			letra = 'A';
			break;
		case 10: 
			letra = 'A';
			break;
		default: 
			letra = 'X';
	}
	printf ("O conceito do aluno eh: %c\n\n\n", letra);
}

void floyd (){
	int cont = 0, num = 0, N;
	scanf ("%d", &N);
	printf ("\n\n");
	for (int i = 1; i <= N; i++){

		while (cont < i){
			num++;
			printf ("%d ", num);
			cont++;
		}
		
		if (cont == i){
			printf ("\n");
			cont = 0;
		}
		
	}
}

void floyd_mod (){
	int cont = 0, num = 0, N;
	scanf ("%d", &N);
	printf ("\n\n");
	for (int i = 1; i <= N; i++){

		while (cont < i){
			num++;
			
			if (i == N){
			    while (cont < i){
			        printf ("%d ", num);
			        num++;
			        cont++;
		        }
		    }
			cont++;
		}
		if (cont == i) cont = 0;
	}
}

int tamanho (){
	int cont = 0;
	char linha[128];
	printf("Digite uma linha:\n");
	fflush (stdin);
	fgets(linha, 128, stdin);
	
	for (int i = 0; i <= 128; i++){
		if (linha [i] != '\0' && linha [i] != '\n') cont ++;
		else return cont;
	}
}

void converte (){
	char linha[1000];
	printf("Digite uma linha:\n");
	fflush (stdin);
	fgets(linha, 1000, stdin);
	
	for (int i = 0; i <= 1000; i++){
		if (linha [i] >= 97 && linha [i] <= 122) linha [i] -= 32;
	}
	printf ("%s", linha);
}

void palindromos (){
	int tam = 0, pa = 0;
	char palavra[30];
	
	printf("Digite uma palavra:\n");
	fflush (stdin);
	fgets(palavra, 30, stdin);
	
	tam = strlen (palavra) - 1;
	
	for (int i = 0; i <= tam/2; i++){
		if (palavra [i] != palavra [tam-i-1]) {
			printf ("\n\nNao eh palindromo!\n");
			pa = 1;
			break;
		}
	}
	
	if (pa == 0) printf ("\n\nEh palindromo!\n");
}

void inverte (){
	int tam = 0, pos = 0;
	char frase[300], c, inversa [300];
	
	printf("Digite uma frase: ");
	fflush (stdin);
	
    do{
		c = getc (stdin);
		frase[pos] = c;
		pos++;
		tam++;
	} while (c != '.');
	
	for (int i = 0; i<=tam; i++){
		inversa [i] = frase [tam-i-1];
	}
	
	printf ("%s", inversa);
}

void abrevia (){
	int tam = 0, pos = 0;
	char nome[60], c;
	
	printf("Digite um nome completo: ");
	fflush (stdin);
	
    do{
		c = getc (stdin);
		nome[pos] = c;
		pos++;
		tam++;
	} while (c != '.');
	
	for (int i = 0; i<=tam; i++){
		if (nome [i] >= 65 && nome [i] <= 90){
			printf ("%c.", nome[i]);
		}
	}
}

void abrevia_mod (){
	int tam = 0, pos = 0;
	char nome[60], c;
	
	printf("Digite um nome completo: ");
	fflush (stdin);
	
    do{
		c = getc (stdin);
		nome[pos] = c;
		pos++;
		tam++;
	} while (c != '.');
	
	for (int i = 0; i <= tam; i++){
		if (nome [i] >= 65 && nome [i] <= 90) nome [i] += 32;
	}
	
	for (int i = 0; i<=tam; i++){
		if (nome [i] >= 97 && nome [i] <= 122 && nome [i-1] == 32){
			nome [i] -= 32;
		}
	}
	
	if (nome [0] >= 97 && nome [0] <= 122) nome [0] -= 32;
	
	for (int i = 0; i<=tam; i++){
		if (nome [i] >= 65 && nome [i] <= 90){
		    if (nome [i] == 'D' && (nome [i+1] == 'e' || nome [i+1] == 'o' || nome [i+1] == 'a') && (nome [i+2] == 's' || nome [i+2] == 32)) continue;
			printf ("%c.", nome[i]);
		}
	}
}