#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TAM_MAX 100
#define MIN_LIMITE 2

int random (int n){
    return rand () % n;
}

int randomInt (int min, int max){
    return min + random (max - min + 1);
}

//===============================Função de preenchimento de elementos da matriz=============================================

void preenche_matriz (int matriz [] [TAM_MAX], int m_linhas, int n_colunas, int k_limite){

    for (int i = 0; i<m_linhas; i++){
        for (int j = 0; j<n_colunas; j++){
            matriz [i] [j] = randomInt (1, k_limite);
        }
    }
}

//===============================Função de preenchimento de elementos da matriz=============================================


//===============================Função de impressão da matriz=============================================

void imprime_matriz (int matriz [] [TAM_MAX], int m_linhas, int n_colunas){

    printf ("\n\n");

    for (int i = 0; i<m_linhas; i++){
        for (int j = 0; j<n_colunas; j++){
            printf ("%3d ", matriz [i] [j]);
        }
        printf ("\n");
    }
}

//===============================Função de impressão da matriz=============================================


//======================================Função de "Backup" da matriz==================================================

void copia_matriz (int matriz [] [TAM_MAX], int matriz_mod [] [TAM_MAX], int m_linhas, int n_colunas){

    for (int i = 0; i<m_linhas; i++){
        for (int j = 0; j<n_colunas; j++){
            matriz_mod [i] [j] = matriz [i] [j];
        }
    }
}

//======================================Função de "Backup" da matriz==================================================


//==============================================Função de localização de sequências===============================================

void localiza_sequencia_de_3 (int matriz [] [TAM_MAX], int matriz_mod [] [TAM_MAX], int m_linhas, int n_colunas){
    int controle = 0, cont = 0;

    //----------------------------Esse bloco "for" realiza a busca nas linhas------------------------------
    for (int i = 0; i < m_linhas; i++){
        controle = matriz [i] [0];
        for (int j = 1; j < n_colunas; j++){
            if (controle == matriz [i] [j] && controle != 0){
                cont++;
            } else{
                controle = matriz [i] [j];
                cont = 0;
                continue;
            }
            if (cont >= 2){
                matriz_mod [i] [j] = 0;
                matriz_mod [i] [j-1] = 0;
                matriz_mod [i] [j-2] = 0;
            }
        }
        cont = 0;
    }
    //------------------------Esse bloco "for" realiza a busca nas linhas------------------------------

    //---------------------Esse bloco "for" realiza a busca nas colunas------------------------------
    for (int j = 0; j < n_colunas; j++){
        controle = matriz [0] [j];
        for (int i = 1; i < m_linhas; i++){
            if (controle == matriz [i] [j] && controle != 0){
                cont++;
            } else{
                controle = matriz [i] [j];
                cont = 0;
                continue;
            }
            if (cont >= 2){
                matriz_mod [i] [j] = 0;
                matriz_mod [i-1] [j] = 0;
                matriz_mod [i-2] [j] = 0;
            }
        }
        cont = 0;
    }
    //------------------------Esse bloco "for" realiza a busca nas colunas------------------------------

}

//==============================================Função de localização de sequências===============================================


//==============================================Função de contagem dos zeros===============================================

int conta_zeros (int matriz [] [TAM_MAX], int m_linhas, int n_colunas){
    int cont = 0;

    for (int i = 0; i<m_linhas; i++){
        for (int j = 0; j<n_colunas; j++){
            if (matriz [i] [j] == 0){
                cont ++;
            }
        }
    }
    return cont;
}

//==============================================Função de contagem dos zeros===============================================


//==============================================Função de transladar os zeros==================================================

void translada_zeros (int matriz_mod [] [TAM_MAX], int m_linhas, int n_colunas){
    int aux;

    for (int i = 0; i < m_linhas; i++){

        for (int j = 0; j < n_colunas; j++){
            if (matriz_mod [i] [j] == 0){

                for (int x = i - 1; x >= 0; x--){

                    aux = matriz_mod [x] [j];
                    if (aux == 0) break;

                    else{

                        matriz_mod [x] [j] = matriz_mod [x + 1] [j];
                        matriz_mod [x + 1] [j] = aux;
                    }
                }
            }
            
        }
    }
    
    
}

//==============================================Função de transladar os zeros==================================================