#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define clear() printf("\033[H\033[J")

typedef struct {
    char cuvant[20];
    char *def;
} definitie;

void afisare_meniu();
void citeste_definitie(definitie *);
int cauta_definitie(definitie *, int, char *);
void die() { printf("Allocation error!!"); exit(0); }

int main()
{
    definitie *dictionar;
    int asize = 0;
    char input;

    dictionar = (definitie *) malloc(asize * sizeof(definitie));
    if(!dictionar) die();

    afisare_meniu();
    printf("Introduceti o optiune: ");
    scanf("%c", &input);
    while(!strchr("Tt", input)) {
        switch(input) {
            case '1':; //inserare cuvant
                definitie d;
                citeste_definitie(&d);
                asize++;

                dictionar = (definitie *) realloc(dictionar, asize * sizeof(definitie));
                if(!dictionar) die();
                dictionar[asize - 1] = d;
                clear();
            break;
            case '2': //afisare statistici
                clear();
                printf("/************************************************************\n");
                printf("Statistici dictionar: \n");
                printf("Dictionarul contine %d cuvinte\n\n", asize);
                int i;
                for(i = 0; i < asize; i++) {
                    definitie d = dictionar[i];
                    printf("%s \t= %s\n", d.cuvant, d.def);
                }
                printf("\n\n");
                getc(stdin);

            break;
            case '3':; //cauta definitie
                char cuvant[20];
                clear();
                printf("/************************************************************\n");
                printf("Cauta cuvant in dictionar: \n");
                printf("Ce cuvant doriti sa cautati in dictionar? \n");
                scanf("%s", &cuvant);

                int index = cauta_definitie(dictionar, asize, cuvant);
                if(index == -1) {
                    printf("Cuvantul cautat nu a fost gasit :(\n\n");
                } else {
                    definitie def = dictionar[index];
                    clear();
                    printf("Ati cautat cuvantul \"%s\"\n", cuvant);
                    printf("Definitie gasita: \n");
                    printf("%s \t= %s\n", def.cuvant, def.def);
                }
                getc(stdin);
            break;
            case '4':; //verificare propozitie
                getc(stdin);
                char text[500];
                clear();
                printf("Introduceti propozitia pentru a fi scanata si afisate cuvintele gresite: \n");
                fgets(text, 500, stdin);
                text[strlen(text) - 1] = 0;

                printf("Cuvinte care nu se afla in dictionar: \n");
                char *p = strtok(text, " ,.");
                while(p) {
                    if(cauta_definitie(dictionar, asize, p) == -1) printf("%s\n", p);
                    p = strtok(NULL, " ,.");
                }
            break;
        }

        afisare_meniu();
        scanf(" %c", &input);
    }

    free(dictionar);

    return 0;
}

void citeste_definitie(definitie *d) {
    char a[20], p[1000];
    printf("\n\nCe cuvant vreti sa introduceti in dictionar?\n");
    scanf("%20s", a); getchar();
    printf("Introduceti insemnatatea cuvantului \"%s\": ", a);
    fgets(p, 1000, stdin);

    int size = strlen(p);
    p[size - 1] = 0;

    d->def = (char *) malloc(size * sizeof(char));

    strcpy(d->cuvant, a);
    strcpy(d->def, p);
}

int cauta_definitie(definitie *dictionar, int size, char *cuvant) {
    int i;
    for(i = 0; i < size; i++) {
        definitie d = dictionar[i];
        if(strcmp(d.cuvant, cuvant) == 0) {
            return i;
        }
    }

    return -1;
}

void afisare_meniu() {
    printf("\n\n");
    printf("/************************************************************\n");
    printf("1. Intorducere cuvant\n");
    printf("2. Statistici dictionar\n");
    printf("3. Cautare definitie\n");
    printf("4. Verificare propozitie\n");
    printf("T. Terminare\n");
}
