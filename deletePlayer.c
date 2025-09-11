#include "header.h"

void    deletePlayer(TeamPlayers **team)
{
    printf("Enter identifier of the player that you want to delete: ");
    int idToDelete = readInt();
    
    TeamPlayers *head = *team;
    TeamPlayers *prev = NULL;
    while (head)
    {
        if (head->player.id == idToDelete)
        {
            if (prev == NULL) *team = head->next;
            else prev->next = head->next;
            free(head);
            printf("Player with identifier %d is successfully deleted.\n", idToDelete);
            return ;
        }
        prev = head;
        head = head->next;
    }
    printf("There is no player with id: %d in the team.\n", idToDelete);
}