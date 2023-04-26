#include <stdio.h>
#include "tlg.h"
#include "thash.h"
#include <string.h>
#include "functiiLG.c"
#include "functii-tabHash.c"

typedef struct {
	int aparitii;
	char cuv[50];
	int length;
} TCuv;

void inserttxt(v)
{
	char string[30];
	printf("Introduce sir:");
	scanf("%s", &string);
	char* p =string;
}

int codHash(void * element)
{
	TCuv* cuv = (TCuv *) element;
	 if (cuv >= 'A' && cuv <= 'Z')
        return cuv-'A';
 
     else if (cuv >= 'a' && cuv <= 'z')
       return cuv-'a';
 
}

void afisareCuvant(void * element)

{
	int aparitii;
	TCuv * cuv = (TCuv *) element;
	printf("%s %d\n", cuv, aparitii);
}

TLG citesteListaCuvinte(char * numeFisier) {
	FILE *f;
	char * line = NULL;
	size_t len = 0;
	TLG L = NULL;

	f = fopen(numeFisier, "rt");
	if (f == NULL)
		return NULL;

	/*while (getline(&line, &len, f) != -1) {
		char * autor = strtok(line, ":");
		char * titlu = strtok(NULL, ":");
		char * editura = strtok(NULL, ":");

		if (editura[strlen(editura) - 1] == '\n')
			editura[strlen(editura) - 1] = '\0';

		TCarte * carte = malloc(sizeof(TCarte));
		if (carte == NULL)
			return L;

		strcpy(carte->autor, autor);
		strcpy(carte->titlu, titlu);
		strcpy(carte->editura, editura);
		Ins_IncLG(&L, (void *) carte);
    }
	fclose(f);
	return L;
}*/

int cmpCuvant(void * e1, void * e2)
{
	TCuv* cuv1 = (TCuv *) e1;
	TCuv * cuv2 = (TCuv *) e2;

	if (strcmp(cuv1, cuv2) > 0)
		return 0;
		
	if (strcmp(cuv1, cuv2) < 0)
		return 0;

	return 1;
}

TH * GenerareHash(TLG listaCarti)
{
    TH *h = NULL;
	TLG p;
    TCuv * cuv;
	int rez;

	/* calcul dimensiuni maxime pt tabela hash */
	size_t M = ('Z'-'A');

	/* initializare tabela hash */
	h = (TH *) InitTH(M, codHash);
	if(h == NULL)
		return NULL;

	for(p = listaCuv; p != NULL; p = p->urm) {
        cuv = (TCuv *) malloc(sizeof(TCuv));
        if(cuv == NULL)
						return h;

        
						//free(carte);
						return h;
		}
	

	return h;
}

int main()
{
	/* Citeste o lista de carti din fisier */
	TLG listaCarti = citesteListaCarti("carti.txt");
	if (listaCarti == NULL) {
		printf("Lista nu a putut fi generata\n");
        return 0;
	}

	printf("=========== LISTA CARTI ===========\n");
	Afisare(&listaCarti, afisareCarte);

	TH * h = NULL;
	h = GenerareHash(listaCarti);
	if (h == NULL) {
		printf("Tabela hash nu a putut fi generata\n");
        return 0;
	}

	printf("\n\n=========== TABELA HASH ===========\n");
	AfiTH(h, afisareCarte);

  	DistrugeLG(&listaCarti, free);
	DistrTH(&h, free);
  	return 0;
}
