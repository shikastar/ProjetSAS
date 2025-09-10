#include "header.h"


Player *getPlayerWithName(char *name, TeamPlayers *team)
{
    while (team)
    {
        if (!strcmp(name, team->player.firstName))
            return &team->player;
        team = team->next;
    }
}


void    searchById(TeamPlayers *team) 
{
    int id = readInt();
    Player *player = getPlayerWithId(id, team);
    if (player == NULL) {
        printf("No player with id :%d exist in the team.\n", id);
        return ;
    }
    displayPlayerInfo(*player);
}

void    searchByName(TeamPlayers *team)
{
    char *name = readLine();
    Player *player = getPlayerWithName(name, team);
    if (player == NULL) {
        printf("No player with name :%s exist in the team.\n", name);
        return ;
    }
    displayPlayerInfo(*player);
}

void    checkSearchOption(TeamPlayers *team) 
{
    int option = readInt();
    switch (option)
    {
        case 1 :
            searchById(team);
            break;
        case 2 :
            searchByName(team);
            break;
        default :
            printf("invalid search option.\n");
            break;
    } 
}

void    printSearchOptions()
{
    printf("here is all search options availabe: \n");
    printf("    1- Search player by it's id.\n");
    printf("    2- Search player by it's firstName.\n");
    // to add other options.
}

void    seachForAplayer(TeamPlayers *team)
{
    printSearchOptions();
    checkSearchOption(team);
}

