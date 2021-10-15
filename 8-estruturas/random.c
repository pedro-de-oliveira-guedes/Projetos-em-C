#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//Retorna um número aleatório entre 0 e 1 (ponto flutuante)
float randf(){
    return (float) rand() / RAND_MAX;
}

//Retorna um número ponto flutuante aleatório entre um "min" e um "max"
float randFloat(float min, float max){
    return min + randf() * (max - min);
}

//Retorna um número inteiro aleatório entre 0 e o parâmetro passado - 1 (n - 1)
int random (int n){
    return rand () % n;
}

//Retorna um número aleatório inteiro entre o mínimo e máximo passados à função
int randomInt (int min, int max){
    return min + random (max - min + 1);
}