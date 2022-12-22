#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINES 9
#define MAX_LEN 100

char **reader(){
    char **arr = (char**)malloc(sizeof(char*) * MAX_LINES);
    for (int i = 0; i < MAX_LINES; i++){
        arr[i] = (char*)malloc(MAX_LEN);
    }

    FILE* fp;

    if ((fp = fopen("/proc/stat", "r")) == NULL){
        printf("File cannot be opened!\n");
        exit(1);
    }

    int line = 0;
    while (!feof(fp) && !ferror(fp) && line < MAX_LINES){
        if (fgets(arr[line], MAX_LEN, fp) != NULL){
            line++;
        }
    }
    fclose(fp);

    return arr;
}

int main(){
    char **data = NULL;
    
    data = reader();

    for (int i = 0; i < MAX_LINES; i++){
        printf("%s", data[i]);
    }

    return 0;
}