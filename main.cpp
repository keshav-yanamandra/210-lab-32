// Keshav Yanamandra
// COMSC-210
// Lab 33

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int INITIAL_CARS = 2;
//chances are %s so they add up to 100
// const int PAY_CHANCE = 55;
// const int JOIN_CHANCE = 45;
//lanes
const int LANES = 4;

void displayQueue(deque<Car> &lane);

int main() {

    srand(time(0));

    deque<Car> lanes[LANES];

    // putting 2 cars in each lane
    for (int i = 0; i < LANES; i++) {
        for (int j = 0; j < INITIAL_CARS; j++) {
            Car car;
            lanes[i].push_back(car);
        }
    }

    // test the array of deques
    // for (int i = 0; i < LANES; i++) {
    //     Car testCar;
    //     lanes[i].push_back(testCar);

    //     cout << "Lane " << i + 1 << " size: "
    //         << lanes[i].size() << endl;

    //     cout << "Front car: ";
    //     lanes[i].front().print();

    //     cout << "Back car: ";
    //     lanes[i].back().print();

    //     lanes[i].pop_back();
    // }

    deque<Car> lane;

    // loop instantiates the lane with the starting cars
    for (int i = 0; i < INITIAL_CARS; i++) {
        Car car;
        lane.push_back(car);
    }

    // cout << "Number of cars: " << lane.size() << endl;
    // cout << "First car: ";
    // lane.front().print();

    cout << "Initial queue:" << endl;

    for (int i = 0; i < LANES; i++) {
        cout << "Lane " << i + 1 << ":" << endl;
        displayQueue(lanes[i]);
    }

    // displayQueue(lane);

    // // named it t and not time because ctime already has a time() function 
    // int t = 0;

    // while (!lane.empty()) {

    //     t++;

    //     int o = rand() % (PAY_CHANCE + JOIN_CHANCE);


    //     cout << endl;
    //     cout << "Time: " << t << " Operation: ";

    //     if (o < PAY_CHANCE) {
    //         cout << "Car paid: ";
    //         lane.front().print();
    //         lane.pop_front();
    //     }
    //     else {
    //         Car car;
    //         lane.push_back(car);

    //         cout << "Joined lane: ";
    //         car.print();
    //     }

    //     cout << "Queue:" << endl;
    //     displayQueue(lane);

    // }

    return 0;
}

// prints the whole lane with 4 spaces in front of each car
void displayQueue(deque<Car> &lane) {

    // handling for empty
    if (lane.empty()) {
        cout << "    Empty" << endl;
        return;
    }

    for (deque<Car>::iterator it = lane.begin();
         it != lane.end(); ++it) {

        cout << "    ";
        it->print();
    }
}

