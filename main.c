#include "header.h"

void    displayMenu() 
{
    printf("\n=============================MENU=========================================\n");
    printf("    1- Add new Players.\n");
    printf("    2- Display team players.\n");
    printf("    3- Edit player info.\n");
    printf("==========================================================================\n");
    printf("Select an option from the menu please: \n");
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
            // delete
            break;
        case 5:
            seachForAplayer(*team);
            break;
        default:
            printf("Invalid choice, Please select a choice from the menu.");
    }
}

int main(int ac, char **av) 
{
    if (ac > 1) freopen(av[1], "r", stdin);
    TeamPlayers *team = NULL;
    while (true)
    {
        displayMenu();
        int userChoice = readInt();
        checkUserChoice(userChoice, &team);
    }
}