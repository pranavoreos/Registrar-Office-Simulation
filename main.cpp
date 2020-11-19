/*
Pranav Saravanan
Student id: 2341335
Email: saravanan@chapman.edu
CPSC 350-01
Registrar’s Office Simulation
*/

#include <iostream>
#include "Simulation.h"

using namespace std;

int main(int argc, char** argv){

  Simulation simulation1;
  int currentTime = 0;
  int openWindows = 0;
  bool tracker = false;

  if (argc == 2){
    if (simulation1.inputFile(argv[1])){
      while (!tracker){
        if (simulation1.studentQueue.isEmpty()){
          int num = 0;
          for (int i = 0; i < simulation1.totalWindows; ++i){
            if ((simulation1.windowArray[i]->timeAtWindow) < 1){
              num++;
            }
          }

          if (num == simulation1.totalWindows){
            tracker = true;
          }
        }

        for (int i = 0; i < simulation1.totalWindows; ++i){
          if (simulation1.windowArray[i]->timeAtWindow < 1){
            if (!simulation1.studentQueue.isEmpty()){
              Student* student1 = simulation1.studentQueue.returnFront();
              if (student1->entryTime <= currentTime){
                if (simulation1.windowArray[i]->idleTime > 0){
                  simulation1.idleTimeList.insert(simulation1.windowArray[i]->idleTime);
                }
                simulation1.windowArray[i] = simulation1.studentQueue.remove();
                simulation1.waitTimeList.insert(simulation1.windowArray[i]->timeInQueue);
              }
            }
          }
        }
        currentTime++;
        simulation1.time(currentTime);
      }

      for (int i = 0; i < simulation1.totalWindows; ++i){
        if (simulation1.windowArray[i]->idleTime > 0){
          simulation1.idleTimeList.insert(simulation1.windowArray[i]->idleTime);
        }
      }

      cout << "1. The mean student wait time: " << simulation1.calcMeanWait() << endl;
      cout << "2. The median student wait time: " << simulation1.calcMedianWait() <<  endl;
      cout << "3. The longest student wait time: " << simulation1.calcLongestWait() <<  endl;
      cout << "4. The number of students waiting over 10 minutes: " << simulation1.calcNumWaitsOverTen() << endl;
      cout << "5. The mean window idle time: " << simulation1.calcMeanIdle() << endl;
      cout << "6. The longest window idle time: " << simulation1.calcLongestIdle() << endl;
      cout << "7. Number of windows idle for over 5 minutes: " << simulation1.calcNumIdleOverFive() << endl;
    }
	}
  return 0;
}
