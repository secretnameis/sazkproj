#include <iostream>
#include <ctype.h>    // tolower
#include <stdlib.h>	 //system
#include "funkce.h"
#include <fstream>
#include <string>

using namespace std;

struct t_databaze* first = NULL; // globalni ukazatel na prvni pozici
struct t_zapasy* mojep = NULL; // globalni ukazatel na prvni auto



void Onadd() // pridavani veci do seznamu
{
	char  cm;
	system("cls");
	printf("co chces pridat:\n");
	printf("Z: zapas   "); //specialni seznam
	printf("I: informace   "); // sporty, ligy, tym
	printf("V: sazky   "); // jeste nemam promysleno
	printf("Q: main menu\n\n");
	cm = tolower(getchar());
	while (getchar() != '\n');

	switch (cm)
	{
	case 'z': //zapas + informace  cas,datum,misto, stav (pro hodnoceni vyher)
		char my_tema[ZNACKA_SIZE];
		char my_cas[ZNACKA_SIZE];
		char my_datum[ZNACKA_SIZE];
		char my_misto[ZNACKA_SIZE];
		char my_stav[ZNACKA_SIZE];
		int my_id;
		//zapas id se ziska automaticky
		printf("\ntema zapasu:"); 
		scanf_s("%s", my_tema, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\ncas zapasu:");
		scanf_s("%s", my_cas, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\ndatum zapasu:");
		scanf_s("%s", my_datum, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nmisto zapasu:");
		scanf_s("%s", my_misto, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nstav zapasu:");
		scanf_s("%s", my_stav, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nid zapasu");
		scanf_s("%d", &my_id);
		while (getchar() != '\n');


		//y_id=0; // prozatimni hodnota
		
		//void addzapas(char* tema, char* cas, char* datum, char* misto, char* stav, t_zapasy** uk_prvni)
		addzapas(my_id,my_tema,my_cas,my_datum,my_misto,my_stav,&mojep); //funkce a predat parametry

		break;

	case 'i': //sport tymy,ligy, kurz					
		char my_sport[ZNACKA_SIZE];
		char my_liga[ZNACKA_SIZE];
		char my_tym[ZNACKA_SIZE];
		char my_kurz[ZNACKA_SIZE];
		int my_spide;

		printf("\n nazev sportu:");
		scanf_s("%s", my_sport, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nliga:");
		scanf_s("%s", my_liga, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\ntym");
		scanf_s("%s", my_tym, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\n kurz");
		scanf_s("%s", my_kurz, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nid sportu");
		scanf_s("%d", &my_spide);
		while (getchar() != '\n');

		//my_spid = 0; // nekde ziskat
		addinfo(my_spide,my_sport,my_liga,my_tym,my_kurz,&first); //funkce a predat parametry
		break;

	case 'v':
		//moznosti sazky
		//treba vzit vysledky zapasu a podle kurzu vypocitat cenu vyhry  WIP
		break;

	
	} 
    


}

void Ondel()
{//mazani, pridat vyber co mazat; ochrana pred smazanim sportu pokud ma registrovan zapas
	//mazani podle sportid, zapas id
}

void editovat()
{//asi se bude komplet prepisovat vybrany retezec
}

void zobrazit()
{//tisk vsech informaci nebo vybrane informace
	//spojit info pomoci ID

	
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



}

void ulozeni() //ulozi hodnoty z t_zapasy do soboury zapasy.txt
{
	
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

	
}



int main()
{
	char cmd;
	do
	{
		system("cls");		// smaze obrazovku
		printf("A: Pridat    ");
		printf("D: Smazat    ");
		printf("E: Editovat  ");
		printf("P: Tisk     ");
		printf("Q: Konec\n\n");

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