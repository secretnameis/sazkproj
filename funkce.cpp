#include "funkce.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;



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

void delsport(int spot_id, sport** sprvni)
{
	struct sport* akts;

	while (*sprvni && (*sprvni)->sport_id == spot_id)
	{
		struct sport* newPrvni = (*sprvni)->sport_dalsi;
		free(*sprvni);  // uvolneni auta z pameti
		*sprvni = newPrvni;
	}

	akts = *sprvni;
	while (akts && akts->sport_dalsi) // prochazeni seznamu
	{
		if (akts->sport_dalsi->sport_id == spot_id) // sport je ke smazani
		{
			struct sport* newDalsi = akts->sport_dalsi->sport_dalsi;
			free(akts->sport_dalsi);  // uvolneni sportu z pameti
			akts->sport_dalsi = newDalsi;
		}
		akts = akts->sport_dalsi; // posun na dalsi sport
	}

}


void delliga(int lid, liga** lprvni)
{
	struct liga* aktl;

	while (*lprvni && (*lprvni)->liga_id == lid)
	{
		struct liga* newPrvni = (*lprvni)->liga_dalsi;
		free(*lprvni);  // uvolneni auta z pameti
		*lprvni = newPrvni;
	}

	aktl = *lprvni;
	while (aktl && aktl->liga_dalsi)
	{
		if (aktl->liga_dalsi->liga_id == lid)
		{
			struct liga* newliga_dalsi = aktl->liga_dalsi->liga_dalsi;
			free(aktl->liga_dalsi);
			aktl->liga_dalsi = newliga_dalsi;
		}
		aktl = aktl->liga_dalsi;
	}
}


void deltym(int tym_id, tym** tprvni)
{
	struct tym* aktt;

	while (*tprvni && (*tprvni)->tym_id == tym_id)
	{
		struct tym* newPrvni = (*tprvni)->tym_dalsi;
		free(*tprvni);  // uvolneni auta z pameti
		*tprvni = newPrvni;
	}

	aktt = *tprvni;
	while (aktt && aktt->tym_dalsi) // prochazeni seznamu
	{
		if (aktt->tym_dalsi->tym_id == tym_id) // sport je ke smazani
		{
			struct tym* newDalsi = aktt->tym_dalsi->tym_dalsi;
			free(aktt->tym_dalsi);  // uvolneni sportu z pameti
			aktt->tym_dalsi = newDalsi;
		}
		aktt = aktt->tym_dalsi; // posun na dalsi sport
	}
}

void delzapas(int zapas_id, zapas** zprvni)
{
	struct zapas* aktz;

	while (*zprvni && (*zprvni)->zapas_id == zapas_id)
	{
		struct zapas* newPrvni = (*zprvni)->zapas_dalsi;
		free(*zprvni);  // uvolneni auta z pameti
		*zprvni = newPrvni;
	}

	aktz = *zprvni;
	while (aktz && aktz->zapas_dalsi)
	{
		if (aktz->zapas_dalsi->zapas_id == zapas_id)
		{
			struct zapas* newDalsi = aktz->zapas_dalsi->zapas_dalsi;
			free(aktz->zapas_dalsi);
			aktz->zapas_dalsi = newDalsi;
		}
		aktz = aktz->zapas_dalsi;
	}
}

/*
void nacist_sport() {
	FILE* ss;
	char str[60];  //sem nacitame radky
	char* token;   // sem rozdelime polozky radku
	
	int lokal_id;
	//char lokal_popis;
	
	//int i;			// posun po polozkach

	ss = fopen("sport.txt", "r");
	if (ss == NULL) {
		perror("Nejde otevrit soubor");
		

	}
	while (fgets(str, 60, ss) != NULL) {
		token = strtok(str, ";");  // prvni token-polozka
		printf(token);
		printf(" - ");

		lokal_id = atoi(token);
		token = strtok(NULL, ";");

		printf(token);
		printf("\n");

		//lokal_popis = strtoken;
		//strcpy_s(lokal_popis, 30, token);

		//int delkatokenu; 
		const int delkatokenu = sizeof(token);
		char lokal_popis[delkatokenu];
		int i;
		for (i = 0; i < delkatokenu; i++) {
			lokal_popis[i] = token[i];
			cout << lokal_popis[i];
		}
		
		//return lokal_id, lokal_popis;
	}


	fclose(ss);
	//return lokal_id, lokal_popis;
}*/