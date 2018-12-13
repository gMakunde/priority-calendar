#ifndef CALENDAR_H
#define CALENDAR_H
#include <string>
using namespace std;

class Calendar{
  private:
    string name;
  
  public:
    Calendar() {
      name = " ";
    }
    
    Calendar(String n){
      name = n;
    }

    void setName(string n)
      {name = n;}

    string getName() const
      {return name}
};
#endif
