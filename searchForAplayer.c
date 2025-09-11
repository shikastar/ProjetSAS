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
    printf("Enter Id of the player you want to search: ");
    int id = readInt();
    Player *player = getPlayerWithId(id, team);
    if (player == NULL)
        printf("There is no player with id: %d in the team.\n", id);
    else displayPlayerInfo(*player);
}

void    searchByName(TeamPlayers *team)
{
    printf("Enter firstName of the player you want to search: ");
    char *name = readLine();
    Player *player = getPlayerWithName(name, team);
    if (player == NULL)
        printf("There is no player with name: %s in the team.\n", name);
    else displayPlayerInfo(*player);
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
            printf("Invalid search option.\n");
            break;
    } 
}

void    printSearchOptions()
{
    printf("Here is all search options availabe: \n");
    printf("    1- Search player by it's id.\n");
    printf("    2- Search player by it's firstName.\n");
    printf("--> option: ");
}

void    seachForAplayer(TeamPlayers *team)
{
    printSearchOptions();
    checkSearchOption(team);
}

