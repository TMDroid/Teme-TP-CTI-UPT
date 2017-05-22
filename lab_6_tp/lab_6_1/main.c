#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float price;
    char name[100];
} produs;

void die() {
    printf("Eroare la deschiderea fisierului!");
    exit(0);
}

void rerror() {
    printf("Eroare la citirea din fisier!");
    exit(0);
}

void scriere() {
    getchar();
    produs produse[100];
    char name[100];
    float price;
    int counter = 0, i;

    //citirea datelor
    printf("Introduceti numele produsului: ");
    while(fgets(name, 100, stdin) != 0 && strcmp(name, "\n") != 0) {
        name[strlen(name) - 1] = 0;

        printf("Introduceti pretul produsului: ");
        scanf("%f", &price);

        strcpy(produse[counter].name, name);
        produse[counter].price = price;
        counter++;

        printf("Introduceti numele produsului: ");
        getchar();
    }

    //scrierea in fisier
    FILE *f;
    f = fopen("products.txt", "w+b");
    if(!f) die();

    for(i = 0; i < counter; i++) {
        produs p = produse[i];

        char length = strlen(p.name);

        fwrite(&length, sizeof(char), 1, f);
        fwrite(p.name, sizeof(char), length, f);
        fwrite(&p.price, sizeof(float), 1, f);
    }

    fclose(f);

}

void citire() {
    //scrierea in fisier
    FILE *f;
    f = fopen("products.txt", "rb");
    if(!f) die();

    size_t current, end;
    fseek(f, 0, SEEK_END);
    end = ftell(f);
    fseek(f, 0 , SEEK_SET);
    current = ftell(f);

    while(current < end) {
        char size;
        if(fread(&size, sizeof(char), 1, f) == 0) rerror();

        char name[size];
        if(fread(&name, sizeof(char), size, f) == 0) rerror();
        name[size] = NULL;

        float price;
        if(fread(&price, sizeof(float), 1, f) == 0) rerror();

        printf("Produsul < %s > costa %.2f lei\n", name, price);

        current = ftell(f);
    }



}

int main()
{
    printf("Introduceti optiunea dorita: \n");
    printf("1. Introducere date si scriere in fisier\n");
    printf("2. Citire date din fisier\n\n");

    char a;
    scanf("%c", &a);

    switch(a) {
        case '1':
            scriere();
        break;
        case '2':
            citire();
        break;
        default: exit(0);

    }

    return 0;
}
