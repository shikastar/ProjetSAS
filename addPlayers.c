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
    scanf("%d", &player->tshirtNumber); getchar();
}

void    readPosition(Player *player)
{
    printf("    Enter player position: ");
    player->position = readLine();
}


void    readAge(Player *player)
{
    printf("    Enter player age: ");
    scanf("%d", &player->age); getchar();
}

void    readGoalsScored(Player *player)
{
    printf("    Enter player number of goals scored: ");
    scanf("%d", &player->goalsScored); getchar();
}

void    readInscriptionDate(Player *player)
{
    printf("    Enter inscription date:\n");
    printf("         Enter the year of inscription: ");
    scanf("%d", &player->inscriptionDate.year); getchar();
    printf("         Enter the month of inscription: ");
    scanf("%d", &player->inscriptionDate.month); getchar();
    printf("         Enter the day of inscription: "); getchar();
    scanf("%d", &player->inscriptionDate.day); getchar();
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


void    addNewPlayers(TeamPlayers *team)
{
    printf("Please enter number of new players that you want to add :");
    int numOfNewPlayers;
    scanf("%d", &numOfNewPlayers); getchar();

    for (int i = 0; i < numOfNewPlayers; i++)
    {
        printf("    Please Enter player number %d data.\n", i + 1);
        Player player = createNewPlayer();
        addNewPlayer(&team, player);
    }
}
