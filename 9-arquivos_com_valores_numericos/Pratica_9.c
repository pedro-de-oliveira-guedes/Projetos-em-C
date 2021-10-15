#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_BILHETE 6
#define VALOR_MAX_BILHETE 100

//Os números sorteados foram: 6, 9, 22, 23, 48, 52

//Números do seriado Lost, que são: 4, 8, 15, 16, 23, 42

void ordena_por_bubble (int bilhete [TAM_BILHETE]){
    int trocou = 0, aux = 0;

    while (true){
        
        trocou = 0;
            
        for (int i = 0; i < TAM_BILHETE - 1; i++){
        
            if (bilhete [i] > bilhete [i+1]){
                aux = bilhete [i];
                bilhete [i] = bilhete [i+1];
                bilhete [i+1] = aux;
                trocou = 1;
            }
        }
        
        if (trocou == 0)
            break;
    }
}

int main (){
    FILE *arq;
    int bilhete [TAM_BILHETE];
    int resultado [TAM_BILHETE] = {6, 9, 22, 23, 48, 52};
    int lost [TAM_BILHETE] = {4, 8, 15, 16, 23, 42};

    int aux = 0, trocou = 0, resultado_igual = 0, lost_igual = 0;

    int quadra = 0, quina = 0, num_acertos = 0;

    arq = fopen ("cartelas.txt", "r");

    while(!feof(arq)){
        int i = 0;
        num_acertos = 0;

        for (int cont = 0; cont < TAM_BILHETE; cont++){
            fscanf(arq, "%d", &bilhete[cont]);
            //printf("\nli: %d", n);
        }

        ordena_por_bubble (bilhete);

//=*=*=*=*=*=*=*=Comparação com o bilhete de resultado=*=*=*=*=*=*=*=
        for (i = 0; i < TAM_BILHETE; i++){
            if (bilhete [i] != resultado [i]){
                break;
            }
        }

        for (int cont = 0; cont < TAM_BILHETE; cont++){
            for (int cont_aux = 0; cont_aux < TAM_BILHETE; cont_aux++){
                if (bilhete [cont] == resultado [cont_aux]){
                    num_acertos++;
                    break;
                }
            }
        }

        if (i == TAM_BILHETE){
            resultado_igual++;
        }

        else if (num_acertos == 4){
            quadra++;
        }

        else if (num_acertos == 5){
            quina++;
        }

//=*=*=*=*=*=*=*=Vê se há uma completa igualdade entre o bilhete e o resultado de LOST:=*=*=*=*=*=*=*=
        for (i = 0; i < TAM_BILHETE; i++){
            if (bilhete [i] != lost [i]){
                break;
            }
        }

        if (i == TAM_BILHETE){
            lost_igual++;
        }

    }

    fclose (arq);

    printf ("Houveram %d ganhadores da loteria!\n\n", resultado_igual);
    printf ("Houveram %d bilhetes com numeros iguais a LOST!\n\n", lost_igual);
    printf ("Houveram %d ganhadores da quadra!\n\n", quadra);
    printf ("Houveram %d ganhadores da quina!\n\n", quina);

    return 0;
}