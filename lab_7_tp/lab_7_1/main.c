#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F_NAME "a.txt"
#define LINE_L 256

#define PRAG_VARSTA 20
#define NR_MELODII 5
#define SEX_M "m"
#define SEX_F "f"

typedef struct {
    char *titlu;
    int frecv;
} melodie;

typedef struct {
    char *nume;
    char sex;
    int varsta;
    char** melodii[NR_MELODII];
} persoana;


melodie *melodii = NULL;
persoana *persoane = NULL;
int numar_melodii = 0, numar_persoane = 0;


void citire();
int citeste_persoana();
int adauga_melodie(char *);
int cauta_melodie(char *);

void calculare_top();
void calculare_liste();
void afisare();
void ordonare_crescator_melodii();

int main()
{
    melodii = (melodie *) malloc(numar_melodii * sizeof(melodie));
    persoane = (persoana *) malloc(numar_persoane * sizeof(persoana));

    citire();
    calculare_top();
    afisare();
    calculare_liste();

    free(melodii);
    free(persoane);
    return 0;
}

void citire() {
    FILE *f = fopen(F_NAME, "rt");
    if(!f) {
        printf("Eroare in deschiderea fisierului!");
        exit(EXIT_FAILURE);
    }

    int done = 0;

    while(!done) {
        done = citeste_persoana(f);
    }

    fclose(f);
}

int citeste_persoana(FILE *f) {
    char buff[LINE_L];

    if(NULL == fgets(buff, LINE_L, f)) {
        return 1;
    }
    buff[strlen(buff)-1] = 0;

    int i, spaces = 0;
    for(i = 0; i < strlen(buff); i++) {
        if(!isspace(buff[i])) {
            break;
        } else {
            spaces++;
        }
    }
    if(spaces == strlen(buff)) return 1;

    persoana p;
    p.nume = strdup(buff);
    fgets(buff, LINE_L, f);
    p.sex = buff[0];
    fgets(buff, LINE_L, f);
    p.varsta = atoi(buff);

    for(i = 0; i < NR_MELODII; i++) {
        fgets(buff, LINE_L, f);
        buff[strlen(buff) - 1] = 0;

        adauga_melodie(buff);
        p.melodii[i] = strdup(buff);
    }

    numar_persoane++;
    persoana *pers = (persoana *) realloc(persoane, numar_persoane * sizeof(persoana));
    if(!pers) {
        printf("Eroare de realocare dinamica");
        exit(EXIT_FAILURE);
    }
    persoane = pers;
    persoane[numar_persoane - 1] = p;

    return 0;
}

int adauga_melodie(char *nume) {
    int m = cauta_melodie(nume);
    if(m != -1) return m;

    //cod pentru adaugarea unei noi melodii
    melodie tempmel;
    tempmel.titlu = strdup(nume);
    tempmel.frecv = 1;

    numar_melodii++;
    melodie *mel = (melodie *) realloc(melodii, numar_melodii * sizeof(melodie));
    if(!mel) {
        printf("Eroare de realocare dinamica");
        exit(EXIT_FAILURE);
    }

    melodii = mel;
    melodii[numar_melodii - 1] = tempmel;

    return numar_melodii - 1;
}

int cauta_melodie(char *nume) {
    int i;
    for(i = 0; i < numar_melodii; i++) {
        if(strcmp(nume, melodii[i].titlu) == 0) {
            melodii[i].frecv++;
            return i;
        }
    }

    return -1;
}



void calculare_top() {
    ordonare_crescator_melodii();
}

void calculare_liste() {
    int i;

    printf("Baieti 20-: \n");
    for(i = 0; i < numar_persoane; i++) {
        persoana p = persoane[i];

        if(p.sex == 'm' && p.varsta < 20) {
            char* pref = p.melodii[0];
            if(strcmp(pref, melodii[0].titlu) == 0 ||
                strcmp(pref, melodii[1].titlu) == 0 ||
                strcmp(pref, melodii[2].titlu) == 0 ) {
                    printf("%s -> %s\n", p.nume, p.melodii[0]);
                }
        }
    }

    printf("\nBaieti 20+: \n");
    for(i = 0; i < numar_persoane; i++) {
        persoana p = persoane[i];

        if(p.sex == 'm' && p.varsta > 20) {
            char* pref = p.melodii[0];
            if(strcmp(pref, melodii[0].titlu) == 0 ||
                strcmp(pref, melodii[1].titlu) == 0 ||
                strcmp(pref, melodii[2].titlu) == 0 ) {
                    printf("%s -> %s\n", p.nume, p.melodii[0]);
                }
        }
    }

    printf("\nFete 20-: \n");
    for(i = 0; i < numar_persoane; i++) {
        persoana p = persoane[i];

        if(p.sex == 'f' && p.varsta < 20) {
            char* pref = p.melodii[0];
            if(strcmp(pref, melodii[0].titlu) == 0 ||
                strcmp(pref, melodii[1].titlu) == 0 ||
                strcmp(pref, melodii[2].titlu) == 0 ) {
                    printf("%s -> %s\n", p.nume, p.melodii[0]);
                }
        }
    }

    printf("\nFete 20+: \n");
    for(i = 0; i < numar_persoane; i++) {
        persoana p = persoane[i];

        if(p.sex == 'f' && p.varsta > 20) {
            char* pref = p.melodii[0];
            if(strcmp(pref, melodii[0].titlu) == 0 ||
                strcmp(pref, melodii[1].titlu) == 0 ||
                strcmp(pref, melodii[2].titlu) == 0 ) {
                    printf("%s -> %s\n", p.nume, p.melodii[0]);
                }
        }
    }
}

void afisare() {
    int i;
    printf("Topul celor mai populare melodii: \n\n");
    for(i = 0; i < numar_melodii; i++) {
        melodie mel = melodii[i];

        printf("   %d.%s: %d\n",i+1, mel.titlu, mel.frecv);
    }

    printf("\n\n");
}

void ordonare_crescator_melodii() {
    int i, j;
    for(i = 0; i < numar_melodii - 1 ; i++) {
        for(j = i + 1; j < numar_melodii; j++) {
            if(melodii[i].frecv < melodii[j].frecv) {
                melodie temp = melodii[i];
                melodii[i] = melodii[j];
                melodii[j] = temp;
            }
        }
    }
}

