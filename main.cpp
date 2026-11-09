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
const int PAY_CHANCE = 46;
const int JOIN_CHANCE = 39;
const int SWITCH_CHANCE = 15;
//lanes
const int LANES = 4;
const int PERIODS=20;

void displayQueue(deque<Car> &lane);

void displayPeriodQueue(deque<Car> &lane, int laneNum);

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

    for (int t = 1; t <= PERIODS; t++) {

        cout << endl;
        cout << "Time: " << t << endl;

        // all lanes first
        for (int i = 0; i < LANES; i++) {

            int roll = rand() % 100;

            if (roll < PAY_CHANCE && !lanes[i].empty()) {
                cout << "Lane: " << i + 1 << " Paid: ";
                lanes[i].front().print();
                lanes[i].pop_front();
            }
            else if (roll < PAY_CHANCE + JOIN_CHANCE) {
                Car car;
                lanes[i].push_back(car);

                cout << "Lane: " << i + 1 << " Joined: ";
                car.print();
            }
            else if (!lanes[i].empty()) {
                cout << "Lane: " << i + 1 << " Switched: ";
                lanes[i].back().print();
            }


        }

        // then print all queues
        for (int i = 0; i < LANES; i++) {
            displayPeriodQueue(lanes[i], i + 1);
        }
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

// prints a lane 
void displayPeriodQueue(deque<Car> &lane, int laneNum) {

    if (lane.empty()) {
        cout << "Lane " << laneNum << " Queue: empty" << endl;
        return;
    }

    cout << "Lane " << laneNum << " Queue: " << endl;

    for (deque<Car>::iterator it = lane.begin();
        it != lane.end(); ++it) {

        cout << "        ";
        it->print();
    }
}

