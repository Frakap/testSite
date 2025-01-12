// build webpage that has the following content
// Title: hello world
// Content: This is my personal webpage

#include "main.h"

#define MAX_PARAGRAPH 2048
#define MAX_PARAGRAPH_NUM 50

int main(int argc, char *argv[]){

    if(argc < 6){
        perror("Invalid Argument Count");
        perror("Expected: ./launch -t title -h header -c inputFile");
        exit(-1);
    }

    char *title;
    char *header;
    perror("Status");
    FILE *pageFile;

    char buffer[MAX_PARAGRAPH];
    int count = 1;

    initStat(&pageFile, &header, &title, argc, argv);

    while(fgets(buffer, sizeof(buffer), pageFile) != NULL){
        if(buffer[0] == '\n'){
            ++count;
        }
    }
    rewind(pageFile);
    
    char body[MAX_PARAGRAPH_NUM][MAX_PARAGRAPH] = {{'\0'}};

    int i = 0;
    int max = sizeof(body) / sizeof(body[0]);
    while (i < count && (fgets(buffer, sizeof(buffer), pageFile) != NULL))
    {
        if ((buffer[0]) == '\n')
        {
            ++i;
            continue;
        }
        if (strlen(buffer) + strlen(body[i]) < MAX_PARAGRAPH)
            strncat(body[i], buffer, MAX_PARAGRAPH - strlen(buffer) - 1);
    }

    buildHtml(title, header, count, body);
    return 0;
}