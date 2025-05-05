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
    char choice = argv[2][0];

    if (argc < 4) {
        usage(argv[0]);
    } else {
        printf("Dostepne dzialania: add, sub, mul, div \n");
    }

    switch (choice) {
        case 'a':
            printf("%d + %d = %d", firstNumber, secondNumber, firstNumber+secondNumber);
            break;
        case 's':
            printf("%d - %d = %d", firstNumber, secondNumber, firstNumber-secondNumber);
            break;
        case 'm':
            printf("%d * %d = %d", firstNumber, secondNumber, firstNumber*secondNumber);
            break;
        case 'd':
            if (secondNumber == 0) {
                printf("Nie mozna dzielic przez 0");
            } else {
                printf("%d / %d = %.2f", firstNumber, secondNumber, (double)firstNumber/(double)secondNumber);
            }
            break;
        default:
            printf("Nie rozpoznano dzialania");
    }
}