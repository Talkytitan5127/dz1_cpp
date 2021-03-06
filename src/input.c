#include "input.h"


char input_char() {
    char c = '\0';
    int result = 0;
    do {
        result = scanf("%c", &c);
    } while (result != 1);
    return c;
}

char* input_string(int length) {
    char *string = (char *)malloc((length + 1) * sizeof(char));
    if (!string) {
        return false;
    }
    size_t index = 0;
    char c = '\0';
    c = input_char();
    while (c != '\n' && c != EOF) {
        if (index >= length) {
            printf("Длина слова должна быть меньше %d\n", length);
            free(string);
            return false;
        }
        string[index] = c;
        index++;
        c = input_char();
    }
    string[index] = '\0';
    return string;
}


int input_int() {
    char c = '\0';
    int result = 0;
    c = input_char();
    while (c != EOF && c != '\n') {
        if (!(c >= '0' && c <= '9')) {
            char *buf = input_string(LEN_BUF);
            if (buf) {
                free(buf);
            }
            return EXIT_SUCCESS;
        }
        result = result * 10 + c - '0';
        c = input_char();
    }
    return result;
}