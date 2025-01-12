#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    char* delivery = "";
    int thick = 0;
    int count = 0;
    char ch;

    while( (ch = getopt(argc, argv, "d:t:")) != EOF){
        switch(ch){
            case 'd':
                delivery = optarg;
                break;
            case 't':
                thick  = atoi(optarg);
                break;
            default:
                fprintf( stderr, "Invalid arguments: %s\n", optarg);
                return 1;
                break;
        }
    }

        argc -= optind;
        argv += optind;

    if(thick){
        puts("Thick Crust");
    }
    if (delivery[0])
        printf("To be delivered to: %s\n", delivery);
    puts("Engredients:");

    for(count; count < argc; ++count){
            puts(argv[count]);
        }
        return 0;


    while(ch = getopt(argc, argv, "ae:") != -1)

}