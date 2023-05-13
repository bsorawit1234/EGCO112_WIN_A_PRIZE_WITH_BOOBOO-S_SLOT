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
  User *t;
  int choose, check_choose = 1;
  std::string user;
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

  ListUser Players;
  std::string read_from_file, users, passe;
  float Money, credit;

  switch(choose) {
    case 1: 
      user = login_register(1);
      break;
    case 2:
      user = login_register(2);
      break;
    case 3:
      return;
  }

  std::ifstream insert_ll("Total.txt");
  while(!insert_ll.eof()) {
    std::getline(insert_ll, read_from_file);
    if(read_from_file.length() == 0) continue;
    std::istringstream ss(read_from_file);
    ss >> users >> passe >> Money >> credit;
    Players.insert(users, Money, credit);
  }
  insert_ll.close();
  
  player = Players.find_node(user);

  home(player);
  start(player);

}

int main() {
  srand(time(NULL));

  User* u2;
  start(u2);

  return 0;
}