#include <iostream>
#include <ctype.h>    // tolower
#include <stdlib.h>	 //system
#include "funkce.h"

struct t_databaze* first = NULL; // globalni ukazatel na prvni pozici
struct t_zapasy* mojep = NULL; // globalni ukazatel na prvni auto

//testc

void Onadd() // pridavani veci do seznamu
{
	char  cm;
	system("cls");
	printf("co chces pridat:\n");
	printf("Z: zapas   "); //specialni seznam
	printf("I: informace   "); // sporty, ligy, tym
	printf("V: sazky   "); // jeste nemam promysleno
	printf("Q: navrat do menu\n\n");
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
		printf("\ntema zapasu: "); 
		scanf_s("%s", my_tema, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\ncas zapasu: ");
		scanf_s("%s", my_cas, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\ndatum zapasu: ");
		scanf_s("%s", my_datum, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nmisto zapasu: ");
		scanf_s("%s", my_misto, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nstav zapasu: ");
		scanf_s("%s", my_stav, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nid zapasu: ");
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

		printf("\n nazev sportu: ");
		scanf_s("%s", my_sport, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nliga: ");
		scanf_s("%s", my_liga, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\ntym: ");
		scanf_s("%s", my_tym, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\n kurz: ");
		scanf_s("%s", my_kurz, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nid sportu: ");
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



int main()
{
	char  cmd;
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

	
	//zapis zapasu do souboru struktura pole (idzap, tema, cas, datum, misto, stav)
	
	return 0;
}