#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char *args[6];
char **parse_args(char *line)
{
    char *p = line;
    int i = 0;
    while (p)
    {
        args[i] = strsep(&p, " ");
        i++;
    }
    return args;
}

int main()
{
    char ls[] = "ls -a -l";
    char **args = parse_args(ls);
    execvp(args[0], args);
    return 0;
}