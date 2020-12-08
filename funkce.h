#pragma once
#define ZNACKA_SIZE 30
   
//pridelat funkce na prochazeni poli
struct sport {

    int  sport_id;
    char sport_nazev[ZNACKA_SIZE];
    struct sport* sport_dalsi;
};

struct liga {
    int liga_id;
    char liga_nazev[ZNACKA_SIZE];
    struct liga* liga_dalsi;
};

struct tym {
    int tym_id;
    char  tym_nazev[ZNACKA_SIZE];
    int tym_sport;
    int tym_liga;
    struct tym* tym_dalsi;
};

struct zapas //veci na bod2: podrobne infomace o zapasu
{
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
    struct zapas* zapas_dalsi;
};

void addsport(int sport_id, char* sport_nazev, struct sport** sport_prvni);
void addliga(int liga_id, char* liga_nazev, struct liga** liga_prvni);
void addtym(int tym_id,char* tym_nazev,int tym_sport,int tym_liga, struct tym** tym_prvni);
void addzapas(int zapas_id, int zapas_sport, int zapas_liga, char* zapas_datum, char* zapas_misto, int zapas_tymA, int zapas_tymB, int zapas_skoreA, int zapas_skoreB, char* zapas_sazka, struct zapas** zapas_prvni);
