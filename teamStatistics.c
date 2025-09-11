#include "header.h"


void    displayNumberOfPlayers(TeamPlayers *team)
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

    float averageAge = 0;
    if (numberOfPlayers) averageAge = agesSum / numberOfPlayers;
    printf("Average age of players in the team is : %.2f\n", averageAge);
}

void    displayBestScorerPlayer(TeamPlayers *team)
{
    if (team == NULL) {
        printf("There is no players in the team.\n");
        return ;
    }
    Player bestScorer = team->player;

    while (team)
    {
        if (team->player.goalsScored > bestScorer.goalsScored)
            bestScorer = team->player;
        team = team->next;
    }

    printf("The best goals scorer in the team is %s %s, he scored %d goals.\n",
        bestScorer.firstName, bestScorer.secondName, bestScorer.goalsScored);
}

void    displayYoungestandOldestPlayer(TeamPlayers *team)
{
    if (team == NULL) {
        printf("There is no players in the team.\n");
        return ;
    }
    Player youngestPlayer = team->player;
    Player oldestPlayer = team->player;
    while (team)
    {
        if (team->player.age < youngestPlayer.age) youngestPlayer = team->player;
        if (team->player.age > oldestPlayer.age) oldestPlayer = team->player;
        team = team->next;
    }
    printf("The youngest player in the team is : %s %s, his age is : %d.\n",
        youngestPlayer.firstName, youngestPlayer.secondName, youngestPlayer.age);
    printf("The oldest player in the team is : %s %s, his age is : %d.\n", 
        oldestPlayer.firstName, oldestPlayer.secondName, oldestPlayer.age);
}

void    displayPlayersScoringXgoals(TeamPlayers *team)
{
    printf("Enter the number X: ");
    int X = readInt();

    printf("List of players that scored more than %d goals: \n", X);
    while (team)
    {
        if (team->player.goalsScored > X) 
            printf(" %s %s, goals scored is : %d.\n", team->player.firstName, team->player.secondName, team->player.goalsScored);
        team = team->next;
    }
}

void    checkStatisticsOption(TeamPlayers *team)
{
    int option = readInt();
    switch (option)
    {
        case 1:
            displayNumberOfPlayers(team);
            break;
        case 2:
            displayPlayersAverageAge(team);
            break;
        case 3:
            displayPlayersScoringXgoals(team); 
            break;
        case 4:
            displayBestScorerPlayer(team);
            break;
        case 5:
            displayYoungestandOldestPlayer(team); 
            break;
        default:
            printf("Invalid statistics option.\n");
    }
}


void    displayStatisticsMenu()
{
    printf("Here are the statistics options available: \n");
    printf("    1- Display number of players in the team.\n");
    printf("    2- Display average age of players in the team.\n");
    printf("    3- Display number of players that score more that X goals.\n");
    printf("    4- Display the best goalScorer in the team.\n");
    printf("    5- Display the youngest and the oldest player in the team.\n");
    printf("---> option: ");
}

void    displayTeamStatistics(TeamPlayers *team)
{
    displayStatisticsMenu();
    checkStatisticsOption(team);
}
