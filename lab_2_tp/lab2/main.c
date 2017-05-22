#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct concert {
    char trupa[100];
    char locatia[100];
    int luna, ziua;
};


int main(void)
{
    /* Pointer catre o structura. */
    struct concert *c;

    /* Alocam dinamic memorie. */
    c = (struct concert *) malloc(sizeof(struct concert));
    if (!c) {
        printf("Eroare alocare memorie.\n");
        exit(EXIT_FAILURE);
    }

    /* Initializam structura alocata cu niste date. */
    strcpy(c->trupa, "Phoenix");
    strcpy(c->locatia, "Filarmonica de Stat Banatul");
    c->luna = 3;
    c->ziua = 2;

    /* Afisam datele. */
    printf("%02d.%02d: %s - %s\n", c->luna, c->ziua,
           c->trupa, c->locatia);

    /* Eliberam memoria. */
    free(c);

    return 0;
}

