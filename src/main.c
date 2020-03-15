#include "../include/vehicle.h"
#include <stdio.h>
#include <stdlib.h>

void print_criteria();

int main(int argc, char** argv) {
    printf("Введите количество автомобилей\n");
    int count = input_int();
    printf("%d\n", count);

    struct vehicle** array;
    array = (struct vehicle**)malloc(count * vehicle_size());
    if (!array) {
        return EXIT_FAILURE;
    }

    for (int index = 0; index < count; index++) {
        printf("Введите марку машины\n");
        char* name_model = input_string(LEN_BUF);
        if (!name_model) {
            clear_array(array, count);
            return EXIT_FAILURE;
        }
        printf("Введите тип кузова\n");
        char* car_type = input_string(LEN_BUF);
        if (!car_type) {
            clear_array(array, count);
            return EXIT_FAILURE;
        }
        printf("Введите скорость машины\n");
        int speed = input_int();
        if  (!speed) {
            clear_array(array, count);
            return EXIT_FAILURE;
        }
        printf("Введите расход топлива\n");
        int fuel_flow = input_int();
        if (!fuel_flow) {
            clear_array(array, count);
            return EXIT_FAILURE;
        }
        printf("Введите мощность двигателя");
        int power = input_int();
        if (!power) {
            clear_array(array, count);
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
            clear_array(array, count);
            return EXIT_FAILURE;
        }
    }

    for (int index = 0; index < count; index++) {
        print_vehicle(array[index]);
    }

    int switcher = 0;
    char *string = NULL;
    int number;
    struct vehicle* search_obj = malloc(vehicle_size());
    if (!search_obj) {
        clear_array(array, count);
        return EXIT_FAILURE;
    }

    int *result = (int*)malloc(count*sizeof(int));
    if (!result) {
        clear_array(array, count);
        clean_vehicle(search_obj);
    }

    int success = 0;
    while (switcher != 6) {
        print_criteria();
        printf("Введите цифру:\n");
        switcher = input_int();
        switch (switcher) {
            case 1:
                printf("Введите марку:");
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
                printf("Введите скорость:\n");
                number = input_int();
                if (!number) {
                    printf("Неверно введена скорость");
                    break;
                }
                search_obj->speed = number;
                break;
            case 4:
                printf("Введите расход топлива");
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
    clean_vehicle(search_obj);
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
