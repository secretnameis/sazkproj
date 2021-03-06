#include <iostream>
#include <ctype.h>    // tolower
#include <stdlib.h>	 //system
#include "funkce.h"
#include <fstream>
#include <string>
#include <thread>

using namespace std;


//struct t_databaze* first = NULL; // globalni ukazatel na prvni pozici
//struct t_zapasy* mojep = NULL; // globalni ukazatel na prvni auto
struct sport* sprvni = NULL; // globalni ukazatel na prvni sport
struct liga* lprvni = NULL; // globalni ukazatel na prvni ligu
struct tym* tprvni = NULL; // globalni ukazatel na prvni tym
struct zapas* zprvni = NULL; // globalni ukazatel na prvni zapas

// funkce pro malezeni max ID v seznamu
int max_sport_ID() {

	struct sport* akts = sprvni;
	int max = 0;
	while (akts)
	{
		if (akts->sport_id > max) {
			
			max = akts->sport_id;
		}
		akts = akts->sport_dalsi;
	}
	return max+1;
}

int max_liga_ID() {

	struct liga* aktl = lprvni;
	int max = 0;
	while (aktl)
	{
		if (aktl->liga_id > max) {

			max = aktl->liga_id;
		}
		aktl = aktl->liga_dalsi;
	}
	return max + 1;
}

int max_tym_ID() {

	struct tym* aktt = tprvni;
	int max = 0;
	while (aktt)
	{
		if (aktt->tym_id > max) {

			max = aktt->tym_id;
		}
		aktt = aktt->tym_dalsi;
	}
	return max + 1;
}

int max_zapas_ID() {

	struct zapas* aktz = zprvni;
	int max = 0;
	while (aktz)
	{
		if (aktz->zapas_id > max) {

			max = aktz->zapas_id;
		}
		aktz = aktz->zapas_dalsi;
	}
	return max + 1;
}



