#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SORT_BY_AGE  0
#define SORT_BY_NAME 1

typedef struct Date
{
    int     day;
    int     month;
    int     year;
}           Date; 

typedef struct Player
{
    int     id;
    char    *firstName;
    char    *secondName;
    int     tshirtNumber;
    char    *position;
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


void    addNewPlayers(TeamPlayers **team);
char    *readLine(void);
void    printErrorAndExit(const char *error);
void    displayPlayersInfo(TeamPlayers *team);
void    displayTeamPlayers(TeamPlayers *team);
