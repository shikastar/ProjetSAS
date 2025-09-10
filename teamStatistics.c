#include "header.h"


void    displayNumberOfplayers(TeamPlayers *team)
{
    int numberOfPlayers = 0;
    while (team)
    {
        numberOfPlayers++;
        team = team->next;
    }
    printf("Number of players in the team is : %d\n", numberOfPlayers);
}

void    displayPlayersAverageAge(TeamPlayers *team)
{
    int numberOfPlayers = 0;
    float agesSum = 0;
    
    while (team)
    {
        agesSum += team->player.age;
        numberOfPlayers++;
        team = team->next;
    }

    float average = 0;
    if (numberOfPlayers) average = agesSum / numberOfPlayers;
    printf("Average age of players in the team is : %.2f\n", average);
}

void    checkStatisticsOption(TeamPlayers *team)
{
    int option = readInt();
    switch (option)
    {
        case 1:
            displayNumberOfplayers(team);
            break;
        case 2:
            displayPlayersAverageAge(team);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("Invalid statistics option.\n");
    }
}


void    displayStatisticsMenu()
{
    printf("here is the statistics options available.\n");
    printf("    1- Display number of players in the team.\n");
    printf("    2- Display average age of players in the team.\n");
    printf("    3- Display number of players that score more that X goals.\n");
    printf("    4- Displaye the best goalScorer in the team.\n");
    printf("    5- Display the youngest and the oldest player in the team.");
}

void    displayTeamStatistics(TeamPlayers *team)
{
    displayStatisticsMenu();
    checkStatisticsOption(team);
}
