#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <sstream>

#include <chrono>
#include <thread>  

// using namespace std;

#include "ListUser.h"
#include "excep_tion.h"
#include "login_register.h"
#include "home.h"

void start(User *player) {
  int choose, check_choose = 1;
  clear_screen();

  std::cout << "*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--* " << std::endl;
  std::cout << "       WELCOME TO WIN A PRIZE WITH BOO BOO'S SLOT      " << std::endl;
  std::cout << "*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--* " << std::endl;
  std::cout << " " << std::endl;
  std::cout << "                   PRESS 1 TO REGISTER                " << std::endl;
  std::cout << "                   PRESS 2 TO LOGIN " << std::endl;
  std::cout << "                   PRESS 3 TO EXIT GAME" << std::endl;
  std::cout << " " << std::endl;
  std::cout << "*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--* " << std::endl;

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

  // this_thread::sleep_for(chrono::milliseconds(2000));
     
  //   cout << R"(
  //                   __    __  __  __  ___          _          __ ___   __  __   __  ______   __  __
  //                  |  |  |  ||  ||  \|   |        / \        |  |\   \|  |\  \'|  ||___  /  |  |\  \  
  //                  | '|/\| '|| '|| '|\  '|      '/  '\       |  '|/__/| '|/  / | '|   /'/__ |  _''>
  //                  |__,/\'__||__||__|'|__|      /_____\      |__|    '|__|'\__\|__|''/_____/|__|/__/  )" <<endl;

  //   this_thread::sleep_for(chrono::milliseconds(1200));

  //   cout << R"(
  //                                     __    __  __  ________  __    __
  //                                    |  |  |  ||  ||__    __||_ |  | _| 
  //                                    | '|/\| '|| '|   | '|  ' | ';=; |
  //                                    |__,/\'__||__|  '|__|'''|__|  |__| )" <<endl;


  //   this_thread::sleep_for(chrono::milliseconds(1200));

  //   cout << R"(
  //    __  __    ____     ____        __  __    ____     ____       ______       ______  __       ____    ________
  //   |  |\  \ /  /\  \'/  /\  \'    |  |\  \ /  /\  \'/  /\  \'   /  /\__\     /  /\__\|  |   '/  /\  \'|__    __|
  //   | '|( '(|  |  | '|| |  | '|    | '|( '(|  |  | '|| |  | '|  _\  \''      _\  \''  | '|__ |  |  | '|   | '| '
  //   |__|/__/ \__\/__/'\__\/__/'    |__|/__/ \__\/__/'\__\/__/' \__\/__/     \__\/__/  |_____| \__\/__/'  '|__|''  
    
  //    )" <<endl;
     
  //   this_thread::sleep_for(chrono::milliseconds(3000));

  //   clear_screen();


  User *u1 = new User("boom", 5000, 5000); // for testing
  start(u1);
}