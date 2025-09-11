#include "header.h"

void    setPlayerId(Player *player)
{
    static int id = 8;
    id++;

    player->id = id;
}

void    readFirstAnsSecondName(Player *player, TeamPlayers *team) 
{
    do {
        printf("    Enter player first  name: ");
        player->firstName = readLine();
        printf("    Enter player second name: ");
        player->secondName = readLine();
    } while (isInvalidName(player, team));
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
        printf("    Enter player position: \n");
        printf("     -goalkeeper\n");
        printf("     -defender\n");
        printf("     -midfielder\n");
        printf("     -striker\n");
        printf("--> choice: ");
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
    do {
        printf("    Enter player number of goals scored: ");
        player->goalsScored = readInt();
        if (player->goalsScored < 0)
            printf ("goals scored should be a non negative integer. please try again.\n");
    } while (player->goalsScored < 0) ;
}

void    readInscriptionDate(Player *player)
{
    do {
        printf("    Enter inscription date:\n");
        printf("         Enter the year of inscription: ");
        player->inscriptionDate.year = readInt();
        printf("         Enter the month of inscription: ");
        player->inscriptionDate.month = readInt();
        printf("         Enter the day of inscription: ");
        player->inscriptionDate.day = readInt();
    } while (isInvalidDate(player->inscriptionDate));
}

void    readStatus(Player *player)
{
    do 
    {
        printf("    Enter player status: \n");
        printf("     -starting\n");
        printf("     -substitute\n");
        printf("       --> choice: ");
        player->status = readLine();
    } while (isInvalidStatus(player->status));
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
    int numOfNewPlayers; 
    do {
        printf("Please enter number of new players that you want to add :");
        numOfNewPlayers = readInt();
        if (numOfNewPlayers <= 0) printf("number of players to add should be a positive integer, try again please.\n");
    } while (numOfNewPlayers <= 0);
    

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
