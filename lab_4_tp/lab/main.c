#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mysin(double x) { return sin(x); }
double mycos(double x) { return cos(x); }
double mysincos(double x) { return sin(x) * cos(x); }
double myxpow2(double x) { return x*x; }
double to_degrees(double radians) {
    return radians * (180.0 / M_PI);
}

void tabelare(double (*f1) (x), double (*f2) (x), double (*f3) (x), double (*f4) (x), int a, int b, double pas) {
    printf("\n\n\n");
    printf("Tabelarea functiilor\n\n");
    printf("val ");

    double i;
    for(i = a; i < b; i += pas) {
        double t1 = (*f1)(to_degrees(i));
        double t2 = (*f2)(to_degrees(i));
        double t3 = (*f3)(to_degrees(i));
        double t4 = (*f4)(i);
        printf("%.3lf \t %.5lf  \t %.5lf \t %.5lf \t %.5lf \n", i, t1, t2, t3, t4);
    }
}


int main()
{
    int a, b, n, what;
    double step;

    printf("Introduceti valoarea pentru inceputul intervalului: ");
    scanf("%d", &a);
    printf("Introduceti valoarea pentru sfarsitul intervalului: ");
    scanf("%d", &b);
    printf("Introduceti numarul de puncte intermediare: ");
    scanf("%d", &n);
    step = (b - a) / (double) n;

    tabelare(&mysin, &mycos, &mysincos, &myxpow2, a, b, step);

    return 0;
}
