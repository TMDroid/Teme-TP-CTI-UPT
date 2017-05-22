#include <stdio.h>
#include <stdlib.h>

void die() { printf("Eroare in deschiderea fisierului!!"); exit(EXIT_FAILURE); }

int main(int argc, char *argv[])
{
    if(argc < 3) {
        printf("Numar insuficient de argumente!\n");
        printf("Usage: ./lastn <numar linii> <nume fisier text>\n");
        return 0;
    }

    char *srcname = "/var/log/syslog"; //de unde sa citeasca
    char *dstname = argv[2]; //in ce fisier sa puna
    int n = atoi(argv[1]); //cate randuri de la final
    char buff[10 * 1024];

    FILE *src, *dst;
    src = fopen(srcname, "rt");
    dst = fopen(dstname, "wt");
    if(!src || !dst) { die(); }


    //numarare linii in fisier
    int lines = 0;
    while(fgets(buff, 10 * 1024, src) && !feof(src)) {
        lines++;
    }


    fseek(src, 0, SEEK_SET);
    int counter = 0;

    while(fgets(buff, 10 * 1024, src) && !feof(src)) {
        if(counter >= lines - n) {
            fputs(buff, dst);
        }

        counter++;
    }

    fclose(src);
    fclose(dst);


    return 0;
}
