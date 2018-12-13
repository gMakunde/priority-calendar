#ifndef ASSIGNCAL_H
#define ASSIGNCAL_H
#include "calendar.h"

class Assignment : public Calendar {
  private:
    string subject;
  public:
    Assignment(){
      subject = "";
    }

    Assignment(string s){
      subject = s;
    }

    void setSubject(string s)
    {subject = s;}

    string getSubject() const
    {return subject;}

};
#endif
