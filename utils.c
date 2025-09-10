#include "header.h"

void    printErrorAndExit(const char *error)
{
    perror(error);
    exit(EXIT_FAILURE);
}

// to read a full line including spaces
char    *readLine(void)
{
    size_t len = 0;
    char *line = NULL;
    size_t read = getline(&line, &len, stdin);
    if (read < 0)
        printErrorAndExit("Error in reading line.\n");
    line[strlen(line) - 1] = '\0';
    return line;
}