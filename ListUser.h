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
      std::cout << "LL has been destructor." << std::endl;
    }

    void insert(std::string n, float m, float c) {
      User *newUser = new User(n, m, c);

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
        std::cout << t->name << std::endl;
        t = t->next;
      }
    }

    User* find_node(std::string &n) {
      User* temp = head;
      while(temp) {
        if(temp->name == n) {
          break;
        }
        temp = temp->next;
      }
      return temp;
    }

};