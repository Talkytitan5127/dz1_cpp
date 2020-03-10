#include "../include/input.h"


char input_char() {
    char c = '\0';
    int result = 0;
    do {
        result = scanf("%c", &c);
    } while (result != 1);
    return c;
}

char* input_string(char* message, int length) {
    if (message != NULL) {
        printf("%s\n", message);
    }
    char *string = (char *)malloc((length + 1) * sizeof(char));
    size_t index = 0;
    char c = '\0';
    while (c = input_char(), c != '\n' && c != EOF) {
        if (index >= length) {
            printf("Длина слова должна быть меньше %d\n", length);
            free(string);
            return false;
        }
        string[index] = c;
        index++;
    }
    string[index] = '\0';
    return string;
}


int input_int(char* message) {
    printf("%s\n", message);
    char c = '\0';
    int result = 0;
    c = input_char();
    while (c != EOF && c != '\n') {
        if (!(c >= '0' && c <= '9')) {
            char *buf = input_string(NULL, LEN_BUF);
            if (buf) {
                free(buf);
            }
            return 0;
        }
        result = result * 10 + c - '0';
        c = input_char();
    }
    return result;
}