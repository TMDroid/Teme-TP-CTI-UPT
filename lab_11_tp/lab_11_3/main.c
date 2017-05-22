#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct elem {
    char *c;
    struct elem *next;
} cuvant;

int main() {
    char buff[35];
    cuvant *start, *finish;
    start = NULL;

    printf("Introduceti cuvintele: ");
    while ((scanf("%33s", buff) != NULL) && strcmp(buff, "gata") != 0) {
        cuvant *c;
        c = (cuvant *) malloc(sizeof(cuvant));
        if (!c) return 0;

        c->c = strdup(buff);
        c->next = NULL;

        if (start == NULL) {
            start = finish = c;
        } else {
            finish->next = c;
            finish = c;
        }
    }

    printf("\n\nCuvintele introduse sunt: \n");

    cuvant *iterator;
    iterator = start;
    while (iterator != NULL) {
        printf(" - %s\n", iterator->c);
        iterator = iterator->next;
    }

}