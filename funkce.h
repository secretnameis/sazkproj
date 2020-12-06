#pragma once
#define ZNACKA_SIZE 30

struct t_sporty
{
    char  nazevsportu[ZNACKA_SIZE];
    int   rok;
    char  tymy[30];
    struct t_sporty* dalsi;
};

//test niceho
//tesrt merge