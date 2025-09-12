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
    do 
    {
        printf("Enter player new position: ");
        player->position = readLine();
    } while (isInvalidPosition(player->position));
    printf("player position succesfully changed.\n");
}

void    changePlayerAge(Player *player)
{
    do {
        printf("Enter player new age: ");
        player->age = readInt();
    } while (isInvalidAge(player->age));
    printf("player age have succesfully changed.\n");
}

void    changePlayerScoredGoals(Player *player)
{
    do
    {
        printf("Enter player new number of scored goals: ");
        player->goalsScored = readInt();
        if (player->goalsScored < 0)
            printf ("goals scored should be a non negative integer. please try again.\n");
        else if (player->goalsScored > 10) 
            printf("player %s %s is a team star, he scored %d goals.\n", player->firstName,
            player->secondName, player->goalsScored);
    } while (player->goalsScored < 0);
    printf("player goal scored have succesfully changed.\n");
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
        case 4 :
            break ;
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
    printf("    4- Exit.\n");
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
