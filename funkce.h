#pragma once
#define ZNACKA_SIZE 30

struct t_sporty
{
    char  nazevsportu[ZNACKA_SIZE];
    int   rok;
    char  album[30];
    struct t_sporty* dalsi;
};

