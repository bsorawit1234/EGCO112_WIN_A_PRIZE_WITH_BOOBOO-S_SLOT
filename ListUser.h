#include "User.h"

class ListUser : public exception{
  private:
    User *head;
  public:
    ListUser() {
      head = NULL;
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
    }

    void display() {
      User *t = head;
      while(t != NULL) {
        cout << t->name << endl;
        t = t->next;
      }
    }

    void checkUser_and_insert_bet(const string &Name, float &bet_amountt){
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
          try{
            cout << "Bet Amount : ";
            cin >> bet_amountt;
            cin.clear();
            cout << "\033[F\033[K";
            cout << "Bet Amount : " << '$' << bet_amountt << endl;
            if(bet_amountt > t->show_credits()) {
              cout << "You have insufficient credit." << endl;
              do {
                flags = 0;
                cout << "Do you want to deposit money?(Y/N) ";
                cin >> yes_or_no;
                cin.clear();
                if(yes_or_no == 'y' || yes_or_no == 'Y') {
                  /* add credits */
                  cout << "How much credit do you want to deposit? : ";
                  cin >> deposit;
                  cin.clear();
                  t->deposit(deposit);
                } else if(yes_or_no == 'n' || yes_or_no == 'N') {
                  /* exit program */
                  for(int i = 0; i < 2; i++) {
                    cout << "\033[F\033[K"; /* clear 2 lines before error message. */
                  }
                  throw "You have insufficient credits.";
                } else {
                  flags = 1;
                }
              } while(flags);
            } else {
              t->bet_amount(bet_amountt);
            }

          } catch(const char* e) {
            cout << e << endl;
          }
          break;

        } else {
          if(t->next == NULL) {
            throw "The username you entered isn't valid.";
          }
          t = t->next;
        }
      }
    }

};