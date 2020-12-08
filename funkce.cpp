#include "funkce.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//struct t_zapasy* ukazatel = NULL;

void addsport(int sport_id, char* sport_nazev, sport** sport_prvni)
{
	struct sport* novysport;
	struct sport* aktsport;
	
	// alokace dynamicke promenne
	novysport = (struct sport*)malloc(sizeof(struct sport));

	novysport->sport_id = sport_id;
	//novysport->sport_id = max_sport_ID();
	strcpy_s(novysport->sport_nazev, 30, sport_nazev); // naplneni struktury
	novysport->sport_dalsi = NULL;


	if (*sport_prvni == NULL) // linearni seznam je prazdny
	{
		*sport_prvni = novysport;
		return;
	}
	else if (novysport->sport_id < (*sport_prvni)->sport_id) // vlozime na zacatek
	{
		novysport->sport_dalsi = *sport_prvni;
		*sport_prvni = novysport;
		return;
	}

	aktsport = *sport_prvni;
	while (aktsport) // prochazeni seznamu
	{
		if (aktsport->sport_dalsi == NULL) // jsme na poslednim aute
		{
			aktsport->sport_dalsi = novysport; // pridavame na konec
			return;
		}
		else if (novysport->sport_id < aktsport->sport_dalsi->sport_id)
		{
			novysport->sport_dalsi = aktsport->sport_dalsi; // vlozime za aktsport
			aktsport->sport_dalsi = novysport;
			return;
		}
		aktsport = aktsport->sport_dalsi; // posun na dalsi auto
	}

}

void addliga(int liga_id, char* liga_nazev, liga** liga_prvni)
{
	struct liga* novaliga;
	struct liga* aktliga;

	// alokace dynamicke promenne
	novaliga = (struct liga*)malloc(sizeof(struct liga));

	novaliga->liga_id = liga_id;
	strcpy_s(novaliga->liga_nazev, 30, liga_nazev); // naplneni struktur

	novaliga->liga_dalsi = NULL;


	if (*liga_prvni == NULL) // linearni seznam je prazdny
	{
		*liga_prvni = novaliga;
		return;
	}
	else if (novaliga->liga_id < (*liga_prvni)->liga_id) // vlozime na zacatek
	{
		novaliga->liga_dalsi = *liga_prvni;
		*liga_prvni = novaliga;
		return;
	}

	aktliga = *liga_prvni;
	while (aktliga) // prochazeni seznamu
	{
		if (aktliga->liga_dalsi == NULL) // jsme na poslednim aute
		{
			aktliga->liga_dalsi = novaliga; // pridavame na konec
			return;
		}
		else if (novaliga->liga_id < aktliga->liga_dalsi->liga_id)
		{
			novaliga->liga_dalsi = aktliga->liga_dalsi; // vlozime za aktAuto
			aktliga->liga_dalsi = novaliga;
			return;
		}
		aktliga = aktliga->liga_dalsi; // posun na dalsi auto
	}

}

void addtym(int tym_id, char* tym_nazev, int tym_sport, int tym_liga, tym** tym_prvni)
{
	struct tym* novytym;
	struct tym* akttym;

	// alokace dynamicke promenne
	novytym = (struct tym*)malloc(sizeof(struct tym));

	novytym->tym_id = tym_id;
	strcpy_s(novytym->tym_nazev, 30, tym_nazev); // naplneni struktur
	novytym->tym_sport = tym_sport;
	novytym->tym_liga = tym_liga;
	novytym->tym_dalsi = NULL;


	if (*tym_prvni == NULL) // linearni seznam je prazdny
	{
		*tym_prvni = novytym;
		return;
	}
	else if (novytym->tym_id < (*tym_prvni)->tym_id) // vlozime na zacatek
	{
		novytym->tym_dalsi = *tym_prvni;
		*tym_prvni = novytym;
		return;
	}

	akttym = *tym_prvni;
	while (akttym) // prochazeni seznamu
	{
		if (akttym->tym_dalsi == NULL) // jsme na poslednim aute
		{
			akttym->tym_dalsi = novytym; // pridavame na konec
			return;
		}
		else if (novytym->tym_id < akttym->tym_dalsi->tym_id)
		{
			novytym->tym_dalsi = akttym->tym_dalsi; // vlozime za akttym
			akttym->tym_dalsi = novytym;
			return;
		}
		akttym = akttym->tym_dalsi; // posun na dalsi tym
	}

}

void addzapas(int zapas_id, int zapas_sport, int zapas_liga, char* zapas_datum, char* zapas_misto, int zapas_tymA, int zapas_tymB, int zapas_skoreA, int zapas_skoreB, char* zapas_sazka, zapas** zapas_prvni)
{
	struct zapas* novyzapas;
	struct zapas* aktzapas;

	// alokace dynamicke promenne
	novyzapas = (struct zapas*)malloc(sizeof(struct zapas));

	//naplneni struktury
	novyzapas->zapas_id = zapas_id;
	novyzapas->zapas_sport = zapas_sport;
	novyzapas->zapas_liga = zapas_liga;
	strcpy_s(novyzapas->zapas_datum, 30, zapas_datum);
	strcpy_s(novyzapas->zapas_misto, 30, zapas_misto);
	novyzapas->zapas_tymA = zapas_tymA;
	novyzapas->zapas_tymB = zapas_tymB;
	novyzapas->zapas_skoreA = zapas_skoreA;
	novyzapas->zapas_skoreB = zapas_skoreB;
	strcpy_s(novyzapas->zapas_sazka, 30,zapas_sazka);
	novyzapas->zapas_dalsi = NULL;

	if (*zapas_prvni == NULL) // linearni seznam je prazdny
	{
		*zapas_prvni = novyzapas;
		return;
	}
	else if (novyzapas->zapas_id < (*zapas_prvni)->zapas_id) // vlozime na zacatek
	{
		novyzapas->zapas_dalsi = *zapas_prvni;
		*zapas_prvni = novyzapas;
		return;
	}

	aktzapas = *zapas_prvni;
	while (aktzapas) // prochazeni seznamu
	{
		if (aktzapas->zapas_dalsi == NULL) // jsme na poslednim aute
		{
			aktzapas->zapas_dalsi = novyzapas; // pridavame na konec
			return;
		}
		else if (novyzapas->zapas_id < aktzapas->zapas_dalsi->zapas_id)
		{
			novyzapas->zapas_dalsi = aktzapas->zapas_dalsi; // vlozime za aktzapas
			aktzapas->zapas_dalsi = novyzapas;
			return;
		}
		aktzapas = aktzapas->zapas_dalsi; // posun na dalsi auto
	}

}





//jiz neplati, bude predelano
/*
void addzapas(int idzap, char* tema, char* cas, char* datum, char* misto, char* stav, struct t_zapasy** uk_prvni)
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


void smazat(char* sport, char* liga, char* tym, char* zapas, char* kurz, struct t_databaze** uk_prvni)
{
	printf("test");
}
*/