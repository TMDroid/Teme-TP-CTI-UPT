#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* tipul pentru nodul listei */
typedef struct elem
{
    int info;
    struct elem *urm;
} nod;

/* cauta in lista indicata de radacina nodul cu campul info = infofnou
  si returneaza pointerul catre acel camp
  daca nodul cautat nu exista returneaza NULL  */

nod *caut(nod *radacina, int inf)
{
    nod *p;
    for (p=radacina; p!=NULL && p->info!=inf; p=p->urm);
   // se parcurge lista atata timp cant mai sunt noduri si inf nu a fost gasit
        if (p!=NULL)  /* daca inf a fost gasit in lista */
            return p;
    return NULL;
}

/*   Functia listez parcurge lista si pentru fiecare nod afiseaza informatia memorata.     */
void listez(nod *radacina)
{
    nod *p;
    for (p=radacina; p!=NULL; p=p->urm)
       printf("Valoarea: %d la adresa %p\n",p->info,p);
}

nod *sterg_incep(nod *radacina)
{
    nod *p, *aux;
    if (radacina==NULL){  // lista goala
     printf("lista e vida\n");
     return NULL;
    }
    else
    // sterg primul element
       aux=radacina;  //retin adresa primului element
       radacina=radacina->urm;  // il sterg, facandu-l pe urmatorul primul nod
       free(aux); //eliberez memoria ocupata de el
       return radacina;
}

nod *creaza_nod(int infonou){
    nod *p;
    if ((p=(nod *)malloc(sizeof(nod)))==NULL){
     /* daca nu e memorie suficienta pentru a crea un nod nou,  se da un mesaj de eroare dupa care se
          termina functia si se returneaza NULL */
       printf("Eroare: memorie insuficienta\n");
      return NULL;
    }
    else{               // daca e loc
       p->info=infonou;   //se completeaza campurile nadului
       p->urm=NULL;
       return p;        //se returneaza o referinta (un pointer) catre acel nod
    }
}

nod * intro_incep(nod *radacina, nod *nou)
{
    nou->urm=radacina; // nou->urm pointeaza spre primul nod din lista sau
     // spre nimic (NULL) daca nu era nici un nod in lista (radacina==NULL)
    radacina=nou;     //radacina pointeaza spre nou, acum primul nod din lista
    return radacina;

}

nod * intro_sfs(nod *ultim, nod *nou){
   if (ultim!=NULL)
   ultim->urm=nou;   // ultim->urm pointeaza spre noul nod, legandu-l la lista
   return nou;     // nou devine ultimul nod
}

/* Functia main afiseaza meniul programului,citeste comanda si
   apeleaza functia corespunzatoare                     */
void main(void)
{
   char o;
   int val;
   nod *radacina=NULL;  // pastreaza inceputul listei
   nod *nou, *ultim=NULL;     // pastreaza sfarsitul listei
   puts(""); // tiparesc un sir vid pentru delimitare fata de rularile anterioare
   while(1)
   {
       puts("");
       /* se afiseaza meniul programului */
       puts("a : adauga un nod la inceput");
       puts("d : adauga un nod la sfarsit");
       puts("c : cauta un nod");
       puts("s : sterge primul nod");
       puts("l : listeaza tot");
       puts("t : termina programul");
       printf("\nOptiunea: ");
       while(isspace(o=getchar()) );
       printf("\n");
       if (!isspace(o))
          switch (tolower(o))
         {
          case 'a': {  printf("adauga inceput   nr=");
               scanf("%d", &val);
               nou=creaza_nod(val);
               if (radacina==NULL)  ultim=nou;  //daca e primul element din lista
                // initializam si ultim cu adresa noului nod
               radacina=intro_incep(radacina, nou);
              break;}
         case 'd': {  printf("adauga sfarsit   nr=");
             scanf("%d", &val);
             nou=creaza_nod(val);
             if (radacina==NULL)  radacina=nou; // daca e primul element din lista
               // initializam si radacina cu adresa primului nod
             ultim=intro_sfs(ultim, nou);
             break;}
         case 'c': {  puts("cauta si tipareste un nod");
             printf("nr=");
             scanf("%d", &val);
             if ((nou=caut(radacina, val))!=NULL) /* cauta nodul in lista */
                printf(" Valoare:%d\n", nou->info);
             else
                  printf("Eroare: Identificator nedefinit\n");
             break;
         }
         case 's':{   printf("stergere primul nod\n");
             radacina=sterg_incep(radacina); /* sterge nodul din lista */
             if (radacina==NULL) ultim=NULL; /* daca era ultimul nod */
             break;}
         case 'l':{  puts("listare");
             listez(radacina);
             break;}
         case 't':
             return;
         default:
             printf("Eroare : Comanda inexistenta\n");
         }
   }

}