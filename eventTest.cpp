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
  cout << "What is the name of the event: " << endl;
  cin.ignore();
  getline(cin, name);
  do{
    cout << "What type of event is it? (Holiday, Birthday, Assignment, Test): " << endl;
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

