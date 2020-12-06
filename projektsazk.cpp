// projektsazk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//test
#include <iostream>
#include <ctype.h>              // tolower
#include <stdlib.h>	            //system
#include "funkce.h"

void Onadd() // pridavani veci do seznamu
{
	char  cm;
	system("cls");
	printf("co chces pridat:\n");
	printf("Z: zapas   ");
	printf("S: sport   ");
	printf("V: sazky   ");
	printf("Q: main menu\n\n");
	cm = tolower(getchar());
	while (getchar() != '\n');

	switch (cm)
	{
	case 'z':
		//zapas + informace  cas,datum,misto, sazky
		break;

	case 's':
		//sport tymy,ligy, kurz					
		break;
	case 'v':
		//moznosti sazky
		break;

	
	} while (cm != 'q');     // koncime az pri Q
    


}

void Ondel()
{//mazani, pridat vyber co mazat; ochrana pred smazanim sportu pokud ma registrovan zapas
}

void editovat()
{//asi se bude komplet prepisovat vybrany retezec
}

void zobrazit()
{//tisk vsech informaci nebo vybrane informace
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