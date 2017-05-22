#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMES 10000000

int factorial_recursiv(int);

int factorial_iterativ(int);

double calculeaza_timp(clock_t one, clock_t two) {
    return (double) (two - one) / (double) CLOCKS_PER_SEC;
}

int main()
{
    int i, n = 30;
    clock_t it1, it2, rec1, rec2;

    printf("Introduceti numarul pe care vreti sa testati programul: ");
    scanf("%d", &n);

    printf("Calculez factorial iterativ...\n");
    it1 = clock();
    for(i = 0; i < TIMES; i++) factorial_iterativ(n);
    it2 = clock();
    printf("Operatiunea a durat %lf secunde\n", calculeaza_timp(it1, it2));

    printf("Calculez factorial recursiv...\n");
    rec1 = clock();
    for(i = 0; i < TIMES; i++) factorial_recursiv(n);
    rec2 = clock();
    printf("Operatiunea a durat %lf secunde\n", calculeaza_timp(rec1, rec2));
}

int factorial_recursiv(int n) {
    if(n == 1) return 1;

    return n * factorial_recursiv(n-1);
}

int factorial_iterativ(int n) {
    int i, f=1;

    for(i = 1; i <= n; i++) {
        f *= i;
    }

    return f;
}
