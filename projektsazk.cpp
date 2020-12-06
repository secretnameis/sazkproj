#include <iostream>
#include <ctype.h>    // tolower
#include <stdlib.h>	 //system
#include "funkce.h"

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
		//funkce a predat parametry

		break;

	case 'i': //sport tymy,ligy, kurz					
		char my_sport[ZNACKA_SIZE];
		char my_liga[ZNACKA_SIZE];
		char my_tym[ZNACKA_SIZE];
		char my_kurz[ZNACKA_SIZE];

		printf("\n nazev sportu:");
		scanf_s("%s", my_sport, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\nstav zapasu:");
		scanf_s("%s", my_liga, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\ntema zapasu");
		scanf_s("%s", my_tym, ZNACKA_SIZE);
		while (getchar() != '\n');

		printf("\ntema zapasu");
		scanf_s("%s", my_kurz, ZNACKA_SIZE);
		while (getchar() != '\n');
		//funkce a predat parametry

		break;

	case 'v':
		//moznosti sazky
		//treba vzit vysledky zapasu a podle kurzu vypocitat cenu vyhry  WIP
		break;

	
	} while (cm != 'q');     // koncime az pri Q
    


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
}



int main()
{
	char  cmd;
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
	return 0;
}