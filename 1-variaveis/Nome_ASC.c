#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

void main(){
	char a, b, c, d, e;
	setlocale(LC_ALL, "Portuguese_Brasil");
	printf ("\n\n");
	printf ("Boa noite amigo Pedro! \n\nDigite seu primeiro nome e pressione ENTER\n\n Obs: Lembre-se que há diferenciação de letras maiúsculas e minúsculas\n");
	scanf ("%c", &a);
	scanf ("%c", &b);
	scanf ("%c", &c);
	scanf ("%c", &d);
	scanf ("%c", &e);
	printf ("Ele fica assim em código ASCII: %d \t %d \t %d \t %d \t %d", a, b, c, d, e);
}