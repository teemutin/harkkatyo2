#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv){
    FILE *file;
    int   i=2;
    char pattern[100],string1[200];

//Test there is an input
if (argc < 2){
    printf("my-grep: searchterm [file ...]\n");
    exit(1);
    }
//Loop through all the given arguments, as input files
while(argv[i] != NULL) {
    //Open and test the file opened correctly
    file = fopen(argv[i], "r");
    //printf("Filename %s\n",argv[i]);
    if (file == NULL){
        fprintf(stderr, "my-grep: cannot open file\n");
        exit(1);
    }
    //set the pattern
    strcpy(pattern,argv[1]);
    while(!feof(file)) {
        //printf("rullataan\n");
        fgets(string1,1000,file);
        if(strstr(string1,pattern))
            printf("%s",string1);
    }
    
    //close file and get next argument in loop
    fclose(file);
    i++;
}

}