//vypis podle id
char* sportp(int a) {
	int test;
	struct sport* akts = sprvni;
	while (akts)
	{
		test = akts->sport_id;
		if (test == a)
		{
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

char* tymp(int a) {
	int test;
	struct tym* aktt = tprvni;
	while (aktt)
	{
		test = aktt->tym_id;
		if (test == a)
		{
			char* vrat = aktt->tym_nazev;
			return vrat;
		}
		else
		{
			aktt = aktt->tym_dalsi;
		}
	}
}

void Onadd() // pridavani veci do seznamu
{
	char  cm;
	system("cls");
	printf("co chces pridat:\n");
	printf("S: sport    ");
	printf("L: liga    ");
	printf("T: tym    ");
	printf("Z: zapas    "); 
	printf("Q: navrat do menu\n\n");
	cm = tolower(getchar());
	while (getchar() != '\n');

	switch (cm)
	{
	case 's': 
		int sid;
		char snazev[ZNACKA_SIZE];
		
		sid=max_sport_ID();

		printf("\nnazev sportu: "); 
		scanf_s("%s", snazev, ZNACKA_SIZE);
		while (getchar() != '\n');

		addsport(sid, snazev, &sprvni);
		
		break;

	case 'l': //sport tymy,ligy, kurz					
		int liga_id;
		char liga_nazev[ZNACKA_SIZE];
		
		liga_id = max_liga_ID();//funkce na ziskani posledniho id

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
		
		tym_id = max_tym_ID();//funkce na ziskani posledniho id

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

		zapas_id = max_zapas_ID();

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
{
	char  cmq;
	system("cls");
	printf("co chces smazat:\n");
	printf("S: sport  ");
	printf("T: tym    "); // sporty, ligy, tym
	printf("L: liga   ");
	printf("Z: zapas  ");
	printf("Q: navrat do menu\n\n");
	cmq = tolower(getchar());
	while (getchar() != '\n');

	switch (cmq)
	{
	case 's':
		int spid;

		printf("\nsport id : ");
		scanf_s("%d", &spid);
		while (getchar() != '\n');
		delsport(spid, &sprvni);
		break;
	case 't':
		int tid;
		printf("\ntym id : ");
		scanf_s("%d", &tid);
		while (getchar() != '\n');
		deltym(tid,&tprvni);
		break;
	case 'l':
		int lid;
		printf("\nliga id : ");
		scanf_s("%d", &lid);
		while (getchar() != '\n');
		delliga(lid,&lprvni);
		break;

	case 'z':
		int zpid;
		printf("\nzapas id : ");
		scanf_s("%d", &zpid);
		while (getchar() != '\n');
		delzapas(zpid,&zprvni);
		break;
	}
}






void zobrazit()
{
	struct sport* aktsport = sprvni; // ukazatel na aktualni auto
	struct liga* aktliga = lprvni;
	struct tym* akttym = tprvni;
	struct zapas* aktzap = zprvni;

	char sh;
		system("cls");		// smaze obrazovku
		printf("co chces tisknout\n");
		printf("S: sport    ");
		printf("L: liga    ");
		printf("T: tym    ");
		printf("Z: zapas    ");
		printf("V: kdo vyhral    ");
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
				aktsport = aktsport->sport_dalsi; 
			}
			getchar();

			break;

		case 'l':
			printf("\n\n");
			while (aktliga) // prochazeni seznamu
			{
				printf("%d %s\n", aktliga->liga_id, aktliga->liga_nazev); // tisk radku
				aktliga = aktliga->liga_dalsi; // posun na dalsi polozku
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
				akttym = akttym->tym_dalsi; // posunuti ukazatele
			}
			getchar();


			break;
		case 'z':
			printf("\n\n");
			while (aktzap) // prochazeni seznamu
			{
				int u, o,a,b;
				u = aktzap->zapas_sport;
				o = aktzap->zapas_liga;
				a = aktzap->zapas_tymA;
				b = aktzap->zapas_tymB;
				printf("%d %s %s %s %s %s %s %d %d %s\n", aktzap->zapas_id, sportp(u), ligap(o), aktzap->zapas_datum, aktzap->zapas_misto, tymp(a), tymp(b), aktzap->zapas_skoreA, aktzap->zapas_skoreB, aktzap->zapas_sazka); // tisk radku
				aktzap = aktzap->zapas_dalsi;
			}
			getchar();

			break;

		case 'v' | 'V': // zobrazeni vysledku kdo vyhral, funguje momentalne jen na prvni zapas

			while (aktzap)
			{
				int skore_tymA = aktzap->zapas_skoreA;
				int skore_tymB = aktzap->zapas_skoreB;
				char* sazka = aktzap->zapas_sazka;

				if (skore_tymA > skore_tymB) 
				{
					cout << "Tym A zvitezil " << skore_tymA << " : " << skore_tymB << " ." << endl;
					cout << "Sazejici mohl vyhrat: " << sazka << " Kc." << endl;
					
				}
				if (skore_tymA < skore_tymB)
				{
					cout << "Tym B zvitezil " << skore_tymB << " : " << skore_tymA << " ." << endl;
					cout << "Sazejici mohl vyhrat: " << sazka << " Kc." << endl;
				
				}
				if (skore_tymA == skore_tymB)
				{
					cout << "Tymy remizovali " << skore_tymA << " : " << skore_tymB << " ." << endl;
					cout << "Sazejici mohl vyhrat: " << sazka << " Kc." << endl;
					
				}
				
				aktzap = aktzap->zapas_dalsi;
			}

			
			getchar();
			

		}		
}


void ulozeni() //ulozi hodnoty z t_zapasy do soboury zapasy.txt
{
	remove("sport.txt");
	remove("liga.txt");
	remove("tym.txt");
	remove("zapas.txt");
	struct sport* aktsport = sprvni; //ulozeni sportu
	while (aktsport)
	{
		int zapis_sport_id = aktsport->sport_id;
		char* zapis_sport_nazev = aktsport->sport_nazev;

		fstream zapsport("sport.txt", ios::out | ios::app);
		if (zapsport.is_open())
		{
			zapsport << zapis_sport_id << ";" << zapis_sport_nazev << ";" << endl;
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

			zapliga << zapis_liga_id << ";" << zapis_liga_nazev << ";" << endl;

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
			zaptym << zapis_tym_id << ";" << zapis_tym_nazev << ";" << zapis_tym_sport << ";" << zapis_tym_liga << ";" << endl;
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

			zapzapas << zapis_zapas_id << ";" << zapis_zapas_sport << ";" << zapis_zapas_liga << ";" << zapis_zapas_datum << ";" << zapis_zapas_misto << ";" << zapis_zapas_tymA << ";" << zapis_zapas_tymB << ";" << zapis_zapas_skoreA << ";" << zapis_zapas_skoreB << ";" << zapis_zapas_sazka << ";" << endl;

			aktzapas = aktzapas->zapas_dalsi;
			zapzapas.close();
		}
		else
			cout << "Zapas se nepodarilo ulozit.";
	}
}
void testdata() {
	//sporty
	/*
	int sid = 0;
	char snazev[ZNACKA_SIZE] = "hokej";
	char snazev2[ZNACKA_SIZE] = "lyze";
	char snazev3[ZNACKA_SIZE] = "basket";
	addsport(max_sport_ID(),snazev, &sprvni);
	addsport(max_sport_ID(),snazev2, &sprvni);
	addsport(max_sport_ID(), snazev3, &sprvni);
	
	//liga
	int liga_id;
	char liga_nazev[ZNACKA_SIZE]="prvniL", liga_nazev1[ZNACKA_SIZE] = "druhaL", liga_nazev2[ZNACKA_SIZE] = "tretiL";
	addliga(max_liga_ID(), liga_nazev, &lprvni);
	addliga(max_liga_ID(), liga_nazev1, &lprvni);
	addliga(max_liga_ID(), liga_nazev2, &lprvni);
	*/

	//tym
	int tym_id;
	char tym_nazev[ZNACKA_SIZE]="tymA", tym_nazev1[ZNACKA_SIZE] = "tymB", tym_nazev2[ZNACKA_SIZE] = "tymC";
	int tym_sport=1, tym_sport2 = 2, tym_sport1 = 3;
	int tym_liga=1, tym_liga2=2,tym_liga1=1; //max_tym_ID()
	addtym(max_tym_ID(), tym_nazev, tym_sport, tym_liga, &tprvni);
	addtym(max_tym_ID(), tym_nazev1, tym_sport1, tym_liga1, &tprvni);
	addtym(max_tym_ID(), tym_nazev2, tym_sport2, tym_liga2, &tprvni);
	
	//zapas
	int  zapas_id; //id zapasu
	int zapas_sport=1, zapas_sport1 = 3, zapas_sport2 = 2;
	int zapas_liga=3, zapas_liga1 = 2, zapas_liga2 =1;
	char zapas_datum[ZNACKA_SIZE]="23.11.2020", zapas_datum1[ZNACKA_SIZE] = "3.12.2020", zapas_datum2[ZNACKA_SIZE] = "2.1.2020";
	char zapas_misto[ZNACKA_SIZE]="Brno", zapas_misto1[ZNACKA_SIZE] = "Praha", zapas_misto2[ZNACKA_SIZE] = "Ostrava";
	int zapas_tymA = 1, zapas_tymA1 = 2, zapas_tymA2 = 1;
	int zapas_tymB = 3, zapas_tymB1 = 1, zapas_tymB2 = 2;
	int zapas_skoreA=10, zapas_skoreA1 = 20, zapas_skoreA2 = 30;
	int zapas_skoreB=5, zapas_skoreB1 = 40, zapas_skoreB2 = 50;
	char zapas_sazka[ZNACKA_SIZE]="300", zapas_sazka1[ZNACKA_SIZE] = "200", zapas_sazka2[ZNACKA_SIZE] = "100";
	addzapas(max_zapas_ID(), zapas_sport, zapas_liga, zapas_datum, zapas_misto, zapas_tymA, zapas_tymB, zapas_skoreA, zapas_skoreB, zapas_sazka, &zprvni);
	addzapas(max_zapas_ID(), zapas_sport1, zapas_liga1, zapas_datum1, zapas_misto1, zapas_tymA1, zapas_tymB1, zapas_skoreA1, zapas_skoreB1, zapas_sazka1, &zprvni);
	addzapas(max_zapas_ID(), zapas_sport2, zapas_liga2, zapas_datum2, zapas_misto2, zapas_tymA2, zapas_tymB2, zapas_skoreA2, zapas_skoreB2, zapas_sazka2, &zprvni);
	}

//nacitani ze souboru
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
		//printf(token);
		//printf(" - ");

		lokal_id = atoi(token);
		token = strtok(NULL, ";");

		//printf(token);
		//printf("\n");

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
		addsport(lokal_id, lokal_popis, &sprvni);
	}
	fclose(ss);
}

void nacist_liga() {
	FILE* sl;
	char str[60];  //sem nacitame radky
	char* token;   // sem rozdelime polozky radku

	int lokal_id;

	sl = fopen("liga.txt", "r");
	if (sl == NULL) {
		perror("Nejde otevrit soubor");


	}
	while (fgets(str, 60, sl) != NULL) {
		token = strtok(str, ";");  // prvni token-polozka
		lokal_id = atoi(token);
		token = strtok(NULL, ";");

		const int delkatokenu = sizeof(token);
		char lokal_popis[delkatokenu];
		int i;
		for (i = 0; i < delkatokenu; i++) {
			lokal_popis[i] = token[i];
			cout << lokal_popis[i];
		}
		addliga(lokal_id, lokal_popis, &lprvni);
	}
	fclose(sl);
}





int main()
{
	nacist_sport();
	nacist_liga();
	testdata();
	

	char cmd;
	do
	{
		system("cls");		// smaze obrazovku
		printf("Hlavni menu\n");
		printf("A: Pridat    ");
		printf("S: Smazat    ");
		printf("P: Tisk    ");
		printf("Q: ukoncit\n\n");
		

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'a':
			Onadd();
			break;

		case 's':
			Ondel();					
			break;
		case 'p':
			zobrazit();
			break;

		}
	} while (cmd != 'q');     // koncime az pri Q


	//tady odkaz na zapis vseho do souboru
	ulozeni();


	return 0;
}