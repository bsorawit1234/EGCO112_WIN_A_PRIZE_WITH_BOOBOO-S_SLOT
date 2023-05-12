#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <sstream>

using namespace std;

#include "ListUser.h"
#include "excep_tion.h"
#include "login_register.h"
#include "home.h"

void start(User &player) {
  int choose, check_choose = 1;
  clear_screen();
  cout << "GAME NAME" << endl;
  cout << "1. REGISTER" << endl;
  cout << "2. LOGIN" << endl;
  cout << "3. EXIT" << endl;

  while(check_choose) {
    try {
      cout << "choose: ";
      cin >> choose;
      
      if(cin.fail()) {
        cin.clear();
        cin.ignore(256,'\n');
        throw "ONLY NUMBER !!";
      }

      if(choose < 1 || choose > 3) {
        throw "CHOOSE BETWEEN 1-3";
      }
      check_choose = 0;
    } catch(const char* s) {
      cout << endl << s << endl << endl;
    }
  }

  switch(choose) {
    case 1:
      login_register(1);
      break;
    case 2:
      login_register(2);
      break;
    case 3:
      // return;
      home(player);
      start(player);
      break;
  }
}

int main() {
  srand(time(NULL));

  User u1("boom", 5000, 5000); // for testing
  start(u1);
}
