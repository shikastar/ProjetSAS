#include "header.h"

bool    playerAlreadyExist(Player *player, TeamPlayers *team)
{
    bool    alreadyExist = 0;
    while (team)
    {
        if (!strcmp(player->firstName, team->player.firstName)
        && !strcmp(player->secondName, team->player.secondName)) {
            alreadyExist = 1;
            break ;
        }
        team = team->next;
    }
    if (alreadyExist) {
        printf("    There is already a player with name : %s %s in the team.\n", player->firstName, player->secondName);
        printf("    Please chose a new name for the new player.\n");
        return true;
    }
    return false;
}

bool    isInvalidPosition(char *position)
{
    char *possiblePosition[] = {"goalkeeper", "striker", "midfeilder", "defender"}; 
    for (int i = 0; i < 4; i++) {
        if (!strcmp(possiblePosition[i], position)) return false;
    }
    printf("    Invalid player position please try again.\n");
    return true;
}

bool    shirtNumberAlreadyExist(int shirtNumber, TeamPlayers *team) {
    while (team) 
    {
        if (team->player.tshirtNumber == shirtNumber)
            return true ;
        team = team->next;
    }
    return false;
}

bool    isInvalidShirtNumber(int shirtNumber, TeamPlayers *team) {
    if (shirtNumber < 0 || shirtNumber > MAX_SHIRT_NUM)
    {
        printf("Shirt number should be a positive integer less than %d.\n", MAX_SHIRT_NUM);
        return true;
    }
    if (shirtNumberAlreadyExist(shirtNumber, team)) {
        printf("Shirt number already exist.\n");
        return true ;
    }
    return false;
}

bool    isInvalidAge(int age)
{
    if (age <= 0 || age > MAX_AGE) {
        printf("Age should be a positive integer less than %d. try again please.\n", MAX_AGE);
        return true ;
    }
    return false;
}

bool    isInvalidDate(Date date)
{
    bool isInvalid = (date.day < 0 || date.month < 0 || date.year < 0
        || date.day > 31 || date.month > 12  || date.year > 2025);

    if (isInvalid) {
        printf("Invalid date. please try again.\n");
        return true ;
    }
    return false;
}
