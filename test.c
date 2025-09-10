#include <stdlib.h>
#include <stdio.h>

int main() 
{
     size_t len = 0;
    char *line = NULL;
    printf("enter:");
    size_t read = getline(&line, &len, stdin);
    // printf("enter:");
    // printf("%s", line);
    line = NULL;
    read = getline(&line, &len, stdin);
    printf("%s", line);
}