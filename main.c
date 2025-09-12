#include "header.h"

void    displayMenu() 
{
    printf("\n=============================MENU=========================================\n");
    printf("    1- Add new Players.\n");
    printf("    2- Display team players.\n");
    printf("    3- Edit player info.\n");
    printf("    4- Delete a player.\n");
    printf("    5- Search for a player.\n");
    printf("    6- Display team Statistics.\n");
    printf("    7- Exit.\n");
    printf("==========================================================================\n");
    printf("Select an option from the menu please: ");
}


void    checkUserChoice(int userChoice, TeamPlayers **team)
{
    switch (userChoice)
    {
        case 1:
            addNewPlayers(team);
            break;
        case 2:
            displayPlayersInfo(*team);
            break ;
        case 3:
            editPlayerInfo(*team);
            break;
        case 4:
            deletePlayer(team);
            break;
        case 5:
            seachForAplayer(*team);
            break;
        case 6:
            displayTeamStatistics(*team);
            break ;
        case 7:
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice, Please select a choice from the menu.\n");
    }
}

int main(int ac, char **av) 
{
    if (ac > 1) {
        if (!freopen(av[1], "r", stdin) || !freopen("output.txt", "w", stdout))
            printErrorAndExit("Failed opening file\n");
    }
    TeamPlayers *team = NULL;

    addTestingPlayers(&team);
    while (true)
    {
        displayMenu();
        int userChoice = readInt();
        checkUserChoice(userChoice, &team);
    }
}
