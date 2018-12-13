#ifndef EVENT_H
#define EVENT_H
#include <string>
using namespace std;

int amountofDays(int, int, int);
int importanceLevel(int, string);


class Event{
  private:
    struct QueueNode{
      string Type, name;
      int importance;
      int days;
      QueueNode *next;
    };
    QueueNode *front;
    QueueNode *rear;
    int numItems;
  
  public:
    Event();

    ~Event();

    void enqueue(string, string, int, int);
    void dequeue(string &, string &, int &, int &);
    bool isEmpty() const;
    void clear();
};

#endif
