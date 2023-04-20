#include "User.h"

class ListUser {
  private:
    User *head;
  public:
    ListUser() {
      head = nullptr;
    }

    void insert(string n, float m) {
      User *newUser = new User(n, m);

      if(head == nullptr) {
        head = newUser;
      } else {
        User *current = head;
        while(current->next != nullptr) {
          current = current->next;
        }
        current->next = newUser;
      }
    }

    void display() {
      User *t = head;
      while(t != nullptr) {
        cout << t->name << endl;
        t = t->next;
      }
    }

    bool checkUser(const string &Name) {
      User *t = head;
      while(t) {
        if(t->name == Name){
          cout << "User : " << t->name << endl;
          cout << "Credit : ";
          t->show_money();
          cout << " $" << endl;
          return true;
        }else {
          t = t->next;
        }
      }
      return false;
    }
};