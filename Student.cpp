/*
Pranav Saravanan
Student id: 2341335
Email: saravanan@chapman.edu
CPSC 350-01
Registrar’s Office Simulation
*/

#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(){
    timeAtWindow = 0;
    entryTime = 0;
    timeInQueue = 0;
    idleTime = 0;
}

Student::~Student(){

};

Student::Student(int t, int e){
    timeAtWindow = t;
    entryTime = e;
    timeInQueue = 0;
    idleTime = 0;
}
