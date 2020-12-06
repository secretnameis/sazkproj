// projektsazk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctype.h>              // tolower
#include <stdlib.h>	            //system
#include "funkce.h"

void pridat()
{
	char  cm;
	printf("S: sport   ");
	printf("L: ligu    ");
	printf("T: tym     ");
	printf("Z: zapas   ");
	printf("K: kurz    ");
	printf("Q: main menu\n\n");
	cm = tolower(getchar());
	while (getchar() != '\n');

	switch (cm)
	{
	case 's':
		//sport					
		break;
	case 'l':
		//ligu					
		break;
	case 't':
		//Tym;					
		break;
	case 'z':
		//zapas
		break;

	case 'k':
		//kurz
		break;
	
	} while (cm != 'q');     // koncime az pri Q
    


}

void smazat()
{}

void editovat()
{}

void zobrazit()
{}



int main()
{
	char  cmd;
	int roz;
	int t;
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
			pridat();
			break;

		case 'd':
			smazat();					// volame mazani
			break;
		case 'e':
			editovat();					// volame mazani
			break;
		case 'p':
			zobrazit();
			break;
		}
	} while (cmd != 'q');     // koncime az pri Q
	return 0;
}