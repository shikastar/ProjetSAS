#include "header.h"

void    printErrorAndExit(const char *error)
{
    fputs(error, stderr);
    exit(EXIT_FAILURE);
}

bool    isWhiteSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v');
}

char    *trimWhiteSpaces(char *s)
{
    while (s && isWhiteSpace(*s)) {
        if (*s != ' ' && *s != '\t') break;
        s++;
    }
    char *end = s + strlen(s) - 1;
    while (end > s && isWhiteSpace(*end)) {
        *end = '\0';
        end--;
    }
    return s;
}

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
    line = trimWhiteSpaces(line);
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
        return -1;
    else return atoi(line);
}
