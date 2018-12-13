#ifndef EVENT_H
#define EVENT_H
#include <string>
using namespace std;
class Event{
  private:
    struct ListNode{
      string Type, name;
      int importance;
      int days;
      struct ListNode *next;
    };
    ListNode *head;
  public:
    Event()
    {head = nullptr;}
    void setattributes(string type, int imp, int days){
      ListNode newnode;
      newnode.Type = type;
      newnode.importance = imp;
      newnode.days = days;
    }
    void insert(string name, string type, int imp, int days){
      ListNode *newnode;
      newnode = new ListNode;
      newnode->name = name, newnode->Type = type, newnode->importance = imp, newnode->days = days, newnode->next = nullptr;
      ListNode *nodeptr;
      ListNode *prevNode;
      prevNode = new ListNode;
      prevNode = nullptr;
      nodeptr = head;

        while(nodeptr && nodeptr->importance >= newnode->importance){
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
    void insertNode(string name, string type, int imp, int days){
      ListNode *newnode;
     

      newnode = new ListNode;
      newnode->name = name;
      newnode->Type = type;
      newnode->importance = imp;
      newnode->days = days;
      newnode->next = nullptr;

      if(!head){
        head = newnode;
        newnode->next = nullptr;
      }else{
        insert(name,type,imp,days);
      }
    }
    void displayList() const{
      ListNode *nodeptr;
      nodeptr = head;

      while(nodeptr){
          cout << nodeptr->name << ": " << nodeptr->Type << " is " << nodeptr->days << " days away from today." << endl;
          nodeptr = nodeptr->next;
      }
    }
    
  
};
#endif
