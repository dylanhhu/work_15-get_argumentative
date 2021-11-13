#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


char ** parse_args(char *line);


int main() {
    char args[] = "ls -a -l";
    execvp("ls", parse_args(args));

    return 0;
}


char ** parse_args(char *line) {
    char **arg_array = calloc(5, sizeof(char *)); // assuming less than 5 args
    
    char *curr = line;
    char *token;

    int i = 0;
    while ((token = strsep(&curr, " ")) != NULL) {
        arg_array[i] = token;

        i++;
    }

    return arg_array;
}
