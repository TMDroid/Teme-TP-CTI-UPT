#include <stdio.h>
#include <stdlib.h>

#define TIP_MAMIFER 1
#define TIP_INSECTA 2
#define TIP_PESTE 3
#define TIP_PASARE 4

void kill_line(void)
{
    int c;
    while ((c = getchar()) != EOF && c != '\n');
}

typedef struct {
	int gestatie;
	int pui;
} mamifer;

typedef struct {
	int picioare;
	char zboara;
	char periculoasa;
} insecta;

typedef struct {
	char tip_apa;
	int adancime_maxima;
	int viteza_maxima;
} peste;

typedef struct {
	int anverura_aripi;
	int altitudine_maxima;
	int viteza_maxima;
} pasare;

typedef struct {
    char tip;
    union {
		mamifer m;
		insecta i;
		peste f;
		pasare p;
    } u;
    int ani;

} vietuitoare;

int main()
{
    vietuitoare v;

    printf("Tipul vietuitoarei \n1 - mamifer\n2 - insecta\n3 - Peste\n4 - Pasare\n");
	scanf("%c", &v.tip);
	v.tip -= '0';
	kill_line();
    printf("Durata medie de viata (ani): ");
	scanf("%d", &v.ani);

	switch(v.tip) {
		case TIP_MAMIFER:
			printf("Perioada de gestatie: ");
			scanf("%d", &v.u.m.gestatie);
			printf("\n");

			printf("Numar mediu de pui: ");
			scanf("%d", &v.u.m.pui);
		break;
		case TIP_INSECTA:
			printf("Numar de picioare: ");
			scanf("%d", &v.u.i.picioare);

            printf("Zboara? (1 - DA, 0 - NU): ");
			scanf("%c", &v.u.i.zboara);

			printf("E periculoasa pentru om? (1 - DA, 0 - NU): ");
			scanf("%c", &v.u.i.periculoasa);
		break;
		case TIP_PESTE:
			printf("In ce tip de apa traieste?(1 - dulce, 0 - sarata ");
			scanf("%c", &v.u.f.tip_apa);

			printf("Adancimea maxima la care se poate intalni: ");
			scanf("%d", &v.u.f.adancime_maxima);

			printf("Viteza maxima de inot: ");
			scanf("%d", &v.u.f.viteza_maxima);
		break;
		case TIP_PASARE:
			printf("Anvergura aripi: ");
			scanf("%d", &v.u.p.anverura_aripi);

			printf("Altitudine maxima de zbor: ");
			scanf("%d", &v.u.p.altitudine_maxima);

			printf("Viteza de zbor: ");
			scanf("%d", &v.u.p.viteza_maxima);
		break;
		default:
			exit(1);
		break;
	}

    //print
    switch(v.tip) {
        case TIP_MAMIFER:
			printf("Perioada de gestatie:");
			printf("%d", v.u.m.gestatie);

			printf("Numar mediu de pui:");
			printf("%d", v.u.m.pui);
        break;
        case TIP_INSECTA:
            printf("Ati ales insecta!\n");

			printf("Numar de picioare: ");
			printf("%d", v.u.i.picioare);
            printf("\n");

			if(v.u.i.zboara == '1') {
                printf("Zboara\n");
			} else {
                printf("Nu zboara\n");
			}

			if(v.u.i.periculoasa == '1') {
                printf("Este periculoasa pentru om");
			} else {
                printf("NU este periculoasa pentru om");
			}
        break;
        case TIP_PESTE:
            printf("Ati ales Peste!\n");

			printf("In ce tip de apa traieste?(1 - dulce, 0 - sarata): ");
			printf("%c", v.u.f.tip_apa);
            printf("\n");

			printf("Adancimea maxima la care se poate intalni: ");
			printf("%d", v.u.f.adancime_maxima);
            printf("\n");

			printf("Viteza maxima de inot: ");
			scanf("%d", v.u.f.viteza_maxima);
			printf("\n");

        break;
        case TIP_PASARE:
            printf("Ati ales Pasare!\n");

			printf("Anvergura aripi: ");
			printf("%d", v.u.p.anverura_aripi);
            printf("\n");

			printf("Altitudine maxima de zbor: ");
			printf("%d", v.u.p.altitudine_maxima);
            printf("\n");

			printf("Viteza de zbor: ");
			printf("%d", v.u.p.viteza_maxima);
            printf("\n");
        break;
    }

    return 0;
}






