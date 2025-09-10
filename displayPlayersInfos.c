#include "header.h"

void    displayPlayerInfo(Player player)
{
    printf("Player Info: \n");
    printf("    player id: %d.\n", player.id);
    printf("    player firstName: %s.\n", player.firstName);
    printf("    player secondName: %s.\n", player.secondName);
    printf("    player tshistNumber: %d.\n", player.tshirtNumber);
    printf("    player position: %s.\n", player.position);
    printf("    player age: %d.\n", player.age);
    printf("    player goalsScored: %d.\n", player.goalsScored);
    printf("    player insctiption date: %d, %d, %d.\n",
            player.inscriptionDate.day, player.inscriptionDate.month, player.inscriptionDate.year);
    printf("    player status: %s.\n", player.status);
}

void    displayTeamPlayers(TeamPlayers *team)
{
    while (team) 
    {
        displayPlayerInfo(team->player);
        team = team->next;
    }
}

void    swapPlayers(TeamPlayers *player1, TeamPlayers *player2)
{
    Player tmp = player1->player;
    player1->player = player2->player;
    player2->player = tmp;
}

void    sortTeamPlayers(TeamPlayers *team, bool nameOrAge)
{
    TeamPlayers *head = team;
    while (team)
    {
        TeamPlayers *tmp = team->next;
        while (tmp) {
            if (nameOrAge == SORT_BY_NAME){
                if (strcmp(team->player.firstName, tmp->player.firstName) > 0) // teamName > tmpName
                    swapPlayers(team, tmp);
            }
            else {
                // by age
                if (team->player.age > tmp->player.age) swapPlayers(team, tmp);
            }

            tmp= tmp->next;
        }
        team = team->next;
    }
    printf("here is all team players sorted by ");
    if (nameOrAge == SORT_BY_NAME) printf("firstName:\n");
    else printf("age:\n");
    displayTeamPlayers(head);
}

void    displayPlayersInfo(TeamPlayers *team) 
{
    if (team == NULL) {
        printf("There is no players in the team.\n");
        return ;
    }
    printf("Enter in which format you want to display players of the team.\n");
    printf("    1- sorted in alphabetic order of first Names.\n");
    printf("    2- sorted by age(from small to bigger).\n");
    printf("    3- listed by position.\n");
    int choice;
    scanf("%d", &choice); getchar();


    switch (choice)
    {
        case 1 :
            sortTeamPlayers(team, SORT_BY_NAME);
            break;
        case 2 :
            sortTeamPlayers(team, SORT_BY_AGE);
            break;
        case 3 :
            break;
        default :
            printf("Invalid choice.\n");
            break;
    }
}
