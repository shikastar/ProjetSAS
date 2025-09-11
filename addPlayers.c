#include "header.h"

void    setPlayerId(Player *player)
{
    static int id = 8;
    id++;

    player->id = id;
}

bool    playerAlreadyExist(Player *player, TeamPlayers *team)
{
    bool    alreadyExist = 0;
    while (team)
    {
        if (!strcmp(player->firstName, team->player.firstName)
        && !strcmp(player->secondName, team->player.secondName)) {
            alreadyExist = 1;
            break;
        }
        team = team->next;
    }
    if (alreadyExist) {
        printf("    There is already a player with name : %s %s in the team.\n", player->firstName, player->secondName);
        printf("    Please chose new name for the new player.\n");
        return 1;
    }
    return 0;
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

void    readFirstAnsSecondName(Player *player, TeamPlayers *team) 
{
    do {
        printf("    Enter player first  name: ");
        player->firstName = readLine();
        printf("    Enter player second name: ");
        player->secondName = readLine();
    } while (playerAlreadyExist(player, team));
}

bool    shirtNumberAlreadyExist(int shirtNumber, TeamPlayers *team) {
    while (team) 
    {
        if (team->player.tshirtNumber == shirtNumber)
            return true ;
        team = team->next;
    }
}

bool    isInvalidShirtNumber(int shirtNumber, TeamPlayers *team) {
    if (shirtNumber < 0 || shirtNumber > MAX_SHIRT_NUM)
    {
        printf("Shirt number should be a positive integer less than %d", MAX_SHIRT_NUM);
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
    if 
}

void    readTshirtNumber(Player *player, TeamPlayers *team)
{
    do {
        printf("    Enter player tshirt number: ");
        player->tshirtNumber = readInt();
    } while (isInvalidShirtNumber(player->tshirtNumber, team));
}

void    readPosition(Player *player)
{
    do {
        printf("    Enter player position: ");
        printf("     -goalkeeper\n");
        printf("     -defender\n");
        printf("     -midfielder\n");
        printf("     -striker\n");
        player->position = readLine();
    } while (isInvalidPosition(player->position));
}

void    readAge(Player *player)
{
    do {
        printf("    Enter player age: ");
        player->age = readInt();
    } while (isInvalidAge(player->age));
}

void    readGoalsScored(Player *player)
{
    printf("    Enter player number of goals scored: ");
    player->goalsScored = readInt();
}

void    readInscriptionDate(Player *player)
{
    printf("    Enter inscription date:\n");
    printf("         Enter the year of inscription: ");
    player->inscriptionDate.year = readInt();
    printf("         Enter the month of inscription: ");
    player->inscriptionDate.month = readInt();
    printf("         Enter the day of inscription: ");
    player->inscriptionDate.day = readInt();
}

void    readStatus(Player *player)
{
    printf("    Enter player status: ");
    player->status = readLine();
}

Player  createNewPlayer(TeamPlayers *team)
{
    Player newPlayer;

    setPlayerId(&newPlayer);
    readFirstAnsSecondName(&newPlayer, team);
    readTshirtNumber(&newPlayer, team);
    readPosition(&newPlayer);
    readAge(&newPlayer);
    readGoalsScored(&newPlayer);
    readInscriptionDate(&newPlayer);
    readStatus(&newPlayer);
    return newPlayer;
}

// add players:

void    addNewPlayer(TeamPlayers **team, Player player)
{
    TeamPlayers *newPlayer = malloc(sizeof(TeamPlayers));
    if (!newPlayer) printErrorAndExit("Error: Allocation failure.\n");
    newPlayer->player = player;
    newPlayer->next = NULL;

    if (*team == NULL)       // still no player in the team
        *team = newPlayer;
    else {
        newPlayer->next = *team;
        *team = newPlayer;               // head of team point on new player added
    }
}


void    addNewPlayers(TeamPlayers **team)
{
    printf("Please enter number of new players that you want to add :");
    int numOfNewPlayers = readInt();
    if (numOfNewPlayers )

    for (int i = 0; i < numOfNewPlayers; i++)
    {
        printf("    Please Enter player number %d data.\n", i + 1);
        Player player = createNewPlayer(*team);
        addNewPlayer(team, player);
    }
}

void    addTestingPlayers(TeamPlayers **team)
{
    Player arrOfPLayers[] = {
    {1, "Erling", "Haaland", 9, "striker", 24, 195, {14, 7, 2022}, "starting"},
    {2, "Kylian", "Mbappe", 7, "striker", 25, 280, {31, 8, 2017}, "starting"},
    {3, "Kevin", "De Bruyne", 17, "midfielder", 32, 95, {10, 7, 2015}, "starting"},
    {4, "Virgil", "van Dijk", 4, "defender", 32, 25, {3, 1, 2018}, "starting"},
    {5, "Alisson", "Becker", 1, "goalkeeper", 30, 0, {19, 7, 2018}, "starting"},
    {6, "Mason", "Mount", 19, "midfielder", 25, 32, {12, 9, 2021}, "substitute"},
    {7, "Achraf", "Settar", 23, "goalkeeper", 23, 0, {11, 9, 2025}, "substitute"}
    };

    for (int i = 0; i < 7; i++)
        addNewPlayer(team, arrOfPLayers[i]);
}
