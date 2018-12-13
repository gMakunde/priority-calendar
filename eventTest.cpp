#include <iostream>
#include <string>
#include<fstream>
#include "event.h"
#include "assigncal.h"
#include "calendar.h"
using namespace std;

int main() {
  int fm, fd, fy, counter;
  int month, day, year, daysLeft, imp;
  string Type, name;
  Assignment a;
  Calendar c;
  Eventlist list;

  cout << "Enter today's month, day and year (numerical): " << endl;
  cin >> month;
  cin >> day;
  cin >> year;
  
  char yesno = 'y';
  while (yesno == 'y' || yesno == 'Y'){
    cout << "Import event from file?(y/n)" << endl;
    cin >> yesno;
    if (yesno == 'y' || yesno == 'Y'){
      ifstream file;
      file.open("events.txt");
      if(file.is_open()){
        int size;
        cout << "How Many events are on the file?" << endl;
        cin >> size;
        for(int i=0; i<size; i++){
          file >> name >> Type >> fm >> fd >> fy;
          
          
          daysLeft = amountofDays(month, day, year, fm, fd, fy, 0);
          imp = importanceLevel(daysLeft, Type);
          list.insert(name, Type, imp, daysLeft);
        }
      }
      file.close();

    }else{
      cout << "What is the name of the event: " << endl;
      cin.ignore();
      getline(cin, name);
      cout << "What type of event is it? (Holiday, Birthday, Assignment, Test): " << endl;
      getline(cin, Type);
      cout << "Enter Event month day and year: " << endl;
      cin >> fm;
      cin >> fd;
      cin >> fy;
      Calendar(name, Type, fm, fd, fy);
      
      
    
    daysLeft = amountofDays(month, day, year, fm, fd, fy, 0);
    imp = importanceLevel(daysLeft, Type);
    list.insert(name, Type, imp, daysLeft);
    }
    cout << "Enter another event? (y/n)" << endl;
    cin >> yesno;
  }
  cout << endl << endl << "YOUR PRIORITY LIST:" << endl;
  list.displayList();
  string value1, value2;
  int value3, value4;
  //fstream file;
  //cout << "To saving events to file event.txt..." << endl;

  //file.open("event.txt", ios::app);
  //if(file.is_open()){
  //  while (list){
  //    list.(value1, value2, value3, value4);
  //    file << value1 << " " << value2 << " " << value3 << " " << value4 << endl;
  //  }
  //}
  //file.close();
  
  return 0;
}

