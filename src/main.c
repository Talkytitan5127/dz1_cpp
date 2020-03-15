#include "../include/vehicle.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    printf("Введите количество автомобилей\n");
    int count = input_int();
    printf("%d\n", count);

    struct vehicle** array;
    array = (struct vehicle**)malloc(count * vehicle_size());
    if (!array) {
        return EXIT_FAILURE;
    }

    int error = input_vehicles(array, count);
    if (error) {
        clear_array(array, count);
        return EXIT_FAILURE;
    }

    for (int index = 0; index < count; index++) {
        print_vehicle(array[index]);
    }

    struct vehicle* search_obj = malloc(vehicle_size());
    if (!search_obj) {
        clear_array(array, count);
        return EXIT_FAILURE;
    }

    error = input_criteria_search(&search_obj);
    if (error) {
        clear_array(array, count);
        clean_vehicle(search_obj);
        return EXIT_FAILURE;
    }

    int *result = (int*)malloc(count*sizeof(int));
    if (!result) {
        clear_array(array, count);
        clean_vehicle(search_obj);
        return EXIT_FAILURE;
    }

    int success = 0;
    success = find_vehicle(search_obj, array, count, &result);

    printf("Итоги поиска:\n");
    if (!success) {
        printf("Нет подходящего авто\n");
    } else {
        for (int index = 0; index < success; index++) {
            int result_index = result[index];
            print_vehicle(array[result_index]);
        }
    }

    clear_array(array, count);
    clean_vehicle(search_obj);
    free(result);
    return 0;
}
