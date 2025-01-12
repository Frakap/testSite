#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        puts("Invalid number of arguments");
        return 1;
    }
    FILE* inFile = fopen(argv[1], "r");
    if(inFile == NULL){
        perror("File could not be opened");
        return 1;
    }
    char line[1000];
    char copy[1000];
    char* token;
    int words = 0;
    int lines = 0;
    
    while((fgets(line, sizeof(line), inFile)) != NULL){
    	int len = strlen(line);
    	line[len -3] = '\0';
        ++lines;
                
        strncpy(copy,line, sizeof(line) -1);
        token = strtok(copy, " ");
        while(token != NULL){
            ++words;
            token = strtok(NULL, " ");
        }
    }

    fclose(inFile);

    printf("Number of words: %d\nNumber of lines: %d\n", words, lines);
    puts("Program ran succesfully\n");
    
    return 0;    
}
