#include "header.h"


void    displayMenu() 
{
    printf("\n=============================MENU=========================================\n");
    printf("    1- Add new Players.\n");
    printf("==========================================================================\n");
    printf("Select an option from the menu please: ");
}


void    checkUserChoice(int userChoice, TeamPlayers *team)
{
    switch (userChoice)
    {
        case 1:
            addNewPlayers(team);
            break;
        default:
            printf("Invalid choice, Please select a choice from the menu.");
    }
}

int main() 
{
    TeamPlayers *team = NULL;

    while (true)
    {
        displayMenu();
        int userChoice;
        scanf("%d", &userChoice); getchar();
        checkUserChoice(userChoice, team);
    }
}