#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

#define SORT_BY_AGE  0
#define SORT_BY_NAME 1
#define MAX_SHIRT_NUM 500

typedef struct
{
    int     day;
    int     month;
    int     year;
}           Date; 

typedef struct 
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


typedef struct          TeamPlayers 
{
    Player              player;
    struct TeamPlayers *next;
}                       TeamPlayers;


void    addNewPlayers(TeamPlayers **team);
char    *readLine(void);
void    printErrorAndExit(const char *error);
void    displayPlayersInfo(TeamPlayers *team);
void    displayTeamPlayers(TeamPlayers *team);
int     readInt(void);
void    editPlayerInfo(TeamPlayers *team);
void    seachForAplayer(TeamPlayers *team);
Player  *getPlayerWithId(int id, TeamPlayers *team); 
void    displayPlayerInfo(Player player);
void    displayTeamStatistics(TeamPlayers *team);
void    deletePlayer(TeamPlayers **team);
void    addTestingPlayers(TeamPlayers **team);
