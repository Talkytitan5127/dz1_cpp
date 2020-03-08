#include "../include/vehicle.h"
#include <stdio.h>
#include <stdlib.h>

void clear_array(struct vehicle**, int);
void print_criteria();

int main(int argc, char** argv) {
    printf("Введите количество автомобилей\n");
    int count = input_int();
    printf("%d\n", count);

    struct vehicle** array;
    array = malloc(count * vehicle_size());

    for (int index = 0; index < count; index++) {
        bool error = init_vehicle(&array[index]);
        if (!error) {
            clear_array(array, count);
            return 1;
        }
    }

    for (int index = 0; index < count; index++) {
        print_vehicle(array[index]);
    }

    int switcher = 0;
    char *string = NULL;
    int number;
    struct vehicle* search_obj = malloc(vehicle_size());

    int *result = (int*)malloc(count*sizeof(int));
    int success = 0;

    while (switcher != 6) {
        print_criteria();
        printf("Введите цифру: \n");
        switcher = input_int();
        switch (switcher) {
            case 1:
                printf("Введите марку\n");
                string = input_string(LEN_BUF);
                if (!string) {
                    printf("Неверно введена марка");
                    break;
                }
                search_obj->name_model = string;
                break;
            case 2:
                printf("Введите тип кузова:\n");
                string = input_string(LEN_BUF);
                if (!string) {
                    printf("Неверно введен тип");
                    break;
                }
                search_obj->car_type = string;
                break;
            case 3:
                printf("Введите скорость\n");
                number = input_int();
                if (!number) {
                    printf("Неверно введена скорость");
                    break;
                }
                search_obj->speed = number;
                break;
            case 4:
                printf("Введите расход топлива\n");
                number = input_int();
                if (!number) {
                    printf("Неверно введен расход");
                    break;
                }
                search_obj->fuel_flow = number;
                break;
            case 5:
                printf("Введите мощность двигателя\n");
                number = input_int();
                if (!number) {
                    printf("Неверно введена мощность");
                    break;
                }
                search_obj->engine_power = number;
                break;
            case 6:
                success = find_vehicle(search_obj, array, count, &result);
                break;
            default:
                printf("Попробуй еще раз\n");
                break;
        }
    }

    printf("Итоги поиска:\n");
    if (!success) {
        printf("Нет подходящего авто\n");
    } else {
        for (int index = 0; index < success; index++) {
            print_vehicle(array[index]);
        }
    }

    clear_array(array, count);
    free(result);
    return 0;
}

void clear_array(struct vehicle** array, int length) {
    for (int index = 0; index < length; index++) {
        if (array[index]) {
            clean_vehicle(array[index]);
        }
    }
    free(array);
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
