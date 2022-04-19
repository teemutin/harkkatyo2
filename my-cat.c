#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 50

int main(int argc, char **argv){
  int   file;
  char  buffer[BUFFER_SIZE];
  int   read_size;
  int   i=1;

//Test there is an input
if (argc < 2){
    fprintf(stderr, "Error: usage: ./cat filename\n");
    return (-1);
    }
//Loop through all the given arguments, as input files
while(argv[i] != NULL) {
    //Open and test the file opened correctly
    file = open(argv[i], O_RDONLY);
    if (file == -1){
        fprintf(stderr, "Error: %s: file not found\n", argv[1]);
        return (-1);
        }
    while ((read_size = read(file, buffer, BUFFER_SIZE)) > 0)
        write(1, &buffer, read_size);

    close(file);
    i++;
    
}

}