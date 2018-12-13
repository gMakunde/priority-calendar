#include <iostream>
#include <string>
#include<fstream>
#include "event.h"
#include "derivecalendar.h"
#include "calendar.h"
using namespace std;

int main() {
  
  int DoOrEvent;
  cout << "Welcome to the Prioritzer" << endl << "Would you like to add an event or view your to do list?(enter 1 for event, enter 2 for To-do list" << endl;
  cin >> DoOrEvent;
  if (DoOrEvent == 1){
    prioritzer();
  }else{
    todo();
  }
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

