#include <iostream>
#include <string>
#include "event.h"
using namespace std;

int amountofDays(int, int, int);
int importanceLevel(int, string);
int fm, fd, fy, counter;

int main() {
  int month, day, year, daysLeft, imp;
  string Type, name;
  Event list;

  cout << "Enter today's month (numerical): " << endl;
  cin >> month;
  cout << "Enter today's day: " << endl;
  cin >> day;
  cout << "Enter today's year: " << endl;
  cin >> year;


  counter = 0;
  cout << "What is the name of the event: " << endl;
  cin.ignore();
  getline(cin, name);
  do{
    cout << "What type of event is it? (Holiday, Birthday, Assignment, Test: " << endl;
    getline(cin, Type);

    cout << "Enter the month of the event: " << endl;
    cin >> fm;
    cout << "Enter the day of the event: " << endl;
    cin >> fd;
    cout << "Enter the year of the event: " << endl;
    cin >> fy;
    daysLeft = amountofDays(month, day, year);
    imp = importanceLevel(daysLeft, Type);
    list.insertNode(name, Type, imp, daysLeft);


    cout << "What is the name of the event (enter '0' to exit): " << endl;
    cin.ignore();
    getline(cin, name);
    //importance = importanceLevel(daysLeft, Type);
    
  counter = 0;
  }while (name != "0");
  //importance = importanceLevel(daysLeft, Type);
  cout << endl << endl << "YOUR PRIORITY LIST:" << endl;
  list.displayList();
}

int importanceLevel(int daysL, string TypeofEvent){
  int importance = 0;
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
    importance = 1;
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

int amountofDays(int m, int d, int y){
  //If the day is the same as the day of the event, RETURN THE AMOUNT OF DAYS BETWEEN
  if(fm == m && fd == d && fy == y)
    return counter;

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
  return amountofDays(m, d, y);
}
