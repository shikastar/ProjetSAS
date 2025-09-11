#include "header.h"

void    deletePlayer(TeamPlayers **team)
{
    printf("Enter identifier of the player that you want to delete: ");
    int idToDelete = readInt();
    
    bool isDeleted = 0;
    TeamPlayers *head = *team;
    TeamPlayers *prev = NULL;
    while (head)
    {
        if (head->player.id == idToDelete)
        {
            if (prev == NULL) *team = head->next;
            else prev->next = head->next;
            free(head);
            isDeleted = 1;
            break; 
        }
        prev = head;
        head = head->next;
    }
    if (isDeleted)
        printf("Player with identifier %d is successfully deleted.\n", idToDelete);
    else
        printf("There is no player with id: %d in the team.\n", idToDelete);
}