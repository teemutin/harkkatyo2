#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv){
    FILE *file;
    char  buffer;
    int   i=1;

//Test there is an input
if (argc < 2){
    return (0);
    }
//Loop through all the given arguments, as input files
while(argv[i] != NULL) {
    //Open and test the file opened correctly
    file = fopen(argv[i], "r");
    if (file == NULL){
        fprintf(stderr, "my-cat: cannot open file\n");
        exit(1);
    }
    //Go through the file till end of file is reached, and print
    while((buffer=fgetc(file))!=EOF) {
        printf("%c",buffer);
    }
    
    //close file and get next argument in loop
    fclose(file);
    i++;
    
}
exit(0);

}