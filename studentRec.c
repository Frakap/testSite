#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record{
    int ID;
    char name[99];
    double gpa;
} Record;
void initFile(FILE*, int);
void addRecord(FILE*);
void deleteRecord(FILE*);
void retrieveRecords(FILE*);

int main(int argc, char* argv[]){
    
    FILE* studentRecords = fopen(argv[1], "wb+");
    if(studentRecords == NULL){
        perror("Unable to open file");
        return 1;
    }

    int num;
    printf("%s", "Enter number of students\n? ");
    scanf("%d", &num);

    int options;
    initFile(studentRecords, num);
    while(options != -1){
        puts("MENU: (ENTER CHOICE NUMBER)\n");
        puts("EXIT  (-1)");
        puts("ADD RECORD: (0)");
        puts("REMOVE RECORDS: (1)");
        puts("RETRIEVE RECORDS (2)");
        printf("%s","\nENTER CHOICE:\n? ");

        while(scanf("%d", &options) != 1 || options < -1 || options > 2){
            printf("%s","Invalid input, Try again\n? ");
            while(getchar() != '\n');
        }

        switch(options){
            case(-1):
                puts("Exiting Menu.\nGoodBye!");
                break;
            case(0):
                puts("Adding New record.");
                addRecord(studentRecords);
                break;
            case(1):
                puts("Deleting Record.");
                deleteRecord(studentRecords);
                break;
            case(2):
                puts("Displaying Student Records: ");
                retrieveRecords(studentRecords);
                break;
            default:
                puts("Invalid choice:");
                break;
        }
    }

}

void initFile(FILE* dataFile, int size){
    int numOfStuds = size;
    Record blankRecord = {0, "" , 0.0};

    for(int i = 1; i <= numOfStuds; ++i){
        fwrite(&blankRecord, sizeof(Record), 1, dataFile);
    }
    rewind(dataFile);
}

void addRecord(FILE* dataFile){
    
    Record holdRecord;
    char string[100];
    printf("%s", "Enter student info (ID,Name,GPA) seperated by commas:\n? ");
    while (getchar() != '\n');
    fgets(string, sizeof(string), stdin);

    if(string != NULL){

    char* token =  strtok(string, ",");
    holdRecord.ID = atoi(token);

    char* token2 = strtok(NULL, ",");
    strncpy(holdRecord.name, token2, sizeof(holdRecord.name)-1);

    char* token3 = strtok(NULL, ",");
    holdRecord.gpa = atof(token3);

    fseek(dataFile, holdRecord.ID*sizeof(Record), SEEK_SET);
    fwrite(&holdRecord, sizeof(Record), 1, dataFile);
    rewind( dataFile);
    }
}

void deleteRecord(FILE* dataFile){
    Record blankRecord = {0, "", 0.0};
    int id;
    printf("%s", "Enter the ID of the student to delete");
    scanf("%d", &id);
    while(getchar() != '\n');

    fseek(dataFile, id*sizeof(Record), SEEK_SET);
    fwrite(&blankRecord, sizeof(Record), 1, dataFile);
}

void retrieveRecords(FILE* dataFile){
    Record blankRecord;
    int num;
    printf("%s", "Number of students:\n?");
    scanf("%d", &num);
    while(getchar() != '\n');
    puts("\nList of Students: ");
    for(int i = 1; i <= num; ++i){
        fread(&blankRecord, sizeof(Record), 1, dataFile);
        if(blankRecord.ID != 0){
            printf("Student ID: %d\nStudent Name: %s\nStudent GPA: %.2f\n", blankRecord.ID, blankRecord.name, blankRecord.gpa);
            puts("_____________________________________");
        }

    }
    rewind(dataFile);

}