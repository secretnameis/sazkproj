#include <iostream>
#include <ctype.h>    // tolower
#include <stdlib.h>	 //system
#include "funkce.h"
#include <fstream>
#include <string>

using namespace std;

//struct t_databaze* first = NULL; // globalni ukazatel na prvni pozici
//struct t_zapasy* mojep = NULL; // globalni ukazatel na prvni auto
struct sport* sprvni = NULL; // globalni ukazatel na prvni sport
struct liga* lprvni = NULL; // globalni ukazatel na prvni ligu
struct tym* tprvni = NULL; // globalni ukazatel na prvni auto
struct zapas* zprvni = NULL; // globalni ukazatel na prvni auto

char* sportp(int a) {//vypis podlwe id
	int test;
	struct sport* akts = sprvni;
	while (akts)
	{
		test = akts->sport_id;
		if (test == a)
		{
			//printf("%d %s", akts->sport_id, akts->sport_nazev);
			char* vrat = akts->sport_nazev;
			return vrat;
		}
		else
		{
			akts = akts->sport_dalsi;
		}
	}
}

char* ligap(int a) {//vypis podle id
	int test;
	struct liga* aktl = lprvni;
	while (aktl)
	{
		test = aktl->liga_id;
		if (test == a)
		{
			char* vrat = aktl->liga_nazev;
			return vrat;
		}
		else
		{
			aktl = aktl->liga_dalsi;
		}
	}
}

