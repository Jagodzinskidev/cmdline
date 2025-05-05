#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char *program_name) {
    printf("Sposob uzycia: %s <liczba> <dzialanie> <powtorzenia>\n", program_name);
    exit(1);
}
int main(int argc, char *argv[]) {
    int i, firstNumber, secondNumber;
    firstNumber = atoi(argv[1]);
    secondNumber = atoi(argv[3]);
    char *choice = argv[2];

    if (argc < 4)
        usage(argv[0]);

    if (strcmp(choice, "add") == 0) {
        printf("%d + %d = %d", firstNumber, secondNumber, firstNumber+secondNumber);
    }
    else if (strcmp(choice, "sub") == 0) {
        printf("%d - %d = %d", firstNumber, secondNumber, firstNumber-secondNumber);
    }
    else if (strcmp(choice, "mul") == 0) {
        printf("%d * %d = %d", firstNumber, secondNumber, firstNumber*secondNumber);
    }
    else if (strcmp(choice, "div") == 0) {
        if (secondNumber == 0) {
            printf("Nie mozna dzielic przez 0");
        } else {
            printf("%d / %d = %f", firstNumber, secondNumber, (double)firstNumber/(double)secondNumber);
        }
    }
}