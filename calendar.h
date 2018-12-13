#ifndef CALENDAR_H
#define CALENDAR_H
#include <string>
using namespace std;

class Calendar{
  private:
    string name, type;
    int fm, fd, fy;
  
  public:
    Calendar() {
      name = " ";
      type = " ";
      fm = 0;
      fd = 0;
      fy = 0;
    }
    
    Calendar(string n, string t, int m, int d, int y){
      name = n;
      type = t;
      fm = m;
      fd = d;
      fy = y;
    }

    void setName(string n)
      {name = n;}
    void setType(string t)
      {type = t;}
    void setMonth(int m)
      {fm = m;}
    void setDay(int d)
      {fd =d;}
    void setYear(int y)
      {fy = y;}
    string getName() const
      {return name;}
    string getType() const
      {return type;}
    int getMonth() const
      {return fm;}
    int getDay() const
      {return fd;}
    int getYear() const
      {return fy;}
};
#endif
