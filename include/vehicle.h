#ifndef DZ1_VEHICLE_H
#define DZ1_VEHICLE_H

#include "input.h"

#include <stddef.h>
#include <stdbool.h>

#define LEN_BUF 32
#define EPS 2


struct vehicle
{
    int engine_power;
    int speed;
    int fuel_flow;
    char *name_model;
    char *car_type;
};

int vehicle_size();

bool init_vehicle(struct vehicle**);

void clean_vehicle(struct vehicle*);

void print_vehicle(struct vehicle*);

int find_vehicle(struct vehicle*, struct vehicle**, int, int**);

bool compare(struct vehicle*, struct vehicle*);

#endif //DZ1_VEHICLE_H
