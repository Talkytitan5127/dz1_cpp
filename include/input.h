#ifndef DZ1_INPUT_H
#define DZ1_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN_BUF 32
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

char input_char();

char* input_string(int length);

int input_int();

#endif //DZ1_INPUT_H
