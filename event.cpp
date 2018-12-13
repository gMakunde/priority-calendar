#include <iostream>
#include <string>
#include "event.h"
using namespace std;


int importanceLevel(int daysL, string TypeofEvent){
  int importance;
  if(TypeofEvent == "Test" || TypeofEvent == "test"){
    importance = 5;
  }
  if(TypeofEvent == "Assignment" || TypeofEvent == "assignment"){
    importance = 4;
  }
  if(TypeofEvent == "Birthday" || TypeofEvent == "birthday"){
      importance = 2;
  }
  if(TypeofEvent == "Holiday" || TypeofEvent == "holiday"){
    importance = 1;
  }

  if(daysL > 30){
    importance = importance + 1;
  }
  if(daysL > 21 && daysL <= 30){
    importance = importance + 2;
  }
  if(daysL > 14 && daysL <= 21){
    importance = importance + 3;
  }
  if(daysL > 7 && daysL <= 14){
    importance = importance + 4;
  }
  if(daysL > 0 && daysL <= 7){
    importance = importance + 5;
  }

  return importance;
}

int amountofDays(int m, int d, int y, int fm, int fd, int fy, int counter){
  //If the day is the same as the day of the event, RETURN THE AMOUNT OF DAYS BETWEEN
  if(fm == m && fd == d && fy == y){
    return counter;
  }
  //INCREMENT THE DAY AND AMOUNT OF DAYS UNTIL THE EVENT
  d++;
  counter++;
  //(LEAP YEAR) CHECKS DAY ACCORDING TO MAKE SURE THE DAY RESTARTS IF REACHES OUT OF MONTH
  if(y % 4 == 0){
    if (m == 2)
      if (d == 30){
        m++;
        d = 1;
      }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
      if (d == 32){
        m++; 
        d = 1;
      }
    if (m == 4 || m == 6 || m == 9 || m == 11)
      if (d == 31){
        m++;
        d = 1;
      }
  }else{
    if (m == 2)
      if (d == 29){
        m++;
        d = 1;
      }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
      if (d == 32){
        m++; 
        d = 1;
      }
    if (m == 4 || m == 6 || m == 9 || m == 11)
      if (d == 31){
        m++;
        d = 1;
      }
  }
  return amountofDays(m, d, y, fm, fd, fy,counter);
}

Event::Event(){
  front = nullptr;
  rear = nullptr;
  numItems = 0;
}

Event::~Event(){
  clear();
}

void Event::enqueue(string n, string t, int i, int d){
  QueueNode *newNode = nullptr;

  newNode = new QueueNode;
  newNode->name = n;
  newNode->importance = i;
  newNode->Type = t;
  newNode->days = d;
  newNode->next = nullptr;

  if(isEmpty()){
    front = newNode;
    rear = newNode;
  }
  else{
    rear->next=newNode;
    rear = newNode;
  }
  numItems++;
}

void Event::dequeue(string &n, string &t, int &i, int &d){
  QueueNode *temp = nullptr;
  if (isEmpty()){
    cout << "The queue is empty" << endl;
  }
  else{
    n = front->name;
    t = front->Type;
    i = front->importance;
    d = front->days;
    temp = front;
    front = front->next;
    delete temp;
    numItems -= 1;
  }
}

void Event::clear(){
  string value, value2;
  int value3, value4;
  while(!isEmpty()){
    dequeue(value, value2, value3, value4);
  }
}

bool Event::isEmpty() const{
  bool status;
  if(numItems >0){
    status = false;
  }
  else{
    status = true;
  }
  return status;
}

