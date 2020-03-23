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

enum {
    NAME_MODEL = 1,
    CAR_TYPE,
    SPEED,
    FUEL_FLOW,
    ENGINE_POWER,
    FINALLY
};

// return size of struct vehicle
int vehicle_size();

//input data about vehicles
int input_vehicles(struct vehicle** array, int size);

// initialize struct's object with data
bool init_vehicle(struct vehicle** object, char* name_model, char* car_type, int speed, int fuel_flow, int power);

// free object's memory
void clean_vehicle(struct vehicle* object);

// print object's data
void print_vehicle(const struct vehicle* object);

// find object with pattern's data and save index in result_indexes
int find_vehicle(const struct vehicle* pattern, struct vehicle** input_objects, int size, int** result_indexes);

// compare function of two vehicle's object
bool equal(const struct vehicle* object,const struct vehicle* other_object);

// free array's memory
void clear_array(struct vehicle** array, int size);

// input data to next vehicle's searching
int input_criteria_search();

// print criteria's types to user
void print_criteria();

#endif //DZ1_VEHICLE_H
