#include <stdio.h>
#include <stdlib.h>



struct rectangle {
    int width;
    int length;

    int (*area)(struct rectangle*);
    int (*perimeter)(struct rectangle*);
};

int area(struct rectangle* rect){
    return (*rect).width*(*rect).length;
}

int perimeter(struct rectangle* rect){
    return (2)*(rect->width + rect->length);
}

int main(int argc, char* argv[]){

    if(argc != 3){
        puts("Invalid Arg Count!");
        return 1;
    }

   struct rectangle myRect = {4,3, NULL, NULL};
   myRect.area = area;
   myRect.perimeter = perimeter;

   struct rectangle newRect;
   newRect.width = atoi(argv[1]);
   newRect.length = atoi(argv[2]);

   newRect.area = area;
   newRect.perimeter = perimeter;

   printf("Area: %d in^2\nPerimeter: %d in^2\n", myRect.area(&myRect), myRect.perimeter(&myRect));
   printf("Your rectangles Area: %d in^2\nPerimeter: %d in^2\n", newRect.area(&newRect), newRect.area(&newRect));

   return 0;
}