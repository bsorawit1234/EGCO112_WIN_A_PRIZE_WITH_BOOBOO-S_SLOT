#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <sstream>

#include "ListUser.h"
#include "excep_tion.h"
#include "login_register.h"
#include "home.h"
#include "Admin.h"

void start() {
  ListUser Players;
  User *player, *create_LL;
  int choose, check_choose = 1;
  std::string user, users, passe, read_from_file, ranks;
  const std::string USER = "user", vip = "vip";
  float Money, credit;

  clear_screen();

  std::cout << "*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--* " << std::endl;
  std::cout << "       WELCOME TO WIN A PRIZE WITH BOO BOO'S SLOT      " << std::endl;
  std::cout << "*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--* " << std::endl;
  std::cout << " " << std::endl;
  std::cout << "                   PRESS 1 TO REGISTER                " << std::endl;
  std::cout << "                   PRESS 2 TO LOGIN " << std::endl;
  std::cout << "                   PRESS 3 TO ADMIN" << std::endl;
  std::cout << "                   PRESS 4 TO EXIT" << std::endl;
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

      if(choose < 1 || choose > 4) {
        throw "CHOOSE BETWEEN 1-4";
      }

      if(choose == 2 || choose == 3) {
        std::ifstream isempty("Total.txt");
        if(isempty.fail()){
          throw "You have not registered, please register first";
        }
      }

      check_choose = 0;
    } catch(const char* s) {
      std::cout << std::endl << s << std::endl << std::endl;
    }
  }
  
  clear_screen();    

  switch(choose) {
    case 1: 
      user = login_register(1);
      break;
    case 2:  
      user = login_register(choose);
      break;
    case 4:
      return;
  }

  std::ifstream insert_ll("Total.txt");
  while(!insert_ll.eof()) {
    std::getline(insert_ll, read_from_file);
    if(read_from_file.length() == 0) continue;
    std::istringstream ss(read_from_file);
    ss >> users >> passe >> Money >> credit >> ranks;
    if(ranks == USER) {
      create_LL = new User(users, Money, credit);
    } else if(ranks == vip) {
      create_LL = new VIP(users, Money, credit);
    }
    Players.add_node(create_LL);
  }
  insert_ll.close();
  
  player = Players.find_node(user); 

  if(choose == 3) {
    admin_page(Players);
    start();
    return;
  }

  home(player);
  start();

}

void intro() {
  clear_screen();
  
  msleep(800);
  std::cout << "      __    __  __  __  ___          _          __ ___   __  __   __  ______   __  __" << std::endl;
  std::cout << "     |  |  |  ||  ||  \\|   |        / \\        |  |\\   \\|  |\\  \\'|  ||___  /  |  |\\  \\" << std::endl;
  std::cout << "     | '|/\\| '|| '|| '|\\  '|      '/  '\\       |  '|/__/| '|/  / | '|   /'/__ |  _''>" << std::endl;
  std::cout << "     |__,/\\'__||__||__|'|__|      /_____\\      |__|    '|__|'\\__\\|__|''/_____/|__|/__/  )" << std::endl;

  msleep(1200);
  std::cout << "                             __    __  __  ________  __    __" << std::endl;;
  std::cout << "                            |  |  |  ||  ||__    __||_ |  | _|" << std::endl;;
  std::cout << "                            | '|/\\| '|| '|   | '|  ' | ';=; |" << std::endl;;
  std::cout << "                            |__,/\\'__||__|  '|__|'''|__|  |__| )" << std::endl;

  msleep(1200);
  std::cout << " __  __    ____     ____        __  __    ____     ____       ______       ______  __       ____    ________" << std::endl;
  std::cout << "|  |\\  \\ /  /\\  \\'/  /\\  \\'    |  |\\  \\ /  /\\  \\'/  /\\  \\'   /  /\\__\\     /  /\\__\\|  |   '/  /\\  \\'|__    __|" << std::endl;
  std::cout << "| '|( '(|  |  | '|| |  | '|    | '|( '(|  |  | '|| |  | '|  _\\  \\''      _\\  \\''  | '|__ |  |  | '|   | '| '" << std::endl;
  std::cout << "|__|/__/ \\__\\/__/'\\__\\/__/'    |__|/__/ \\__\\/__/'\\__\\/__/' \\__\\/__/     \\__\\/__/  |_____| \\__\\/__/'  '|__|''" << std::endl;
  
  msleep(3000);
  clear_screen();
}

int main() {
  srand(time(NULL));

  intro();

  start();

  return 0;
}