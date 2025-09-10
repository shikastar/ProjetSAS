#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct Date
{
    int     day;
    int     month;
    int     year;
}           Date; 

typedef struct Player
{
    int     id;
    char    *nom;
    char    *prenom;
    int     tshirtNumber;
    int     position;
    int     age;
    int     goalsScored;
    Date    inscriptionDate;
    char    *status;
}           Player;


typedef struct TeamPlayers 
{
    Player player;
    struct TeamPlayers *next;
}               TeamPlayers;
