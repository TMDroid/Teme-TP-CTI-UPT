#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m, tabs = 0;
char caractere[20];
int indici[20];
FILE *out;

void tipareste()
{
  int i,print=1;
  for(i=1;i<=m-1;i++)
    if(indici[i-1]<indici[i]) print=0;
  if(print)
  {
    for(i = 0; i < tabs; i++) fprintf(out, "\t");
    fprintf(out, "{");
    for(i=m-1; i>=0; i--) {
        if(!i) {
            fprintf(out, "%c", caractere[indici[i]]);
        } else {
            fprintf(out, "%c, ", caractere[indici[i]]);
        }
    }
    fprintf(out, "}");
    fprintf(out, "\n");
  }
}

void comb_r(int k)
{
    int j;
    if (k == -1) {
        tabs++;
        tipareste();
        tabs--;
    }

    else {
        for (j = 0; j < n; j++) {
            indici[k] = j;
            comb_r(k - 1);
        }
    }
}

int main()
{
    int i;
    char buffer[28], alphabet[30] = {0};
    FILE *in = fopen("in.txt", "rt");
    if(!in) exit(EXIT_FAILURE);
    out = fopen("out.txt", "wt");
    if(!out) exit(EXIT_FAILURE);

    while(fgets(buffer, 28, in) != 0 && !feof(in)) {
        buffer[strlen(buffer) - 1] = 0;

        int i;
        for(i = 0; i < strlen(buffer); i++) {
            char c = buffer[i];
            if(isalpha(c)) {
                alphabet[c - 'a']++;
            }
        }
    }

    int length = 0;
    for(i = 0; i < 30; i++) {
        if(alphabet[i] != 0) {
            buffer[length++] = i + 'a';
        }
    }
    buffer[length] = 0;

    fclose(in);

    n = strlen(buffer);
    for (i = 0; i < n; i++)
        caractere[i] = buffer[i];
    printf("am citit %d caractere: ", n);
    for (i = 0; i < n; i++)
        printf("%c", caractere[i]);
    printf("\n");

    for(m = 1; m <= n; m++) {
        fprintf(out, "{\n");
        comb_r(m - 1);
        fprintf(out, "}\n\n");
    }

    fclose(out);
    return 0;
}
