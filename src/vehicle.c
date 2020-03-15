#include "vehicle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int vehicle_size() {
    return sizeof(struct vehicle);
}

void clean_vehicle(struct vehicle *obj) {
    if (obj) {
        free(obj);
    }
}

bool init_vehicle(struct vehicle **obj, char* name_model, char* car_type, int speed, int fuel_flow, int power) {
    struct vehicle* point = malloc(vehicle_size());
    if (!point) {
        return false;
    }

    point->name_model = name_model;
    point->car_type = car_type;
    point->speed = speed;
    point->engine_power = power;
    point->fuel_flow = fuel_flow;
    *obj = point;
    return true;
}

bool equal(const struct vehicle *search,const struct vehicle *obj) {
    if (!search) {
        return false;
    }

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

int find_vehicle(const struct vehicle *search, struct vehicle **array, int count, int** result) {
    int *p = *result;
    int res_count = 0;
    for (int index = 0; index < count; index++) {
        if (equal(search, array[index])) {
            p[res_count] = index;
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

int input_vehicles(struct vehicle** array, int size) {
    for (int index = 0; index < size; index++) {
        printf("Введите марку машины\n");
        char* name_model = input_string(LEN_BUF);
        if (!name_model) {
            return EXIT_FAILURE;
        }
        printf("Введите тип кузова\n");
        char* car_type = input_string(LEN_BUF);
        if (!car_type) {
            return EXIT_FAILURE;
        }
        printf("Введите скорость машины\n");
        int speed = input_int();
        if  (!speed) {
            return EXIT_FAILURE;
        }
        printf("Введите расход топлива\n");
        int fuel_flow = input_int();
        if (!fuel_flow) {
            return EXIT_FAILURE;
        }
        printf("Введите мощность двигателя\n");
        int power = input_int();
        if (!power) {
            return EXIT_FAILURE;
        }

        bool error = init_vehicle(
                &array[index],
                name_model,
                car_type,
                speed,
                fuel_flow,
                power);
        if (!error) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int input_criteria_search(struct vehicle** search) {
    struct vehicle* search_obj = *search;

    int number;
    char* string = NULL;

    while (1) {
        print_criteria();
        printf("Введите цифру:\n");
        int switcher = input_int();
        switch (switcher) {
            case NAME_MODEL:
                printf("Введите марку:\n");
                string = input_string(LEN_BUF);
                if (!string) {
                    printf("Неверно введена марка");
                    break;
                }
                search_obj->name_model = string;
                break;
            case CAR_TYPE:
                printf("Введите тип кузова:\n");
                string = input_string(LEN_BUF);
                if (!string) {
                    printf("Неверно введен тип");
                    break;
                }
                search_obj->car_type = string;
                break;
            case SPEED:
                printf("Введите скорость:\n");
                number = input_int();
                if (!number) {
                    printf("Неверно введена скорость");
                    break;
                }
                search_obj->speed = number;
                break;
            case FUEL_FLOW:
                printf("Введите расход топлива\n");
                number = input_int();
                if (!number) {
                    printf("Неверно введен расход");
                    break;
                }
                search_obj->fuel_flow = number;
                break;
            case ENGINE_POWER:
                printf("Введите мощность двигателя\n");
                number = input_int();
                if (!number) {
                    printf("Неверно введена мощность");
                    break;
                }
                search_obj->engine_power = number;
                break;
            case FINALLY:
                return EXIT_SUCCESS;
            default:
                printf("Попробуй еще раз\n");
                break;
        }
    }
}

void print_criteria() {
    printf("Выберите критерий поиска:\n");
    printf("1 - название марки\n");
    printf("2 - тип кузова\n");
    printf("3 - величина скорости\n");
    printf("4 - расход топлива\n");
    printf("5 - мощность двигателя\n");
    printf("6 - найти по заданным критериям\n");
}
