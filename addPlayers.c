#include "header.h"


// read Player Data

void    setPlayerId(Player *player)
{
    static int id = 0;
    id++;

    player->id = id;
}

void    readFirstAnsSecondName(Player *player) 
{
    printf("    Enter player first  name: ");
    player->firstName = readLine();
    printf("    Enter player second name: ");
    player->secondName = readLine();
}

void    readTshirtNumber(Player *player)
{
    printf("    Enter player tshirt number: ");
    player->tshirtNumber = readInt();
}

void    readPosition(Player *player)
{
    printf("    Enter player position: ");
    player->position = readLine();
}


void    readAge(Player *player)
{
    printf("    Enter player age: ");
    player->age = readInt();
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

Player  createNewPlayer()
{
    Player newPlayer;

    setPlayerId(&newPlayer);
    readFirstAnsSecondName(&newPlayer);
    readTshirtNumber(&newPlayer);
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
    if (!newPlayer) printErrorAndExit("Allocation failure.\n");
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
        Player player = createNewPlayer();
        addNewPlayer(team, player);
    }
}
