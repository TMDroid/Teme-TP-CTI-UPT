#include<stdio.h>
#include<string.h>

#define HEIGHT 80
#define WIDTH 20

#define SELECTOR_PATH -1
#define SELECTOR_WALL 0
#define SELECTOR_START 8

int lab[HEIGHT][WIDTH];
int m, n;
int istart, jstart;

int di[] = {-1, 0, 1, 0}, dj[] = {0, -1, 0, 1};

//verific daca casuta curenta e fix pe margine
int check(int i, int j) {
    return (i == 0) || (i == n-1) || (j == 0) || (j == m-1);
}

void afisare() {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("\t%d ", lab[i][j]);
        }

        printf("\n");
    }
    printf("\n\n");
}

void back(int i, int j, int pos) {
    int l;

    for(l = 0; l < 4; l++) {
        int ti = i + di[l];
        int tj = j + dj[l];

        if((ti >= 0) && (ti < n) && (tj >= 0) && (tj < m)) {
            if(lab[ti][tj] == -1) { //daca e pe 1 inseamna ca pot sa merg pe el pentru ca nu e perete
                lab[ti][tj] = pos; //am encodat deplasarea pe o casuta cu un numar reprezentand numarul mutarii

                if(check(ti,tj)) {
                    afisare();
                }

                back(ti, tj, pos+1);
            }
        }
    }

}

int main() {

    FILE *in = fopen("labirint.dat", "rt");
    if(!in) return 0;

    char buffer[WIDTH];
    fgets(buffer, WIDTH, in);
    buffer[strlen(buffer) - 1] = 0;
    m = strlen(buffer);

    int i = 0, j;
    do {

        for(j = 0; j < m; j++) {

            if(buffer[j] == 'P') { lab[i][j] = SELECTOR_WALL; }
            else if(buffer[j] == '.') { lab[i][j] = SELECTOR_PATH; }
            else if(buffer[j] == 'S') {
                lab[i][j] = SELECTOR_START; //buffer[i] == 'S'
                istart = i;
                jstart = j;
            }
        }

        n++; i++;

    } while(fgets(buffer, WIDTH, in) != 0 && !feof(in));

    afisare();

    lab[istart][jstart] = 1;
    back(istart, jstart, 2);
}
