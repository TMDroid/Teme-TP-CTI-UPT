#include <stdio.h>
#include <stdlib.h>

void die() {
    printf("Eroare la deschiderea fisierului!");
    exit(0);
}

void rerror() {
    printf("Eroare la citirea din fisier!");
    exit(0);
}

int main()
{
    FILE *in, *out;

    if((in = fopen("input", "rb")) == NULL) die();
    if((out = fopen("output", "wt")) == NULL) die();

    unsigned short w, h;

    if(fread(&w, sizeof(short), 1, in) == 0 ) rerror();
    if(fread(&h, sizeof(short), 1, in) == 0 ) rerror();

    int i, j;
    unsigned char c;
    for(i = 0; i < w; i++) {
        for(j = 0; j < h; j++) {
            if(fread(&c, sizeof(char), 1, in) == 0) rerror();

            if(c == 0) fputc(' ', out);
            else if(c == 255) fputc('#', out);
            else if(c <= 127) fputc('.', out);
            else fputc('o', out);
        }
        fputc('\n', out);
    }

    fclose(in);
    fclose(out);

    return 0;
}
