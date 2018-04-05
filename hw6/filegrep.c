#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    //If not enough arguments, let user know proper usage
    if (argc==1 | argc==2){
        fprintf(stderr, "Usage: filegrep PATTERN FILE\n");
        return 0;
    }
    //Pointers for our search file
    FILE *infile;
    
    //Open the input file
    if ((infile = fopen(argv[2], "r")) == NULL) {
        //If it fails, let the user know
        fprintf(stderr, "grep: %s: No such file or directory\n", argv[2]);
        return 0;
    }
    
    //Holder for each line while we search
    char line [100];
    //Line counter
    int lineNum = 1;
    //We begin by taking an input line by line
    while (fgets(line, 100, infile) != NULL) {
        //Check if we've found our search term
        char *checkText = strstr(line, argv[1]);
        //If we found it, print that line
        if(checkText){
            printf("%d:", lineNum);
            fputs(line, stdout);
        }
        lineNum++;
    }
    return 0;
}
