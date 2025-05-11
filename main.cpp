#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        usage(argv[0]);
    }

    log_command(argc, argv);

    int firstNumber = atoi(argv[1]);
    int secondNumber = atoi(argv[3]);
    char choice = argv[2][0];
    char result[256];

    const char *info = "Dostepne dzialania: add, sub, mul, div";
    printf("%s\n", info);
    log_line(info);

    switch (choice) {
        case 'a':
            sprintf(result, "%d + %d = %d", firstNumber, secondNumber, firstNumber + secondNumber);
            break;
        case 's':
            sprintf(result, "%d - %d = %d", firstNumber, secondNumber, firstNumber - secondNumber);
            break;
        case 'm':
            sprintf(result, "%d * %d = %d", firstNumber, secondNumber, firstNumber * secondNumber);
            break;
        case 'd':
            if (secondNumber == 0) {
                strcpy(result, "Nie mozna dzielic przez 0");
            } else {
                sprintf(result, "%d / %d = %.2f", firstNumber, secondNumber, (double)firstNumber / (double)secondNumber);
            }
            break;
        default:
            strcpy(result, "Nie rozpoznano dzialania");
    }

    printf("%s\n", result);
    log_line(result);

    return 0;
}
