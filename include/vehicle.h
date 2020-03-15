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
// return size of struct vehicle
int vehicle_size();

// initialize struct's object with data
bool init_vehicle(struct vehicle** object, char* name_model, char* car_type, int speed, int fuel_flow, int power);

// free object's memory
void clean_vehicle(struct vehicle* object);

// print object's data
void print_vehicle(struct vehicle* object);

// find object with pattern's data and save index in result_indexes
int find_vehicle(struct vehicle* pattern, struct vehicle** input_objects, int size, int** result_indexes);

// compare function of two vehicle's object
bool equal(struct vehicle* object, struct vehicle* other_object);

// free array's memory
void clear_array(struct vehicle** array, int size);

#endif //DZ1_VEHICLE_H
