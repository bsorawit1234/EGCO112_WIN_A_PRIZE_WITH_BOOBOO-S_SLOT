#include "game.h"

void status(User *&player) {
  clear_screen();
  std::cout << "-------- HOME ---------" << std::endl;
  std::cout << "  User    : " << player->name << std::endl;
  std::cout << "  Money   : " << player->get_money() << std::endl;
  std::cout << "  Credits : " << player->get_credits() << std::endl;
  std::cout << "-----------------------" << std::endl;
}

void deposit(User *&player) {
  status(player);
  int check_d = 1, check_m = 1;
  char m;
  float d;
  std::cout << "        DEPOSIT" << std::endl;
  std::cout << "How much do you want to deposit?" << std::endl;
  while(check_d) {
    try {
      std::cout << ": ";
      std::cin >> d;
      if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        throw "ONLY NUMBER!!!";
      }
      if(d > player->get_money()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        throw "You don't have enough money to deposit";
      }
      check_d = 0;
    } catch(const char* s) {
      std::cout << std::endl << s << std::endl << std::endl;
    }
  }

  player->deposit(d);
  status(player);
  std::cout << std::endl << player->name << " deposited " << d << "$" << std::endl;
  
  if(player->get_money() == 0) return;
  std::cout << std::endl << "Do you want to deposit more?" << std::endl;
  while(check_m) {
    try {
      std::cout << "(Y/N) : ";
      std::cin >> m;
      m = tolower(m);
      if(m != 'y' && m != 'n') {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        throw "ONLY Y AND N !!!";
      }
      check_m = 0;
    } catch(const char* s) {
      std::cout << std::endl << s << std::endl;
    }
  }
  if(m == 'y') {
    deposit(player);
  }
}

void withdraw(User *&player) {
  status(player);
  int check_w = 1, check_m = 1;
  char m;
  float w;
  std::cout << "        WITHDRAW" << std::endl;
  std::cout << "How much do you want to withdraw?" << std::endl;
  while(check_w) {
    try {
      std::cout << ": ";
      std::cin >> w;
      if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        throw "ONLY NUMBER!!!";
      }
      if(w > player->get_credits()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        throw "You don't have enough credits to withdraw";
      }
      check_w = 0;
    } catch(const char* s) {
      std::cout << std::endl << s << std::endl << std::endl;
    }
  }

  player->withdraw(w);
  status(player);
  std::cout << std::endl << player->name << " withdrew " << w << "$" << std::endl;
  
  if(player->get_credits() == 0) return;
  std::cout << std::endl << "Do you want to withdraw more?" << std::endl;
  while(check_m) {
    try {
      std::cout << "(Y/N) : ";
      std::cin >> m;
      m = tolower(m);
      if(m != 'y' && m != 'n') {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        throw "ONLY Y AND N !!!";
      }
      check_m = 0;
    } catch(const char* s) {
      std::cout << std::endl << s << std::endl;
    }
  }
  if(m == 'y') {
    withdraw(player);
  }
}

void home(User *&player) {
  int choice, check_choice = 1;
  status(player);
  std::cout << "   1. PLAY" << std::endl;
  std::cout << "   2. DEPOSIT" << std::endl;
  std::cout << "   3. WITHDRAW" << std::endl;
  std::cout << "   4. LOGOUT" << std::endl;
  while(check_choice) {
    try {
      std::cout << "choice: ";
      std::cin >> choice;
      if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        throw "ONLY NUMBER !!!";
      }
      if(choice < 1 || choice > 4) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        throw "CHOICE BETWEEN 1-4";
      }
      check_choice = 0;
    } catch(const char* s) {
      std::cout << std::endl << s << std::endl << std::endl;
    }
  }
  
  switch(choice) {
    case 1:
      if(player->get_credits() > 0) {
        game(player);
      } else {
        int check_h = 1;
        char h;
        std::cout << "Your credits is not enough to play slot" << std::endl;
        std::cout << "Type H for back to home" << std::endl;
        while(check_h) {
          try {
            std::cout << ": ";
            std::cin >> h;
            h = tolower(h);
            if(h != 'h') {
              std::cin.clear();
              std::cin.ignore(256, '\n');
              throw "ONLY H !!!";
            }
            check_h = 0;
          } catch(const char* s) {
            std::cout << std::endl << s << std::endl << std::endl;
          }
        }
      }
      home(player);
      break;
    case 2:
      deposit(player);
      home(player);
      break;
    case 3:
      withdraw(player);
      home(player);
      break;
  }
}