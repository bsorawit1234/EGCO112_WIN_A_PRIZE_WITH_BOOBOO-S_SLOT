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
      int flags, flags_for_nested;
      float deposit; 
      char yes_or_no;
      while(t) {
        if(t->name == Name){
          cout << "User : " << t->name << endl;
          cout << "Credit : ";
          t->display_money();
          cout << " $" << endl;
          try{
            flags = 0;
            cout << "Bet Amount : ";
            cin >> bet;
            cin.clear();
            if(bet > t->show_money()) {
              cout << "\033[F";
              cout << "Bet Amount : " << bet << " $" << endl;
              cout << "You have insufficient credit." << endl;
              do {
                if(flags_for_nested) {
                  /* clear the screen after loop */
                }
                flags_for_nested = 0;
                cout << "Do you want to deposit money?(Y/N) " << endl;
                cin >> yes_or_no;
                cin.clear();
                if(yes_or_no == 'y' || yes_or_no == 'Y') {
                  /* add credits */
                  cout << "How much credit do you want to deposit? : ";
                  cin >> deposit;
                  //cin.clear();
                  t->deposit(deposit);
                } else if(yes_or_no == 'n' || yes_or_no == 'N') {
                  /* exit program */
                  for(int i = 0; i < 3; i++) {
                    cout << "\033[F"; /* clear 3 lines before error message. */
                  }
                  throw "You have insufficient credits.";
                } else {
                  flags_for_nested = 1;
                }
              } while(flags_for_nested);
            }
            cout << "\033[F";
            cout << "Bet Amount : " << bet << " $" << endl;
          } catch(const char* e) {
            flags = 1;
            cout << e << endl;
          }
        } else {
          if(!t) {
            throw "Username is invalid.";
          }
        }
        t = t->next;
      }
    }


};