#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define printf __mingw_printf
//#define RAND_MAX 32767

double produto_escalar (int n_prod) {
    double vetor_u [100], vetor_v [100], prod = 0;

    for (int i = 0; i < n_prod; i++){
        printf ("\n\nDigite o valor atribuido a u [%d]: ", i);
        scanf ("%lf", &vetor_u[i]);
        printf ("\n\nDigite o valor atribuido a v [%d]: ", i);
        scanf ("%lf", &vetor_v[i]);
        fflush (stdin);
    }

    for (int i = 0; i < n_prod; i++){
        prod += (vetor_u[i] * vetor_v[i]);
    }

    return prod;
}

void fibonacci (){
    int n = 0;
    long double vet_fibonacci [1000];

    vet_fibonacci [0] = 1;
    vet_fibonacci [1] = 1;

    while (1){
        printf ("Qual termo da sequencia de fibonacci voce deseja saber? ");
        scanf ("%d", &n);

        if (n >= 0 && n <= 1000){

            for (int i = 2; i < n; i++){
                vet_fibonacci [i] = vet_fibonacci [i-1] + vet_fibonacci [i-2];
            }

        } else break;

        printf ("\n\nO termo %d eh: %.0Lf\n\n", n, vet_fibonacci [n-1]);
    }
}

float random_float (){
    return -1000000 + (float) rand() / RAND_MAX * 2000000;
}

int main (){
    int n_prod = 0, tam_vet = 0;
    float soma_vet = 0;
    double prod = 0;

    srand (time(NULL));
    
    printf ("\n---------------------------Exercicio 01---------------------------\n\n");
    printf ("Entre um tamanho n para os vetores: ");
    scanf ("%d", &n_prod);
    prod = produto_escalar (n_prod);
    printf ("\n\n O produto escalar dos dois vetores eh: %.2lf", prod);

    printf ("\n---------------------------Exercicio 02---------------------------\n\n");
    fibonacci ();

    printf ("\n---------------------------Exercicio 03---------------------------\n\n");
    printf ("Qual o tamanho do vetor? ");
    scanf ("%d", &tam_vet);

    float vetor_real_v [tam_vet];

    for (int i = 0; i < tam_vet; i++){
        vetor_real_v [i] = random_float ();
        soma_vet += vetor_real_v [i];
    }

    printf ("\n\nA soma dos elementos desse vetor eh: %.2f.\n", soma_vet);

    return 0;
}