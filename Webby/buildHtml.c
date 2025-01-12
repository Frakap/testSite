#include "main.h"

void buildHtml(char* title, char* header, int count, char body[][2048]){
    puts("<!DOCTYPE html>");

    puts("<html>");
    puts("<head>");
    puts("<style>");
    puts("body {background-color: powderblue;}");
    puts("h1 {color: red;}");
    printf("<title> %s </title>\n", title);
    puts("</head>");
    puts("</style>");

    puts("<body>");
    printf("<h1> %s</h1>\n", header);
    for(int i = 0; i < count; ++i ){
        printf("<p style=\"color: blue\";> %s </p>\n", body[i]);
    }
    puts("</body>");
    puts("</html>");

}