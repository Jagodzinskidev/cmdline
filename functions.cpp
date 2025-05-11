//
// Created by Seweryn on 12.05.2025.
//

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