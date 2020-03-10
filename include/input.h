#ifndef DZ1_INPUT_H
#define DZ1_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN_BUF 32

char input_char();

char* input_string(char*, int);

int input_int(char*);

#endif //DZ1_INPUT_H
