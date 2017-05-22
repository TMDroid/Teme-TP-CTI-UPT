#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DIFF 97
#define LITERE 26

typedef struct {
    char value;
    int freq;
} litera;

void die() { printf("Eroare in deschiderea fisierului!!\n\n"); exit(EXIT_FAILURE); }


int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("Numar insuficient de argumente!\n");
        printf("Usage: ./frec <nume fisier text>\n");
        return 0;
    }

    FILE *f;
    char *name = argv[1];
    f = fopen(name, "rt");
    if(!f) { die(); }

    char c;
    int i, j;
    litera litere[26];

    //initializare
    for(i = 0; i < LITERE; i++) {
        litere[i].value = i + DIFF;
        litere[i].freq = 0;
    }

    //procesare
    while((c = fgetc(f)) && c != EOF) {
        if(isalpha(c)) {
            c = tolower(c) - DIFF;
            litere[c].freq++;
        }
        //printf("%c\n", c);
    }

    //ordonare
    for(i = 0; i < LITERE - 1; i++) {
        for(j = i+1; j < LITERE; j++) {
            if(litere[i].freq < litere[j].freq) {
                litera l = litere[i];
                litere[i] = litere[j];
                litere[j] = l;
            }
        }
    }

    printf("\n\n");
    printf("Frecventa literelor in fisierul \"%s\" este: \n", name);
    for(i = 0; i < LITERE; i++) {
        printf("%c \t %d\n", litere[i].value, litere[i].freq);
    }

    fclose(f);

    return 0;
}
