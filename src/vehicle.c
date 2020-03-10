#include "../include/vehicle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int vehicle_size() {
    return sizeof(struct vehicle);
}

void clean_vehicle(struct vehicle *obj) {
    if (obj->name_model) {
        free(obj->name_model);
    }

    if (obj->car_type) {
        free(obj->car_type);
    }
    free(obj);
}

bool init_vehicle(struct vehicle **obj, char* name_model, char* car_type, int speed, int fuel_flow, int power) {
    struct vehicle* point = malloc(vehicle_size());

    point->name_model = name_model;
    point->car_type = car_type;
    point->speed = speed;
    point->engine_power = power;
    point->fuel_flow = fuel_flow;
    *obj = point;
    return true;
}

bool equal(struct vehicle *search, struct vehicle *obj) {
    if(search->name_model && strcmp(search->name_model, obj->name_model) != 0) {
        return false;
    }
    if (search->car_type && strcmp(search->car_type, obj->car_type) != 0) {
        return false;
    }
    if (search->engine_power && (abs(search->engine_power - obj->engine_power) > EPS)) {
        return false;
    }
    if (search->speed && (abs(search->speed - obj->speed) > EPS)) {
        return false;
    }
    if (search->fuel_flow && (abs(search->fuel_flow - obj->fuel_flow) > EPS)) {
        return false;
    }
    return true;
}

int find_vehicle(struct vehicle *search, struct vehicle **array, int count, int** result) {
    int *p = *result;
    int res_count = 0;
    for (int index = 0; index < count; index++) {
        if (equal(search, array[index])) {
            if (p != NULL) {
                p[res_count] = index;
            }
            res_count++;
        }
    }
    return res_count;
}

void print_vehicle(struct vehicle* obj) {
    printf("Машина марки %s\n", obj->name_model);
    printf("Характеристики\n");
    printf("* Мощность двигателя: %d\n", obj->engine_power);
    printf("* Тип кузова: %s\n", obj->car_type);
    printf("* Расход топлива: %d\n", obj->fuel_flow);
    printf("* Скорость автомобиля: %d\n", obj->speed);
}

void clear_array(struct vehicle** array, int length) {
    for (int index = 0; index < length; index++) {
        if (array[index]) {
            clean_vehicle(array[index]);
        }
    }
    free(array);
}
