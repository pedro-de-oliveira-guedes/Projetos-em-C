#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "redesocial.h"

void main() {
    int n;

    srand (time (NULL));

    popularRedeSocialAleatoriamente (0.6);

    imprimirRedeSocial ();

    n = numAmigosEmComum (2, 4);

    printf("\nnumero de amigos em comum entre 2 e 4: %d", n); //gabarito: 2


    //se voce eh forte, remova o comentario da linha abaixo

    printf("\ncoef. de aglomeracao da pessoa 2 eh: %.2f", coeficienteAglomeracao(2));

    //gabarito: 0.67 ***** (não é garantido, depende da ordem dos rands().
}
