#include "User.h"

class ListUser{
  private:
    User *head;
    int size;
  public:
    ListUser() {
      head = NULL;
      size = 0;
    }

    ~ListUser() {
    //clear all nodes
      User *temp = head;
      while(size != 0){
          if(temp != NULL){
               temp = head->next;
               delete(head);
               head = temp;
               size--;
          }
      }
     cout << "LL has been destructor." << endl;
    }

    void insert(string n, float m) {
      User *newUser = new User(n, m);

      if(head == NULL) {
        head = newUser;
      } else {
        User *current = head;
        while(current->next != NULL) {
          current = current->next;
        }
        current->next = newUser;
      }
      size++;
    }

    void display() {
      User *t = head;
      while(t != NULL) {
        cout << t->name << endl;
        t = t->next;
      }
    }

    User *checkUser(const string &Name){
      User *t = head;
      int flags;
      float deposit; 
      char yes_or_no;
      while(t) {
        if(t->name == Name){
          cout << "User : " << t->name << endl;
          cout << "Credit : " << '$' ;
          t->display_credits();
          cout << '\n';
          break;
        } else {
          if(t->next == NULL) {
            throw "The username you entered isn't valid.";
          }
          t = t->next;
        }
      }
      return t;
    }



};