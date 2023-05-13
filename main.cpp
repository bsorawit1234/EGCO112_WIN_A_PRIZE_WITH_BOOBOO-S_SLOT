#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <sstream>

//using namespace std;

#include "ListUser.h"
#include "excep_tion.h"
#include "login_register.h"
#include "home.h"

void start(User *player) {
  int choose, check_choose = 1;
  clear_screen();
  std::cout << "GAME NAME" << std::endl;
  std::cout << "1. REGISTER" << std::endl;
  std::cout << "2. LOGIN" << std::endl;
  std::cout << "3. EXIT" << std::endl;

  while(check_choose) {
    try {
      std::cout << "choose: ";
      std::cin >> choose;
      
      if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        throw "ONLY NUMBER !!";
      }

      if(choose < 1 || choose > 3) {
        throw "CHOOSE BETWEEN 1-3";
      }
      check_choose = 0;
    } catch(const char* s) {
      std::cout << std::endl << s << std::endl << std::endl;
    }
  }

  switch(choose) {
    case 1:
      player = login_register(1);
      break;
    case 2:
      player = login_register(2);
      break;
    case 3:
      // return;
      home(player);
      start(player);
      break;
  }
  // for testing after adjusting return type of login_register function. 
  home(player);
  start(player);
}

int main() {
  srand(time(NULL));

  User u1("boom", 5000, 5000); // for testing
  User* u2;
  start(u2);
}
