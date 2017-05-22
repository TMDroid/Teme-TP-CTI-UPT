#include <stdio.h>
#include <stdlib.h>

#define DBG_PRINT(format, variable) \
    printf("Fisier: %s", __FILE__); \
    printf("\nLinie: %d", __LINE__); \
    printf("\nNume variabila: %s", #variable); \
    printf("\nValoare variabila: "); \
    if(format[1] == 'd') printf("%d", variable); \
    else if(format[1] == 'f' || format[1] == 'l')  printf("%f", (float) variable); \
    else if(format[1] == 's') printf("%s", (char*) variable); \
    printf("\n")


int main()
{
    int x = 5;
    DBG_PRINT("%d", x);
    printf("Hello world!\n");
    return 0;
}
