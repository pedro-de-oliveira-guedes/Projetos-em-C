#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "redesocial.h"


int M[NUM_PESSOAS][NUM_PESSOAS];


void inicializar_rede () {
    for (int i = 0; i < NUM_PESSOAS; i++){
        
        for (int j = 0; j < NUM_PESSOAS; j++){

            M [i] [j] = 0;
        }
    }
}

void adicionar_amizade (int i, int j) {

    M [i] [j] = 1;
    M [j] [i] = 1;
}

float random_float () {

    return (float) rand() / RAND_MAX;
}

void popularRedeSocialAleatoriamente (float P) {
    float r = 0;
    int vetor [NUM_PESSOAS];

    inicializar_rede ();

    for (int i = 0; i < NUM_PESSOAS; i++) vetor [i] = 0;

    for (int i = 0; i < NUM_PESSOAS; i++){

        for (int j = 0; j < NUM_PESSOAS; j++){

            if (i == j) continue;

            if (vetor [j] == 1) continue;

            r = random_float();

            if (r < P) adicionar_amizade (i, j);

        }

        vetor [i] = 1;
    }
}

void imprimirRedeSocial () {

    for (int i = 0; i < NUM_PESSOAS; i++){

        for (int j = 0; j < NUM_PESSOAS; j++){

            printf ("%3d", M [i] [j]);
        }
        printf ("\n");
    }
}

int numAmigosEmComum (int v, int u) {
    int contador = 0;

    for (int i = 0; i < NUM_PESSOAS; i++){

        if (M [v] [i] == M [u] [i] && M [v] [i] != 0){
            printf ("\nAmigo %d eh comum!", i);
            contador++;
        }
    }
    printf ("\n");

    return contador;
}

float coeficienteAglomeracao(int i){
    int n = 0, cont = 0;

    for (int j = 0; j < NUM_PESSOAS; j++){

        if (M [i] [j] == 1) {

            n++;
            cont += numAmigosEmComum (i, j);
        }
    }

    return (((float) cont / 2) / ((float) n * ((float) n-1) / 2));
}