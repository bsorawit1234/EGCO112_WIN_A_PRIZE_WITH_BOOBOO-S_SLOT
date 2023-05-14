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

      if(head == nullptr) {
        head = newUser;
      } else {
        User *current = head;
        while(current->next != nullptr) {
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

    User* find_node(std::string n) {
      User* temp = head;
      while(temp) {
        if(temp->name == n) {
          return temp;
        }
        temp = temp->next;
      }
      return nullptr;
    }

    void add_node(User *A) {
      head->insert(A);
      head = A;
      size++;
    }

    void class_changes(User* A) {
      VIP* new_A = new VIP(A->name, A->get_money(), A->get_credits());
      User* temp = head;
      while(temp) {
        if(temp->name == A->name) {
          temp = new_A;
        }
        temp = temp->next;
      }
    }

};