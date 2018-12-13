#ifndef EVENT_H
#define EVENT_H
#include <string>
using namespace std;

int amountofDays(int, int, int, int, int, int, int);
int importanceLevel(int, string);
void todo();
void prioritzer();
void CalcImportanceandInsert(int, int, int, int, int, int, string, string,string);

class Eventlist{
  private:
    struct ListNode{
      string Type, name, eventAtrribute;
      int importance;
      int days;
      struct ListNode *next;
    };
    ListNode *head;
  public:
    Eventlist()
    {head = nullptr;}
    void setattributes(string type, int imp, int days){
      ListNode newnode;
      newnode.Type = type;
      newnode.importance = imp;
      newnode.days = days;
    }
    void insert(string name, string type, int imp, int days, string ea){
      cout << "check 3.5" << endl;
      ListNode *newnode;
      newnode = new ListNode;
      newnode->name = name, newnode->Type = type, newnode->importance = imp, newnode->days = days, newnode->next = nullptr, newnode->eventAtrribute = ea;
      ListNode *nodeptr;
      ListNode *prevNode;
      prevNode = new ListNode;
      prevNode = nullptr;
      nodeptr = head;

        while(nodeptr && nodeptr->importance >= newnode->importance){
          cout << "check 3.6" << endl;
          prevNode = nodeptr;
          nodeptr = nodeptr->next;
        }
        if(prevNode == nullptr){
          head = newnode;
          newnode->next = nodeptr;
        }else{
          prevNode->next = newnode;
          newnode->next = nodeptr;
        }

    }
    void insertNode(string name, string type, int imp, int days, string ea){
      cout << "check 3.1" << endl;
      ListNode *newnode;
      newnode = new ListNode;
      newnode->name = name;
      newnode->Type = type;
      newnode->importance = imp;
      newnode->days = days;
      newnode->eventAtrribute = ea;
      newnode->next = nullptr;
      cout << "check 3.2" << endl;
      if(!head){
        cout << "check 3.3" << endl;
        head = newnode;
        newnode->next = nullptr;
      }else{
        cout << "check 3.4" << endl;
        insert(name,type,imp,days,ea);
      }
    }
    
    void displayList() const{
      cout >> "head:" >> head->name >> endl
      ListNode *nodeptr;
      cout >> "check 4.1" >>endl;
      nodeptr = head;
      cout >> "check 4.2" >> endl;
      while(nodeptr){
        cout << "mic mic" << endl;
          cout << nodeptr->name << ": " << nodeptr->Type << " is " << nodeptr->days << " days away from today." << endl;
          nodeptr = nodeptr->next;
      }
    }
    
  
};

class Event{
  private:
    struct QueueNode{
      string Type, name, eventAtrribute;
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

    void enqueue(string, string, int, int, string);
    void dequeue(string &, string &, int &, int &, string&);
    bool isEmpty() const;
    void clear();
};

#endif
