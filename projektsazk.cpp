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
	printf("\n\n");
	printf("\n\n");
	while (aktsport) // prochazeni seznamu
	{
		printf("%d %s %d %s\n", aktsport->sport_id, aktsport->sport_nazev, aktliga->liga_id, aktliga->liga_nazev); // tisk radku
		aktsport = aktsport->sport_dalsi; // posun na dalsi auto
		aktliga = aktliga->liga_dalsi;
	}
	getchar();

	


	/* neplati, bude predelano
	//test vypisu seznamu zapasy
	struct t_zapasy* aktzapas = mojep; // ukazatel na aktualni auto
	printf("\nzapasy\n");
	while (aktzapas) // prochazeni seznamu
	{
		printf("%d %s %s %s %s %s\n", aktzapas->idzap, aktzapas->tema, aktzapas->cas, aktzapas->datum, aktzapas->misto, aktzapas->stav); // tisk radku
		aktzapas = aktzapas->next; // posun na dalsi auto
	}
	//test vypisu seznamu databaze
	struct t_databaze* aktinfo = first; // ukazatel na aktualni auto
	printf("\n databaze\n");
	while (aktinfo) // prochazeni seznamu
	{
		printf(" %s %s %s %s %d\n", aktinfo->sport, aktinfo->liga, aktinfo->tym, aktinfo->kurz, aktinfo->spid); // tisk radku
		aktinfo = aktinfo->dalsi; // posun na dalsi auto
	}

	getchar();
	*/


}

void ulozeni() //ulozi hodnoty z t_zapasy do soboury zapasy.txt
{/*
	
	struct t_zapasy* aktzapas = mojep; // ukazatel na aktualni auto
	//printf("\nUkladani do souboru.\n");
	while (aktzapas) // prochazeni seznamu
	{
		int zapis_idzap = aktzapas->idzap; //
		char* zapis_tema = aktzapas->tema;
		char* zapis_cas = aktzapas->cas;
		char* zapis_datum = aktzapas->datum;
		char* zapis_misto = aktzapas->misto;
		char* zapis_stav = aktzapas->stav;


		fstream myfile("zapas.txt", ios::out | ios::app); //definice a vytvoreni souboru, nastaveni zapisu
		if (myfile.is_open()) //podminka, ktera zjisti jestli se soubor spravne vytvoril/otevrel
		{
			myfile << zapis_idzap << " ; " << zapis_tema << " ; " << zapis_cas << " ; " << zapis_datum << " ; " << zapis_misto << " ; " << zapis_stav << endl;
			aktzapas = aktzapas->next; // posun na dalsi auto
			myfile.close();
		}
		else
			cout << "Soubory se nepodarilo ulozit!";
		
	}

	*/
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
	//ulozeni();


	
	//zapis zapasu do souboru struktura pole (idzap, tema, cas, datum, misto, stav)
	
	return 0;
}