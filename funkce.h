#pragma once
#define ZNACKA_SIZE 30

struct t_databaze //seznam na veci z bodu 1
{
    char  sport[ZNACKA_SIZE];  // sporty + id do souboru sport.txt
    int   spid; // id sportu pro dalsi pouziti
    char  liga[ZNACKA_SIZE]; // ukladat do souboru liga.txt + sport id (liga, tym, kurz)
    char  tym[ZNACKA_SIZE]; // id zapasu ulozit k tymu, bude vyuzito k printu     
    char  kurz[ZNACKA_SIZE]; //nevim jak zapracovat
    
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



 
//seznam ukolu 
/*
ziskavani id pro zapasy, aby to nekolidovalo po smaz�n�
zapis do souboru
cteni ze souboru do pole
funkce mazat
 
*/
