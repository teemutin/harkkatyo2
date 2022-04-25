#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RLEN 2000
struct DataStruct {
    char a;
    int b;
};
typedef struct {
    char a;
    int b;
} DataStruct;

int main(int argc, char **argv){
    FILE *file;
    int i=1;
    //Test there is an input
    if (argc < 2){
        printf("my-unzip: file1 [file2 ...]\n");
        exit(1);
    }
        file = fopen(argv[i], "rb");
        if (file == NULL){
            fprintf(stderr, "my-unzip: cannot open file\n");
            exit(1);
        }

        DataStruct ds;
        for(int j=0;j<14;j++){
            fread(&ds, sizeof(DataStruct), 1, file);
            printf("Nmbr %d Char %c\n", ds.b, ds.a);
        }

        fclose(file);
    exit(0);


}