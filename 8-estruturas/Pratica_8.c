#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_FACES 6

typedef struct Guerreiro{
    int ataque;
    int defesa;
    int carisma;
    int pontos_vida;
    int id_guerreiro;
} Guerreiro;

int rolaDados (){
    int soma = 0;

    for (int i = 0; i < 3; i++){
        soma += (1 + rand () % (NUM_FACES - 1 + 1));
    }

    return soma;
}

void criaGuerreiro (Guerreiro *guerreiro){

    guerreiro->ataque = rolaDados();
    printf ("\nAtaque: %d\n\n", guerreiro->ataque);
    guerreiro->defesa = rolaDados();
    printf ("\nDefesa: %d\n\n", guerreiro->defesa);
    guerreiro->carisma = rolaDados();
    printf ("\nCarisma: %d\n\n", guerreiro->carisma);

    guerreiro->pontos_vida = 0;

    for (int i = 0; i < 3; i++){
        guerreiro->pontos_vida += rolaDados();
    }

    printf ("\nPontos de vida: %d\n\n", guerreiro->pontos_vida);
}

int bonusCarisma (int carisma){
    if (carisma == 18) return 3;
    else if (carisma == 17 || carisma == 16) return 2;
    else if (carisma == 15 || carisma == 14) return 1;
    else if (carisma == 7 || carisma == 6) return -1;
    else if (carisma == 4 || carisma == 5) return -2;
    else if (carisma == 3) return -3;
    else return 0;
    
}

void ataca (Guerreiro *atacante, Guerreiro *defende){
    int soma_guerreiro1 = 0, soma_guerreiro2 = 0, dano = 0;

    soma_guerreiro1 = rolaDados () + atacante->ataque + bonusCarisma (atacante->carisma);

    printf ("\nAtaque guerreiro %d: (%d)", atacante->id_guerreiro, soma_guerreiro1);

    soma_guerreiro2 = rolaDados () + defende->ataque + bonusCarisma (defende->carisma);

    printf ("\nDefesa guerreiro %d: (%d)", defende->id_guerreiro, soma_guerreiro2);
    
    dano = soma_guerreiro1 - soma_guerreiro2;

    printf ("\nDano causado ao guerreiro %d: (%d)\n", defende->id_guerreiro, dano);

    if (dano > 0){
    
        if (defende->pontos_vida > dano){

            defende->pontos_vida -= dano;
        }
        else {
            defende->pontos_vida = 0;
            return;
        }
    }
    else{
        return;
    }

}

void jogo (){
    Guerreiro warrior_1, warrior_2;

    warrior_1.id_guerreiro = 1;
    warrior_2.id_guerreiro = 2;

    criaGuerreiro (&warrior_1);
    criaGuerreiro (&warrior_2);

    while (warrior_1.pontos_vida > 0 && warrior_2.pontos_vida > 0){

        ataca (&warrior_1, &warrior_2);

        printf ("\n\nVida restante guerreiro 2: (%d)", warrior_2.pontos_vida);

        if (warrior_2.pontos_vida == 0) break;

        ataca (&warrior_2, &warrior_1);

        printf ("\n\nVida restante guerreiro 1: (%d)", warrior_1.pontos_vida);

        if (warrior_1.pontos_vida == 0) break;
    }

    if (warrior_1.pontos_vida > 0){

        printf ("\n\n\n-----------\nVencedor: %d", warrior_1.id_guerreiro);

        printf ("\nPontos de vida restantes: %d\n\n", warrior_1.pontos_vida);
    }
    else if (warrior_2.pontos_vida > 0){

        printf ("\n\n\n------------\nVencedor: %d", warrior_2.id_guerreiro);

        printf ("\nPontos de vida restantes: %d\n\n", warrior_2.pontos_vida);
    }

}

int main (){

    srand (time (NULL));

    jogo ();

    return 0;
}