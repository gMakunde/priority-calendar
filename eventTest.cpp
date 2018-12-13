#include <iostream>
#include <string>
#include "event.h"
#include "calendar.h"
using namespace std;

int main() {
  int fm, fd, fy, counter;
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
  
  char yesno = 'y';
  while (yesno == 'y' || yesno == 'Y'){
    cout << "What is the name of the event: " << endl;
    cin.ignore();
    getline(cin, name);
    cout << "What type of event is it? (Holiday, Birthday, Assignment, Test): " << endl;
    getline(cin, Type);

    cout << "Enter the month of the event: " << endl;
    cin >> fm;
    cout << "Enter the day of the event: " << endl;
    cin >> fd;
    cout << "Enter the year of the event: " << endl;
    cin >> fy;
    cout << "hi" << endl;
    daysLeft = amountofDays(month, day, year);
    imp = importanceLevel(daysLeft, Type);
    list.enqueue(name, Type, imp, daysLeft);

    cout << "Enter another event? (y/n)" << endl;
    cin >> yesno;
  }
  cout << endl << endl << "YOUR PRIORITY LIST:" << endl;
  string value1, value2;
  int value3, value4;
  while (!list.isEmpty()){
    list.dequeue(value1, value2, value3, value4);
    cout << value1 << " " << value2 << " " << value3 << " " << value4 << endl;
  }
}

