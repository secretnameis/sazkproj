#pragma once
#define ZNACKA_SIZE 15

struct t_databaze //seznam na veci z bodu 1
{
    
    char  sport[ZNACKA_SIZE];// ukladat do souboru sporty
    char  liga[ZNACKA_SIZE]; 
    char  tym[ZNACKA_SIZE];     
    char  kurz[ZNACKA_SIZE]; //nevim jak zapracovat
    struct t_databaze* dalsi;
};

struct t_zapasy //veci na bod2: podrobne infomace o zapasu
{  //ulozit treba spolecne s info z t_databaze na jeden radek v txt, to pak vypisovat (oddelit treba ;)
    int cislozap; //id zapasu
    char tema[ZNACKA_SIZE];
    char cas[ZNACKA_SIZE];
    char datum[ZNACKA_SIZE];
    char misto[ZNACKA_SIZE];
    char stav[ZNACKA_SIZE]; //kolik kdo dostal bodu / kdo vyhral
    struct t_zapasy* next;
};


void pridat(char* sport, char* liga, char* tym, char* zapas,char* kurz , struct t_databaze** uk_prvni);  //upravit
void smazat(char* sport, char* liga, char* tym, char* zapas, char* kurz, struct t_databaze** uk_prvni); //upravit