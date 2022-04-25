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

char* encode(char* src) {
    //FILE *file2;
    int rLen;
    char count[MAX_RLEN];
    char character1[100];
    int len = strlen(src);
    //file2 = fopen("testifilu.bin", "wb");
 
    /* If all characters in the source string are different,
    then size of destination string would be twice of input string.
    For example if the src is "abcd", then dest would be "a1b1c1d1"
    For other inputs, size would be less than twice.  */
    char* dest = (char*)malloc(sizeof(char) * (len * 2 + 1));
 
    int i, j = 0, k;
 
    /* traverse the input string one by one */
    for (i = 0; i < len; i++) {
 
        /* Copy the first occurrence of the new character */
        dest[j++] = src[i];

        //printf("Kirjain on %c\n",src[i]);
 
        /* Count the number of occurrences of the new character */
        rLen = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            rLen++;
            i++;
        }
        //printf("Kirjaimen määrä on %d\n",rLen);
 
        /* Store rLen in a character array count[] */
        //printf("Eli koko kombinaatio on %d%c\n",rLen,src[i]);
        //sprintf(character1,"%c",src[i]);
        //printf("Ja stringi on %d\n",character1);
        DataStruct ds;
        //strcpy(ds.a,src[i]);
        //strcpy(ds.a,&src);
        //printf("%d",rLen);
        ds.a = character1;
        ds.b = rLen;
        //strncpy(ds.a,src[i],100);
        //ds.a = "B";
        //ds.b = rLen;
        fwrite(&ds, sizeof(DataStruct), 1, stdout);
        //size_t element_size = sizeof src;
        //size_t elements_to_write = sizeof src;


        //fwrite(src,element_size,elements_to_write,stdout);
        //printf("kombinaatio on %d %c\n",ds.b,ds.a);
        //fwrite(&src[i], sizeof(src[i]), 1, stdout);
        //fprintf(stdout, "%c", src[i]);

        //sprintf(count, "%d", rLen);

    }
 
    /*free destination*/
    dest[j] = '\0';
    return dest;
}


int main(int argc, char **argv){
    FILE *file;
    int   len;
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
            char* thinhy = encode(string1);
            printf("%s",thinhy);

        }


        fclose(file);
        i++;
    }
    exit(0);


}