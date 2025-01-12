#include <stdio.h>
#include <stdlib.h>

struct fish {
    const char* name;
    const char* species;
    int teeth;
    int age; 
};

struct foods{
    const char* name;
    int quantity;
    const char* doneness;
};

struct human {
    const char* frstName;
    const char* lstName;
    int age;
    struct human* parent;
    struct fish* pet;
    struct foods meat;
};

struct arr{
    int arr[10];
};

void main(int argc, char* argv){

    struct human myParent;
    struct human* sacrePtr = &myParent;
    struct fish myFish = {"gogol", "fish", 34, 2};
    struct fish* gogolPtr = &myFish;
    struct human myHuman = {"love", "Kapesa", 12, sacrePtr, gogolPtr, NULL};

    struct arr myArray = {{1,2,3,4,5}};
    (*sacrePtr).meat.name = "steak";
    (*sacrePtr).meat.quantity = 12;
    (*sacrePtr).meat.doneness = "mediume-rare";


    printf("Struct: %-20ld\n", (long int)(&myFish));
    printf("name: %-20ld\nSpecies: %-20ld\nteeth: %-20ld\nage: %-20ld\n", (long int)(&myFish.name), (long int)(&myFish.species), (long int)(&myFish.teeth), (long int)(&myFish.age));
    //printf("Pet name: %s\n", (myHuman.pet)->species);
    //printf("Pet name: %s\n", (*(myHuman.pet)).name);

    char* string = ((char*)(*(gogolPtr)));
    printf("String: %s\n", string);

    //printf("Meat: %s\nQuantity: %d\nDoneness: %s\n", (*sacrePtr).meat.name, (*sacrePtr).meat.quantity, (*sacrePtr).meat.doneness);

}