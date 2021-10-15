#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "Funcoes_Ex_1.h"

#define TAM_MAX 100
#define MIN_LIMITE 2

int main (){
    srand (time (NULL));

    int matriz [TAM_MAX] [TAM_MAX], matriz_mod [TAM_MAX] [TAM_MAX];
    int m_linhas = 0, n_colunas = 0, k_limite = 0;
    int digitando = 1, controle = 0;

    while (digitando == 1){

        // =============================Passagem de parametros da matriz pelo usuário======================================
        printf ("\n\nOla! \nDigite o tamanho de linhas da matriz (entre 1 e %d): ", TAM_MAX);
        scanf ("%d", &m_linhas);

        printf ("\n\nDigite o numero de colunas da matriz (entre 1 e %d): ", TAM_MAX);
        scanf ("%d", &n_colunas);

        printf ("\n\nDigite o limite de geracao dos numeros aleatorios (minimo 2): ");
        scanf ("%d", &k_limite);
        // =============================Passagem de parametros da matriz pelo usuário======================================


        //=============================Avaliação de validade dos parâmetros======================================
        if (n_colunas > TAM_MAX || n_colunas <= 0 || m_linhas > TAM_MAX || m_linhas <= 0 || k_limite < MIN_LIMITE){
            printf ("\n\nUM DOS NUMEROS EH INVALIDO, TENTE NOVAMENTE!\n\n");
            continue;
        }
        //=============================Avaliação de validade dos parâmetros======================================

        digitando = 0;

    }

    preenche_matriz (matriz, m_linhas, n_colunas, k_limite);

    imprime_matriz (matriz, m_linhas, n_colunas);

    copia_matriz (matriz, matriz_mod, m_linhas, n_colunas);

    localiza_sequencia_de_3 (matriz, matriz_mod, m_linhas, n_colunas);

    imprime_matriz (matriz_mod, m_linhas, n_colunas);

    controle = conta_zeros (matriz_mod, m_linhas, n_colunas);

    printf ("\nA quantidade de zeros nessa matriz eh: %d\n\n", controle);

    translada_zeros (matriz_mod, m_linhas, n_colunas);

    imprime_matriz (matriz_mod, m_linhas, n_colunas);

    while (1){

        copia_matriz (matriz_mod, matriz, m_linhas, n_colunas);

        localiza_sequencia_de_3 (matriz, matriz_mod, m_linhas, n_colunas);

        if (controle == conta_zeros (matriz_mod, m_linhas, n_colunas)) break;

        else controle = conta_zeros (matriz_mod, m_linhas, n_colunas);

        translada_zeros (matriz_mod, m_linhas, n_colunas);

    }

    imprime_matriz (matriz_mod, m_linhas, n_colunas);

    return 0;
}