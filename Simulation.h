/*
Pranav Saravanan
Student id: 2341335
Email: saravanan@chapman.edu
CPSC 350-01
Registrar’s Office Simulation
*/

#include "Queue.h"
#include "Student.h"
#include <string>

using namespace std;

class Simulation{
    private:

    public:
        Simulation();
        ~Simulation();

        bool inputFile(string file);
        bool time(int num);

        double calcMeanWait();
        double calcMedianWait();
        int calcLongestWait();
        int calcNumWaitsOverTen();

        double calcMeanIdle();
        int calcLongestIdle();
        int calcNumIdleOverFive();

        Student* *windowArray;
        Queue<Student*> studentQueue;

        Queue<int> waitTimeList;
        Queue<int> idleTimeList;

        int *medianArray;
        int *idleArray;

        int totalWindows;
        int totalStudents;

        int type;
        int entryTime;
        int timeAtWindow;
        int clockTickNum;
        int medianArrayCount;
        int idleArrayCount;
};
