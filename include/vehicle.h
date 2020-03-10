#ifndef DZ1_VEHICLE_H
#define DZ1_VEHICLE_H

#include "input.h"

#include <stddef.h>
#include <stdbool.h>

#define LEN_BUF 32
#define EPS 2
#define INPUT_ERROR "Введены неправильные данные"


struct vehicle
{
    int engine_power;
    int speed;
    int fuel_flow;
    char *name_model;
    char *car_type;
};

int vehicle_size();

bool init_vehicle(struct vehicle**, char*, char*, int, int, int);

void clean_vehicle(struct vehicle*);

void print_vehicle(struct vehicle*);

int find_vehicle(struct vehicle*, struct vehicle**, int, int**);

bool equal(struct vehicle*, struct vehicle*);

void clear_array(struct vehicle**, int);

#endif //DZ1_VEHICLE_H
