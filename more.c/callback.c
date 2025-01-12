#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

double add(double a, double b){
    return a+b;
}

double sub(double a, double b){
    return a-b;
}

double mult(double a, double b){
    return a*b;
}

double divd(double a, double b){
   if(b == 0){
        puts("Div by 0 err!");
        exit(-1);
    }
    return a/b;
}

double mod(double a, double b){
    return a;
}

double pwd(double a, double b){
    if(b == 0)
        return 1.0;
    double sum = a;
    for(int i = 1; i < b; ++i){
        sum *= a;
    }
    return sum;
}

double calc(double, double, double (*opFunction)(double, double));

int main(int argc, char* argv[]){

    double (*operation)(double, double);
    char* ch;
    double sum = strtod(argv[1], &ch);
    operation = add;

    for (int i = 2; i < argc; ++i){
    if(!(isdigit(*argv[i]))){
    switch(*argv[i]){
        case '+':
            operation = add;
            break;
        case '-':
            operation = sub;
            break;
        case '/':
            operation = divd;
            break;
        case 'x':
            operation = mult;
            break;
        case '^':
            operation = pwd;
            break;
        case '%':
            operation = mod;
            break;
        default:
            printf("Unknown Operator: \"%c\"\n", *argv[i]);
            return 1;
        }
    } else {
       sum = calc(sum, strtod(argv[i], &ch), operation);

    }
    }
    printf("Result: %.2f\n", sum);

    return 0;
}

double calc(double a, double b, double (*opFunction)(double, double)){
    return opFunction(a,b);
}
