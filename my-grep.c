//TE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv){
    FILE *file;
    int   i=2;
    char pattern[100],string1[2000];

//Test there is an input
if (argc < 2){
    printf("my-grep: searchterm [file ...]\n");
    exit(1);
    }
//If only pattern provided    
if (argc == 2) {
    printf("Only pattern given\n");
    strcpy(pattern,argv[1]);
    //Ask for text and try to match the pattern, if matched, print
    printf("Give text to match the pattern: ");
    fgets(string1,2000, stdin);
    if(strstr(string1,pattern))
        printf("%s",string1);
    exit(0);

}
//If 1 or more files provided
if (argc > 2) {
    //Loop through all the given arguments, as input files
    while(argv[i] != NULL) {
        //Open and test the file opened correctly
        file = fopen(argv[i], "r");
        if (file == NULL){
            fprintf(stderr, "my-grep: cannot open file\n");
            exit(1);
        }
        //set the pattern
        strcpy(pattern,argv[1]);
        //loop through the file, if pattern match is made, print the line
        while(!feof(file)) {
            fgets(string1,2000,file);
            if(strstr(string1,pattern))
                printf("%s",string1);
        }
        
        //close file and get next argument in loop
        fclose(file);
        i++;
    }
}
exit(0);

}