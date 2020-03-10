#include "../include/vehicle.h"
#include <stdio.h>
#include <stdlib.h>

void print_criteria();

int main(int argc, char** argv) {
    int count = input_int("Введите количество автомобилей");
    printf("%d\n", count);

    struct vehicle** array;
    array = (struct vehicle**)malloc(count * vehicle_size());

    for (int index = 0; index < count; index++) {
        char* name_model = input_string("Введите марку машины", LEN_BUF);
        if (!name_model) {
            clear_array(array, count);
            return 1;
        }
        char* car_type = input_string("Введите тип кузова", LEN_BUF);
        if (!car_type) {
            clear_array(array, count);
            return 1;
        }
        int speed = input_int("Введите скорость машины");
        if  (!speed) {
            clear_array(array, count);
            return 1;
        }
        int fuel_flow = input_int("Введите расход топлива");
        if (!fuel_flow) {
            clear_array(array, count);
            return 1;
        }
        int power = input_int("Введите мощность двигателя");
        if (!power) {
            clear_array(array, count);
            return 1;
        }

        bool error = init_vehicle(
                &array[index],
                name_model,
                car_type,
                speed,
                fuel_flow,
                power);
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
        switcher = input_int("Введите цифру:");
        switch (switcher) {
            case 1:
                string = input_string("Введите марку:", LEN_BUF);
                if (!string) {
                    printf("Неверно введена марка");
                    break;
                }
                search_obj->name_model = string;
                break;
            case 2:
                string = input_string("Введите тип кузова:", LEN_BUF);
                if (!string) {
                    printf("Неверно введен тип");
                    break;
                }
                search_obj->car_type = string;
                break;
            case 3:
                number = input_int("Введите скорость:");
                if (!number) {
                    printf("Неверно введена скорость");
                    break;
                }
                search_obj->speed = number;
                break;
            case 4:
                number = input_int("Введите расход топлива");
                if (!number) {
                    printf("Неверно введен расход");
                    break;
                }
                search_obj->fuel_flow = number;
                break;
            case 5:
                number = input_int("Введите мощность двигателя");
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

void print_criteria() {
    printf("Выберите критерий поиска:\n");
    printf("1 - название марки\n");
    printf("2 - тип кузова\n");
    printf("3 - величина скорости\n");
    printf("4 - расход топлива\n");
    printf("5 - мощность двигателя\n");
    printf("6 - найти по заданным критериям\n");
}
