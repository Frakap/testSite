#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct record{
    int ID;
    char name[99];
}Record;

int main(int argc, char* argv[]){

    if(argc != 2){
        perror("Invalid argument count");
        exit(-1);
    }

    FILE* outFile = fopen(argv[1], "wb+");
    if(outFile == NULL){
        perror("unable to open file");
        exit(-1);
    }

    Record myRecord = {11512423, "Fracas"};

    Record holdRecord = {0, ""};

    fwrite(&myRecord, sizeof(Record), 1, outFile);
    rewind(outFile);
    fread(&holdRecord, sizeof(Record), 1, outFile);
    printf("ID: #%d\nName: %s\n", holdRecord.ID, holdRecord.name);

    return 0;
}