void Onadd() // pridavani veci do seznamu
{
	char  cm;
	system("cls");
	printf("co chces pridat:\n");
	printf("S: sport  ");
	printf("L: liga  ");
	printf("T: tym   ");
	printf("Z: zapas "); 
	printf("Q: navrat do menu\n\n");
	cm = tolower(getchar());
	while (getchar() != '\n');

	switch (cm)
	{
	case 's': 
		int sid;
		char snazev[ZNACKA_SIZE];
		
		//funkce na ziskani posledniho id
		printf("\nid sportu: ");
		scanf_s("%d", &sid);
		while (getchar() != '\n');

		
		printf("\nnazev sportu: "); 
		scanf_s("%s", snazev, ZNACKA_SIZE);
		while (getchar() != '\n');

		addsport(sid, snazev, &sprvni);
		
		//void addzapas(char* tema, char* cas, char* datum, char* misto, char* stav, t_zapasy** uk_prvni)
		//addzapas(my_id,my_tema,my_cas,my_datum,my_misto,my_stav,&mojep); //funkce a predat parametry

		break;

	case 'l': //sport tymy,ligy, kurz					
		int liga_id;
		char liga_nazev[ZNACKA_SIZE];

		//funkce na ziskani posledniho id
		printf("\nid ligy: ");
		scanf_s("%d", &liga_id);
		while (getchar() != '\n');


		printf("\nnazev ligy: ");
		scanf_s("%s", liga_nazev, ZNACKA_SIZE);
		while (getchar() != '\n');

		addliga(liga_id, liga_nazev, &lprvni);

		break;

	case 't':
		int tym_id;
		char tym_nazev[ZNACKA_SIZE];
		int tym_sport;
		int tym_liga;
		
		//funkce na ziskani posledniho id
		printf("\nid tymu: ");
		scanf_s("%d", &tym_id);
		while (getchar() != '\n');

		printf("\nnazev tymu: ");
		scanf_s("%s", tym_nazev, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nid sportu: ");
		scanf_s("%d", &tym_sport);
		while (getchar() != '\n');

		printf("\nid liga: ");
		scanf_s("%d", &tym_liga);
		while (getchar() != '\n');

		addtym(tym_id, tym_nazev, tym_sport, tym_liga, &tprvni);

		break;

	case 'z':
		int  zapas_id; //id zapasu
		int zapas_sport;
		int zapas_liga;
		char zapas_datum[ZNACKA_SIZE];
		char zapas_misto[ZNACKA_SIZE];
		int zapas_tymA;
		int zapas_tymB;
		int zapas_skoreA;
		int zapas_skoreB;
		char zapas_sazka[ZNACKA_SIZE];

		printf("\nid zapasu: ");
		scanf_s("%d", &zapas_id);
		while (getchar() != '\n');

		printf("\nid sportu: ");
		scanf_s("%d", &zapas_sport);
		while (getchar() != '\n');

		printf("\nid liga: ");
		scanf_s("%d", &zapas_liga);
		while (getchar() != '\n');

		printf("\ndatum zapasu: ");
		scanf_s("%s", zapas_datum, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nmisto zapasu: ");
		scanf_s("%s", zapas_misto, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nid tymA: ");
		scanf_s("%d", &zapas_tymA);
		while (getchar() != '\n');

		printf("\nid tymB: ");
		scanf_s("%d", &zapas_tymB);
		while (getchar() != '\n');

		printf("\n skore A: ");
		scanf_s("%d", &zapas_skoreA);
		while (getchar() != '\n');

		printf("\nskore B: ");
		scanf_s("%d", &zapas_skoreB);
		while (getchar() != '\n');

		printf("\nsazka: ");
		scanf_s("%s", zapas_sazka, ZNACKA_SIZE);
		while (getchar() != '\n');

		addzapas(zapas_id,zapas_sport,zapas_liga,zapas_datum,zapas_misto,zapas_tymA,zapas_tymB,zapas_skoreA,zapas_skoreB,zapas_sazka,&zprvni);
		break;

	} 
    


}

void Ondel()
{//mazani, pridat vyber co mazat; ochrana pred smazanim sportu pokud ma registrovan zapas
	//mazani podle sportid, zapas id

	char  cmq;
	system("cls");
	printf("co chces smazat:\n");
	printf("Z: zapas    "); 
	printf("I: informace   "); // sporty, ligy, tym
	printf("V: sazky   "); 
	printf("Q: navrat do menu\n\n");
	cmq = tolower(getchar());
	while (getchar() != '\n');

	switch (cmq)
	{
	case 'z':
		//OnAdd();					// volame pridani
		break;
	case 'i':
	//	OnDel();					// volame mazani
		break;
	case 'v':
	//	ShowCars();
		break;
	}

}

void editovat()
{//asi se bude komplet prepisovat vybrany retezec
}

void zobrazit()
{
	struct sport* aktsport = sprvni; // ukazatel na aktualni auto
	struct liga* aktliga = lprvni;
	struct tym* akttym = tprvni;
	struct zapas* aktzapas = zprvni;

	char sh;
		system("cls");		// smaze obrazovku
		printf("co chces tisknout\n");
		printf("S: sport ");
		printf("L: liga  ");
		printf("T: tym   ");
		printf("Z: zapas ");
		printf("A: test  ");
		printf("Q: zpet do menu\n\n");

		sh = tolower(getchar());
		while (getchar() != '\n');

		switch (sh)
		{
		case 's':
			printf("\n\n");
			while (aktsport) // prochazeni seznamu
			{
				printf("%d %s\n", aktsport->sport_id, aktsport->sport_nazev); // tisk radku
				aktsport = aktsport->sport_dalsi; // posun na dalsi auto
			}
			getchar();

			break;

		case 'l':
			printf("\n\n");
			while (aktliga) // prochazeni seznamu
			{
				printf("%d %s\n", aktliga->liga_id, aktliga->liga_nazev); // tisk radku
				aktliga = aktliga->liga_dalsi; // posun na dalsi auto
			}
			getchar();


			break;
		case 't': //tisk tym s externim id
			printf("\n\n");
			while (akttym) // prochazeni seznamu
			{
				int u,o;
				u= akttym->tym_sport;
				o = akttym->tym_liga;
				printf("%d %s %s\n", akttym->tym_id, akttym->tym_nazev, sportp(u),ligap(o)); // tisk radku
				akttym = akttym->tym_dalsi; // posun na dalsi auto
			}
			getchar();


			break;
		case 'z':

			break;

		case 'a':
			//test
			/*
			printf("\n\n");
			printf("\n\n");
			while (aktsport) // prochazeni seznamu
			{
				printf("sport,liga %d %s %d %s\n", aktsport->sport_id, aktsport->sport_nazev, aktliga->liga_id, aktliga->liga_nazev); // tisk radku
				printf("tym,zapas %d %s %d %s\n", akttym->tym_id, akttym->tym_nazev, aktzapas->zapas_id, aktzapas->zapas_datum);
				aktsport = aktsport->sport_dalsi; // posun na dalsi auto
				aktliga = aktliga->liga_dalsi;
				akttym = akttym->tym_dalsi;
				aktzapas = aktzapas->zapas_dalsi;
			}
			getchar();*/
			break;
		}	
}


void ulozeni() //ulozi hodnoty z t_zapasy do soboury zapasy.txt
{
	struct sport* aktsport = sprvni; //ulozeni sportu
	while (aktsport)
	{
		int zapis_sport_id = aktsport->sport_id;
		char* zapis_sport_nazev = aktsport->sport_nazev;

		fstream zapsport("sport.txt", ios::out | ios::app);
		if (zapsport.is_open())
		{
			zapsport << zapis_sport_id << ";" << zapis_sport_nazev << endl;
			aktsport = aktsport->sport_dalsi;
			zapsport.close();

		}
		else
			cout << "Sport se nepodarilo ulozit.";
	}

	struct liga* aktliga = lprvni; //ulozeni ligy
	while (aktliga)
	{
		int zapis_liga_id = aktliga->liga_id;
		char* zapis_liga_nazev = aktliga->liga_nazev;

		fstream zapliga("liga.txt", ios::out | ios::app);
		if (zapliga.is_open())
		{
			zapliga << zapis_liga_id << ";" << zapis_liga_nazev << endl;
			aktliga = aktliga->liga_dalsi;
			zapliga.close();
		}
		else
			cout << "Ligu se nepodarilo ulozit.";
	}

	struct tym* akttym = tprvni;  //ulozeni tymu
	while (akttym)
	{
		int zapis_tym_id = akttym->tym_id;
		char* zapis_tym_nazev = akttym->tym_nazev;
		int zapis_tym_sport = akttym->tym_sport;
		int zapis_tym_liga = akttym->tym_liga;
		
		fstream zaptym("tym.txt", ios::out | ios::app);
		if (zaptym.is_open())
		{
			zaptym << zapis_tym_id << ";" << zapis_tym_nazev << ";" << zapis_tym_sport << ";" << zapis_tym_liga << endl;
			akttym = akttym->tym_dalsi;
			zaptym.close();
		}
		else
			cout << "Tym se nepodarilo ulozit.";
	}

	struct zapas* aktzapas = zprvni; //ulozeni zapasu
	while (aktzapas)
	{
		int zapis_zapas_id = aktzapas->zapas_id;
		int zapis_zapas_sport = aktzapas->zapas_sport;
		int zapis_zapas_liga = aktzapas->zapas_liga;
		char* zapis_zapas_datum = aktzapas->zapas_datum;
		char* zapis_zapas_misto = aktzapas->zapas_misto;
		int zapis_zapas_tymA = aktzapas->zapas_tymA;
		int zapis_zapas_tymB = aktzapas->zapas_tymB;
		int zapis_zapas_skoreA = aktzapas->zapas_skoreA;
		int zapis_zapas_skoreB = aktzapas->zapas_skoreB;
		char* zapis_zapas_sazka = aktzapas->zapas_sazka;

		fstream zapzapas("zapas.txt", ios::out | ios::app);
		if (zapzapas.is_open())
		{
			zapzapas << zapis_zapas_id << ";" << zapis_zapas_sport << ";" << zapis_zapas_liga << ";" << zapis_zapas_datum << ";" << zapis_zapas_misto << ";" << zapis_zapas_tymA << ";" << zapis_zapas_tymB << ";" << zapis_zapas_skoreA << ";" << zapis_zapas_skoreB << ";" << zapis_zapas_sazka << endl;
			aktzapas = aktzapas->zapas_dalsi;
			zapzapas.close();
		}
		else
			cout << "Zapas se nepodarilo ulozit.";
	}
}



int main()
{
	char cmd;
	do
	{
		system("cls");		// smaze obrazovku
		printf("Hlavni menu\n");
		printf("A: Pridat    ");
		printf("D: Smazat    ");
		printf("E: Editovat  ");
		printf("P: Tisk     ");
		printf("Q: ukoncit\n\n");

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'a':
			Onadd();
			break;

		case 'd':
			Ondel();					
			break;
		case 'e':
			editovat();					
			break;
		case 'p':
			zobrazit();
			break;
		}
	} while (cmd != 'q');     // koncime az pri Q

	//tady odkaz na zapis vseho do souboru
	ulozeni();


	
	//zapis zapasu do souboru struktura pole (idzap, tema, cas, datum, misto, stav)
	
	return 0;
}