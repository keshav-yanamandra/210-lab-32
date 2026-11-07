// Keshav Yanamandra
// COMSC-210-5293
// Lab 32

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int INITIAL_CARS = 2;


int main() {

    srand(time(0));
    deque<Car> lane;

    for (int i = 0; i < INITIAL_CARS; i++) {
        Car car;
        lane.push_back(car);
    }

    cout << "Number of cars: " << lane.size() << endl;

    cout << "First car: ";
    lane.front().print();



    return 0;
}