#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char *program_name) {
    printf("Sposob uzycia: %s <liczba> <dzialanie> <powtorzenia>\n", program_name);
    exit(1);
}
int main(int argc, char *argv[]) {
    int i, firstNumber, secondNumber;

    if (argc < 4)
        usage(argv[0]);
    firstNumber = atoi(argv[1]);
    secondNumber = atoi(argv[3]);
    char *choice = argv[2];

    if (strcmp(choice, "add") == 0) {
        printf("%d + %d = %d", firstNumber, secondNumber, firstNumber+secondNumber);
    }
}