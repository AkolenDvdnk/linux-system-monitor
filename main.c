#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 8

int *reader(){
    int *arr = (int*)malloc(MAX_LEN * sizeof(int));

    FILE* fp;

    if ((fp = fopen("/proc/stat", "r")) == NULL){
        printf("File cannot be opened!\n");
        exit(1);
    }

    fscanf(fp, "%*s %d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7]);

    fclose(fp);

    return arr;
}



int main(){
    int *data = NULL;

    data = reader();

    for (int i = 0; i < MAX_LEN; i++){
        printf("%d ", data[i]);
    }
    printf("\n");

    free(data);

    return 0;
}