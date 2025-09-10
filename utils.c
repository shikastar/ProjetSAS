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
    int read = getline(&line, &len, stdin);
    if (read < 0) {
        // reach end of file
        printf("reach end of file.\n");
        exit(EXIT_SUCCESS);
    }
    if (line[strlen(line) -1] == '\n') line[strlen(line) - 1] = '\0';
    return line;
}

bool    isInvalidInteger(char *s)
{
    if (!s) return 1;
    int i = 0;
    long long num = 0;
    while (s[i]) {
        if (!isdigit(s[i])) return 1;
        num = num * 10 + s[i] - '0';
        if (num > INT_MAX) return 1;
        i++;
    }
    return 0;
}

int readInt(void)
{
    char *line = readLine();
    if (isInvalidInteger(line))
        printErrorAndExit("Invalid Integer.\n");
    return atoi(line);
}
