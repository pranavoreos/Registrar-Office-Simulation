/*
Pranav Saravanan
Student id: 2341335
Email: saravanan@chapman.edu
CPSC 350-01
Registrar’s Office Simulation
*/

#include <iostream>

class Student{
    private:

    public:
        Student();
        ~Student();
        Student(int t, int e);

        int timeAtWindow;
        int entryTime;
        int timeInQueue;
        int idleTime;
};
