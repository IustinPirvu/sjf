#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
	int val;
	nod *next;
}nod;

void addnod(nod **prim, nod **ultim, int info)
{
	nod *m;
	m = (nod*)malloc(sizeof(nod));
	m->next = NULL;
	m->val = info;
	if (*prim == NULL)
	{
		*prim = m;
		*ultim = m;
	}
	else
	{
		(*ultim)->next = m;
		*ultim = m;
	}
}

void afislista(nod *prim)
{
	nod *p = prim;
	while (p)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

void inserare_dupa(nod *prim, int valcaut, int valinsert)
{
	nod *p = prim, *m;
	while (p->val != valcaut)
	{
		p = p->next;
	}
	m = (nod*)malloc(sizeof(nod));
	m->val = valinsert;
	m->next = p->next;
	p->next = m;
}

void inserare_inainte(nod *prim, int valcaut, int valinsert)
{
	nod *p = prim, *m;
	while (p->next->val != valcaut) p = p->next;
	m = (nod*)malloc(sizeof(nod));
	m->val = valinsert;
	m->next = p->next;
	p->next = m;
}

void sterg_nod(nod *prim, int valcaut)
{
	nod *p = prim, *m;
	while (p->next->val != valcaut) p = p->next;
	m = p->next;
	p->next = p->next->next;
	free(m);
}

void sterglista(nod *prim)
{
	nod *p;
	while (prim)
	{
		p = prim;
		prim = prim->next;
		free(p);
	}
}

int main()
{
	int x;
	nod *prim = NULL, *ultim = NULL;
	printf("Introdu o valoare: ");
	scanf("%d", &x);
	while (x != 0)
	{
		addnod(&prim, &ultim, x);
		printf("Introdu o valoare: ");
		scanf("%d", &x);
	}
	afislista(prim);
	int valcaut, valinsert;

	printf("Introdu valoarea cautata: ");
	scanf("%d", &valcaut);
	printf("Introdu valoarea pe care o vei insera dupa: ");
	scanf("%d", &valinsert);
	inserare_dupa(prim, valcaut, valinsert);
	afislista(prim);

	printf("Introdu valoarea cautata: ");
	scanf("%d", &valcaut);
	printf("Introdu valoarea pe care o vei insera inainte: ");
	scanf("%d", &valinsert);
	inserare_inainte(prim, valcaut, valinsert);
	afislista(prim);

	printf("Introdu valoarea pe care o vei sterge: ");
	scanf("%d", &valcaut);
	sterg_nod(prim, valcaut);
	afislista(prim);

	sterglista(prim);
	afislista(prim);
}