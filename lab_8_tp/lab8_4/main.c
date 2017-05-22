#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

float sum(int numbers, ...) {
    va_list arguments;
    int i;
    float sum = 0.0f;

    va_start(arguments, numbers);
    for(i = 0; i < numbers; i++) {
        float n = va_arg(arguments, double);
        printf("\nAdding %.2f", n);
        sum += n;
    }

    va_end(arguments);
    return (float) sum;
}

int main()
{
    float s = sum(5, 1.0, 'c' - 'a' + 0.0f, 5.1, 7.2, 9.3);
    printf("\nsum is %.2f", s);

    s = sum(3, 1.0, 'c' - 'a', 5.1, 7.2, 9.3);
    printf("\nsum is %.2f", s);


    s = sum(1, 1.0, 'c' - 'a' + 0.0f, 5.1, 7.2, 9.3);
    printf("\nsum is %.2f", s);
    return 0;
}
