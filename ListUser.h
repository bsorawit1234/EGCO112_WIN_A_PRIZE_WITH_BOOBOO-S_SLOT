#include "User.h"

class ListUser : public exception{
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

    void checkUser(const string &Name, float &bet){
      User *t = head;
      while(t) {
        if(t->name == Name){
          cout << "User : " << t->name << endl;
          cout << "Credit : ";
          t->show_money();
          cout << " $" << endl;
          cout << "Bet Amount : ", cin >> bet;
          cin.clear();
          cout << "\033[F";
          cout << "Bet Amount : " << bet << " $" << endl;
          break;
        } else {
          t = t->next;
          if(!t) {
            throw "Username is invalid.";
          }
        }
      }
    }
};