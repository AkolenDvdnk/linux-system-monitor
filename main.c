#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINES 9
#define MAX_LEN 100

char **reader(){
    char **arr = (char**)malloc(sizeof(char*));
    for (int i = 0; i < MAX_LINES; i++){
        arr[i] = (char*)malloc(MAX_LEN);
    }
}

int main(){


    return 0;
}