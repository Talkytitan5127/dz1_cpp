#include <gtest/gtest.h>

extern "C" {
#include "../include/vehicle.h"
}

TEST(init, init_ok) {
    char name_model[] = "mercedes";
    char car_type[] = "e-class";
    int speed = 320;
    int power = 540;
    int fuel_flow = 13;
    struct vehicle* obj = NULL;
    init_vehicle(&obj, name_model, car_type, speed, fuel_flow, power);
    ASSERT_EQ(name_model, obj->name_model);
    ASSERT_EQ(car_type, obj->car_type);
    ASSERT_EQ(speed, obj->speed);
    ASSERT_EQ(fuel_flow, obj->fuel_flow);
    ASSERT_EQ(power, obj->engine_power);
    delete obj;
}

TEST(equal, equal_ok) {
    char name_model[] = "mercedes";
    char car_type[] = "e-class";
    int speed = 320;
    int power = 540;
    int fuel_flow = 13;
    struct vehicle* obj = NULL;
    struct vehicle* search = NULL;
    init_vehicle(&obj, name_model, car_type, speed, fuel_flow, power);
    init_vehicle(&search, name_model, car_type, speed, fuel_flow, power);
    ASSERT_TRUE(equal(search, obj));
    free(obj);
    free(search);
}

TEST(equal, equal_empty_ok) {
    char name_model[] = "mercedes";
    char car_type[] = "e-class";
    int speed = 320;
    int power = 540;
    int fuel_flow = 13;
    struct vehicle* obj = NULL;
    struct vehicle* search = NULL;
    init_vehicle(&obj, name_model, car_type, speed, fuel_flow, power);
    ASSERT_FALSE(equal(search, obj));
    free(obj);
    free(search);
}

TEST(find, find_vehicle_ok) {
    int count = 1;
    struct vehicle** array;
    array = (vehicle **)malloc(count * vehicle_size());
    char name_model[] = "mercedes";
    char car_type[] = "e-class";
    int speed = 320;
    int power = 540;
    int fuel_flow = 13;
    struct vehicle* search = NULL;
    init_vehicle(array, name_model, car_type, speed, fuel_flow, power);
    init_vehicle(&search, name_model, car_type, speed, fuel_flow, power);
    ASSERT_EQ(find_vehicle(search, array, count, NULL), 1);
    free(search);
    clear_array(array, count);
}
TEST(find, find_empty_ok) {
    int count = 1;
    struct vehicle** array;
    array = (vehicle **)malloc(count * vehicle_size());
    char name_model[] = "mercedes";
    char car_type[] = "e-class";
    int speed = 320;
    int power = 540;
    int fuel_flow = 13;
    struct vehicle* search = NULL;
    init_vehicle(array, name_model, car_type, speed, fuel_flow, power);
    ASSERT_EQ(find_vehicle(search, array, count, NULL), 1);
    free(search);
    clear_array(array, count);
}