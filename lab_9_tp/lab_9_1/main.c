#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N_MAX 30

int n;
int mat[N_MAX][N_MAX];
int marcat[N_MAX];
int sters[N_MAX];

void alege(int *min, int *i_min, int *j_min) {
    int i, j;

    *min = INT_MAX;

    for(i = 0; i < n; i++) {
        if(marcat[i]) {

            for(j = 0; j < n; j++) {

                if(!sters[j] && mat[i][j] < *min && mat[i][j]) {
                    *i_min = i;
                    *j_min = j;
                    *min = mat[i][j];
                }
            }
        }
    }

    if(*min == INT_MAX) {
        *min = 0;
    }
}

int main()
{
    FILE *in = fopen("in.txt", "rt");
    if(!in) exit(EXIT_FAILURE);

    int i, j, gata = 0, min, i_min, j_min, cost_total = 0, temp;
    int arbore[N_MAX][2];
    int count=0;

    fscanf(in, "%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            fscanf(in, "%d", &temp);
            mat[i][j] = temp;
        }
    }

    for(i = 0; i < N_MAX; i++) {
        marcat[i] = 0;
        sters[i] = 0;
    }
    marcat[0] = 1;
    sters[0] = 1;

    while(!gata)
    {
        alege(&min,&i_min,&j_min);
        cost_total += min;

        marcat[j_min] = 1;
        sters[j_min] = 1;

        arbore[count][0] = i_min;
        arbore[count][1] = j_min;
        count++;

        if(count >= n) gata=1;
    }

    for(i = 0; i < count-1; i++) {
        printf("Din orasul %d in orasul %d.\n", arbore[i][0], arbore[i][1]);
    }

    printf("Cost total: %d\n",cost_total);

    fclose(in);
}

