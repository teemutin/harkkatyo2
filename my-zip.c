#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RLEN 1000

struct DataStruct {
    char *a;
    int b;
};
typedef struct {
    char *a;
    int b;
} DataStruct;

//Go through the given string, and find occurances of characters and their number and store it to datastruct and 
//fwrite it to a file to zip
char* encode(char* src) {
    int StrLen;
    char count[MAX_RLEN];
    char character1[100];
    int len = strlen(src);
 
    char* result = (char*)malloc(sizeof(char) * (len * 2 + 1));
 
    int i, j = 0, k;
 
    /* move in iput one by one*/
    for (i = 0; i < len; i++) {
 
        /* Copy the character */
        result[j++] = src[i];
 
        /* Count the number of occurrences of the new character */
        StrLen = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            StrLen++;
            i++;
        }
        sprintf(character1,"%c",src[i]);
        DataStruct ds;
        ds.a = character1;
        ds.b = StrLen;
        fwrite(&ds, sizeof(DataStruct), 1, stdout);

 
        /* Copy the count[] to resultination */
        for (k = 0; *(count + k); k++, j++) {
            result[j] = count[k];
        }
    }
 
    /*free resultination*/
    result[j] = '\0';
    return result;
}


int main(int argc, char **argv){
    FILE *file;
    int i=1;
    char string1[2000];
    //Test there is an input
    if (argc < 2){
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
    }
    while(argv[i] != NULL) {
        file = fopen(argv[i], "r");
        if (file == NULL){
            fprintf(stderr, "my-zip: cannot open file\n");
            exit(1);
        }
        //printf("Fileopened filename %s",argv[i]);
        while(!feof(file)) {
            fgets(string1,2000,file);
            encode(string1);

        }


        fclose(file);
        i++;
    }
    exit(0);


}