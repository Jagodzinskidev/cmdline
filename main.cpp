#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void usage(char *program_name) {
    printf("Sposob uzycia: %s <liczba> <dzialanie> <powtorzenia>\n", program_name);
    exit(1);
}

void log_line(const char *content) {
    FILE *logFile = fopen("log.txt", "a");
    if (logFile == NULL) {
        perror("Nie mozna otworzyc pliku log.txt");
        return;
    }

    time_t now = time(NULL);
    char *timeStr = ctime(&now);
    timeStr[strcspn(timeStr, "\n")] = '\0';

    fprintf(logFile, "[%s] %s\n", timeStr, content);
    fclose(logFile);
}

void log_command(int argc, char *argv[]) {
    char command[512] = {};
    for (int i = 0; i < argc; i++) {
        strcat(command, argv[i]);
        strcat(command, " ");
    }
    log_line(command);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        usage(argv[0]);
    }

    log_command(argc, argv);  // Log full command

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
