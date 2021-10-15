float parteInteira (float x){
    x = (int) x;
    return x;
}

float parteFracionaria (float x){
    x -= (int) x;
    return x;
}

float divInts (int x, int y){
    float z = (float) x / (float) y;
    return z;
}

void soma1 (int *x){
    *x = *x + 1;
}

void troca (float *end_valor1, float *end_valor2){
    float end_valor3 = *end_valor1;
    *end_valor1 = *end_valor2;
    *end_valor2 = end_valor3;
}

unsigned long long fast_pow_2 (int expoente){
    return (unsigned long long int) 1 << expoente;
}

int ddd (unsigned int number){
    return number / (unsigned int) 100000000;
}

int soma1SePar (unsigned int number){
    return number | (unsigned int) 1;
}

int parOuImpar (unsigned int number){
    return !(number & (unsigned int) 1);
}