#include <stdio.h>
#include <values.h>

#define MAX_PUNCTE 20

int n, puncte[MAX_PUNCTE];
int min_c1, min_c2;

void back(int stanga, int dreapta, int *m, int *c1, int *c2) {
    int mijloc, cifra1s, cifra1d, cifra2s, cifra2d;
    int min_st = *m;
    int min_dr = *m;

    printf("Caut minim in secventa [%d; %d]\n", stanga, dreapta);

    if(stanga == dreapta) {
        *m = puncte[stanga];
    } else if(stanga == dreapta - 1) {
        if(puncte[dreapta] - puncte[stanga] < *m) {
            *m = puncte[dreapta] - puncte[stanga];
            *c1 = stanga;
            *c2 = dreapta;
        }
    } else {
        mijloc = (stanga + dreapta) / 2;
        back(stanga, mijloc, &min_st, &cifra1s, &cifra2s);
        back(mijloc, dreapta, &min_dr, &cifra1d, &cifra2d);

        if(min_st < min_dr) {
            *m = min_st;
            *c1 = cifra1s;
            *c2 = cifra2s;
        } else {
            *m = min_dr;
            *c1 = cifra1d;
            *c2 = cifra2d;
        }
    }

}

int main() {
    int i;
    FILE *in = fopen("puncte.in", "rt");
    if(!in) return 0;

    fscanf(in, "%d", &n);

    for(i = 0; i < n; i++) {
        int temp;
        fscanf(in, "%d", &temp);
        puncte[i] = temp;
    }

    int min = INT_MAX, c1, c2;
    back(0, n-1, &min, &c1, &c2);

    printf("\nMinimul este %d surprins intre pozitiile %d si %d\n", min, c1, c2);
}