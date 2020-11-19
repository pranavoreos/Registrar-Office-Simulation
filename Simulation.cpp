/*
Pranav Saravanan
Student id: 2341335
Email: saravanan@chapman.edu
CPSC 350-01
Registrar’s Office Simulation
*/

#include <iostream>
#include <fstream>
#include "Simulation.h"
#include <algorithm>
#include <array>
#include <string>

using namespace std;

Simulation::Simulation(){
    type = 1;
    entryTime = 0;
    timeAtWindow = 0;
    clockTickNum = 0;

    medianArrayCount = 0;
    idleArrayCount = 0;

    totalWindows = 0;
    totalStudents = 0;
}

Simulation::~Simulation(){

}

bool Simulation::inputFile(string file){
	ifstream inputFile;
	inputFile.open(file.c_str());
	string line;
    int lineNum = 1;

	if (inputFile.is_open()){
       		getline(inputFile, line);
       		totalWindows = stoi(line);

          windowArray = new Student*[totalWindows];
          for (int i = 0; i < totalWindows; ++i){
            Student* student1 = new Student();
            windowArray[i] = student1;
          }
          lineNum++;
          while (getline(inputFile, line)){
            switch (type){
                case (1):{
                  entryTime = stoi(line);
                  type++;
                  lineNum++;
                  break;
                }

                case (2):{
                  if (line != ""){
                    clockTickNum = stoi(line);
                    for (int i = 0; i < clockTickNum; ++i){
                      getline(inputFile, line);
                      timeAtWindow = stoi(line);
                      lineNum++;
                      totalStudents++;
                      Student* student2 = new Student(timeAtWindow, entryTime);
                      studentQueue.insert(student2);
                    }
                    type = 1;
                  }
                    break;
                }
            }
        }
	}
    return true;
}

bool Simulation::time(int num){
    for (int i = 0; i < totalWindows; ++i){
        if (windowArray[i]->timeAtWindow > 0){
            windowArray[i]->timeAtWindow--;
        }
        else{
            windowArray[i]->idleTime++;
        }
    }

    if (!studentQueue.isEmpty()){
        ListNode<Student*> *current = studentQueue.front;

        while (current != NULL){
            if (current->data->entryTime < num){
                current->data->timeInQueue += 1;
            }
            current = current->next;
        }
    }
    return true;
}

double Simulation::calcMeanWait(){
    ListNode<int> *current = waitTimeList.front;

    double meanWait = 0;
    int sum = 0;
    int count = 0;

    while (current != NULL){
        sum += current->data;
        current = current->next;

        count++;
    }

    meanWait = double(sum) / double(count);
    return meanWait;
}

double Simulation::calcMedianWait(){
    ListNode<int> *current = waitTimeList.front;

    double medianWait = 0;
    medianArrayCount = 0;
    while (current != NULL){
        current = current->next;

        medianArrayCount++;
    }
        medianArray = new int[medianArrayCount];

        current = waitTimeList.front;
        for (int i = 0; i < medianArrayCount; ++i){
            medianArray[i] = current->data;

            current = current->next;
        }
        sort(medianArray, medianArray + medianArrayCount);
        if (medianArrayCount % 2 == 1){
            double d = 0;
            int num = 0;

            num = (medianArrayCount / 2) + 1;
            d = medianArray[num];
            return d;
        }
        else{
            double d = 0;
            int num1 = 0;
            int num2 = 0;

            num1 = medianArrayCount / 2;
            num2 = (medianArrayCount / 2) + 1;

            d = double(medianArray[num1]) / double(medianArray[num2]);
            return d;
        }
    }


int Simulation::calcLongestWait(){
    if (medianArrayCount != 0){
        return medianArray[medianArrayCount - 1];
    }
}


int Simulation::calcNumWaitsOverTen(){
    if (medianArrayCount != 0){
        int c = 0;

        for (int i = 0; i < medianArrayCount; ++i){
            if (medianArray[i] > 10){
                ++c;
            }
        }
        return c;
    }
}

double Simulation::calcMeanIdle(){
    ListNode<int> *current = idleTimeList.front;

    double meanIdle = 0;
    int sum = 0;
    int count = 0;

    while (current != NULL){
        sum += current->data;
        current = current->next;
        count++;
    }
    meanIdle = double(sum) / double(count);
    return meanIdle;
}

int Simulation::calcLongestIdle(){
    ListNode<int> *current = idleTimeList.front;

    idleArrayCount = 0;
    while (current != NULL){
        current = current->next;
        idleArrayCount++;
    }

    idleArray = new int[idleArrayCount];
    current = idleTimeList.front;
    for (int i = 0; i < idleArrayCount; ++i){
        idleArray[i] = current->data;
        current = current->next;
    }
    sort(idleArray, idleArray + idleArrayCount);
    return (idleArray[idleArrayCount - 1]);
}

int Simulation::calcNumIdleOverFive(){
    int num = 0;
    for (int i = 0; i < idleArrayCount; ++i){
        if (idleArray[i] > 5){
            ++num;
        }
    }
    return num;
}
