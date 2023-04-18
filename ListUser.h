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
};