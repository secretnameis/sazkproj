#include "funkce.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addzapas(int idzap, char* tema, char* cas, char* datum, char* misto, char* stav, t_zapasy** uk_prvni)
{
	struct t_zapasy* novyzapas; // ukazatel pro novy zapas
	struct t_zapasy* aktzapas; // ukazatel na aktualni zapas

	//alokace dynamicke promenne
	novyzapas = (struct t_zapasy*)malloc(sizeof(struct t_zapasy));
	
	//naplneni struktury
	//strcpy_s(novyzapas->cas, 30, cas);    nekde ziskat ID  WIP
	novyzapas->idzap = idzap;
	strcpy_s(novyzapas->tema, 30, tema);
	strcpy_s(novyzapas->cas, 30, cas);
	strcpy_s(novyzapas->datum, 30, datum);
	strcpy_s(novyzapas->misto, 30, misto);
	strcpy_s(novyzapas->stav, 30, stav);
	novyzapas->next = NULL;

	//razeni seznamu
	if (*uk_prvni == NULL) // linearni seznam je prazdny
	{
		*uk_prvni = novyzapas;
		return;
	}
	else if (novyzapas->idzap < (*uk_prvni)->idzap) // vlozime na zacatek 
	{
		novyzapas->next = *uk_prvni;
		*uk_prvni = novyzapas;
		return;
	}

	//razeni seznamu podle idzap
	aktzapas = *uk_prvni;
	while (aktzapas) // prochazeni seznamu
	{
		if (aktzapas->next == NULL) // jsme na poslednim zapase
		{
			aktzapas->next = novyzapas; // pridavame na konec
			return;
		}
		else if (novyzapas->idzap < aktzapas->next->idzap)
		{
			novyzapas->next = aktzapas->next; // vlozime za aktzapas
			aktzapas->next = novyzapas;
			return;
		}
		aktzapas = aktzapas->next; // posun na dalsi auto
	}

}




void pridat(char* sport, char* liga, char* tym, char* zapas, char* kurz, struct t_databaze** uk_prvni)
{
	printf("test");
}

void smazat(char* sport, char* liga, char* tym, char* zapas, char* kurz, struct t_databaze** uk_prvni)
{
	printf("test");
}
