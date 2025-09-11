#include "header.h"


Player  *getPlayerWithId(int id, TeamPlayers *team) 
{
    while (team)
    {
        if (team->player.id == id) return (&team->player);
        team = team->next;
    }
    return NULL;
}

void    changePlayerPosition(Player *player)
{
    printf("Enter player new position: ");
    char *newPosition = readLine();
    player->position = newPosition;
    // to add : check if it is valid position
}

void    changePlayerAge(Player *player)
{
    printf("Enter player new age: ");
    int newAge = readInt();
    player->age = newAge;
}

void    changePlayerScoredGoals(Player *player)
{
    printf("Enter player new number of scored goals: ");
    int newGoalsScored = readInt();
    player->goalsScored = newGoalsScored;
}

void    checkEditOption(int option, Player *player)
{
    switch (option)
    {
        case 1:
            changePlayerPosition(player);
            break;
        case 2:
            changePlayerAge(player);
            break;
        case 3:
            changePlayerScoredGoals(player);
            break;
        default :
            printf("Invalid edit player option.\n");
    }
}

void    printEditOptions()
{
    printf("Here is the edit options availables:\n");
    printf("    1- change player position.\n");
    printf("    2- change player age.\n");
    printf("    3- change player number of goals scored.\n");
    printf("--> option: ");
}

void    editPlayerInfo(TeamPlayers *team)
{
    displayTeamPlayers(team);
    printf("Please Enter player id that you want to edit: ");
    int id = readInt();
    Player *player = getPlayerWithId(id, team);
    if (player == NULL) {
        printf("There is no player with id : %d in the team.\n", id);
        return ;
    }
    printEditOptions();
    int option = readInt();
    checkEditOption(option, player);
}
