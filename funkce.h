#pragma once
#define ZNACKA_SIZE 15

struct t_databaze //seznam na veci z bodu 1
{

    char  sport[ZNACKA_SIZE]; 
    char  liga[ZNACKA_SIZE]; 
    char  tym[ZNACKA_SIZE];
    char  kurz[ZNACKA_SIZE];
    struct t_databaze* dalsi;
};

struct t_zapasy //veci na bod2: podrobne infomace o zapasu
{ 
    int cislozap; //id zapasu
    char tema[ZNACKA_SIZE];
    char cas[ZNACKA_SIZE];
    char datum[ZNACKA_SIZE];
    char misto[ZNACKA_SIZE];
    char sazky[ZNACKA_SIZE];
    struct t_zapasy* next;
};


void pridat(char* sport, char* liga, char* tym, char* zapas,char* kurz , struct t_databaze** uk_prvni);
void smazat(char* sport, char* liga, char* tym, char* zapas, char* kurz, struct t_databaze** uk_prvni);

    char  nazevsportu[ZNACKA_SIZE];
    int   rok;
    char  tymy[30];
    struct t_sporty* dalsi;
};

//test niceho
//tesrt merge

