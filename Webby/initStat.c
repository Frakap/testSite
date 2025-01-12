#include "main.h"

void initStat(FILE** pageFile, char** header, char** title, int argc, char* argv[]){

        char ch;
        while ((ch = getopt(argc, argv, "t:h:c:")) != EOF)
        {
        switch (ch)
        {
        case 't':
            *title = optarg;
            break;
        case 'h':
            *header = optarg;
            break;
        case 'c':
            *pageFile = fopen(optarg, "r");
            if (*pageFile == NULL)
            {
                perror("Unable to open file!\n");
                exit(-1);
            }
            break;
        default:
            fprintf(stderr, "Unknown flag: %c\n", ch);
        }
    }
    argc -= optind;
    argv += optind;

}