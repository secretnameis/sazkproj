#pragma once
#define ZNACKA_SIZE 15

struct t_databaze //seznam na veci z bodu 1
{
    char  sport[ZNACKA_SIZE];  // sporty + id do souboru sport.txt
    int   spid; // id sportu pro dalsi pouziti
    char  liga[ZNACKA_SIZE]; // ukladat do souboru liga.txt + sport id (liga, tym, kurz)
    char  tym[ZNACKA_SIZE];     
    char  kurz[ZNACKA_SIZE]; //nevim jak zapracovat
    // pomoci id zapasu ulozit k tymu
    struct t_databaze* dalsi;
};

struct t_zapasy //veci na bod2: podrobne infomace o zapasu
{   //ukladat do souboru zapas.txt (vse nize + sport id + liga dle vyberu)
    int  idzap; //id zapasu
     
    char tema[ZNACKA_SIZE];
    char cas[ZNACKA_SIZE];
    char datum[ZNACKA_SIZE];
    char misto[ZNACKA_SIZE];
    char stav[ZNACKA_SIZE]; //kolik kdo dostal bodu / kdo vyhral
    struct t_zapasy* next;
};


void pridat(char* sport, char* liga, char* tym, char* zapas,char* kurz , struct t_databaze** uk_prvni);  //upravit
void smazat(char* sport, char* liga, char* tym, char* zapas, char* kurz, struct t_databaze** uk_prvni); //upravit