#ifdef _WIN32
  #include <windows.h>
#else
  #include <unistd.h>
#endif

void msleep(int ms) {
  #ifdef _WIN32
    Sleep(ms);
  #else
    usleep(ms * 1000);
  #endif
}

void clear_screen() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void print_slot(std::string s1, std::string s2, std::string s3) {
  clear_screen();
  std::cout << "   -------" << std::endl;
  std::cout << "   |" << s1 << "|" << s2 << "|" << s3 << "|" << std::endl;
  std::cout << "   -------" << std::endl;
}

void check_result_slot(int n1, int n2, int n3, float &bet) {
  if(n1 == n2 && n2 == n3) { 
    bet *= 10;
  } else if(n3 - n2 == 1 && n2 - n1 == 1) {
    bet *= 5;
  } else if(n3 - n2 == -1 && n2 - n1 == -1) {
    bet *= 5;
  } else if(n1 == n3) {
    bet *= 3;
  } else 
    bet *= -1;
  
}

void slot_game(float bet, std::string s[], User *&player) {
  print_slot(s[0], s[1], s[2]);

  int n[3] = {rand() % 10, rand() % 10, rand() % 1};
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 10; j++) {
      n[i]++;
      if(n[i] == 10) n[i] = 0;
      s[i] = std::to_string(n[i]);
      
      print_slot(s[0], s[1], s[2]);
      std::cout << "Credits: " << player->get_credits() << std::endl;
      std::cout << "Bet amount: " << bet << std::endl;
      fflush(stdout);
      msleep(100); 
    }
  }
  
  check_result_slot(n[0], n[1], n[2], bet);
  player->bet(bet);

  clear_screen();
  print_slot(s[0], s[1], s[2]);
  std::cout << "Credits: " << player->get_credits() << std::endl;

  if(bet >= 0) {
    std::cout << std::endl << "Congrats! You got " << bet << "$" << std::endl;
  } else {
    std::cout << std::endl <<"Sorry! You lose " << bet*(-1) << "$" << std::endl;
  }
}

void game(User *&player) {
  int check_bet = 1, check_choice = 1;
  std::string s[3] = {"0", "0", "0"};
  print_slot(s[0], s[1], s[2]);
  std::cout << "Credits: " << player->get_credits() << std::endl;

  float bet;
  while(check_bet) {
    try {
      std::cout << "Bet amount: ";
      std::cin >> bet;
      if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        throw "ONLY NUMBER!";
      }
      if(player->get_credits() < bet) {
        throw "YOU DON'T HAVE ENOUGH CREDITS.";
      }
      check_bet = 0;
    } catch(char const* s) {
      std::cout << s << std::endl;
    }
  }

  slot_game(bet, s, player);

  char choice;
  if(player->get_credits() > 0) {
    while(check_choice) {
      try {
        std::cout << std::endl << "Do you want to play again?" << std::endl << "(Y/N): ";
        std::cin >> choice;
        choice = tolower(choice);
        if(choice != 'y' && choice != 'n') {
          std::cin.clear();
          std::cin.ignore(256, '\n');
          throw "ONLY Y AND N !!!";
        }
        check_choice = 0;
      } catch(const char* s) {
        std::cout << std::endl << s << std::endl;
      }
    }
    if(choice == 'y') game(player);
  } else {
    std::cout << std::endl << "Your credits is not enough to play slot" << std::endl;
    std::cout << "Type H for back to home" << std::endl;
    while(check_choice) {
      try {
        std::cout << ": ";
        std::cin >> choice;
        choice = tolower(choice);
        if(choice != 'h') {
          std::cin.clear();
          std::cin.ignore(256, '\n');
          throw "ONLY H !!!";
        }
        check_choice = 0;
      } catch(const char* s) {
        std::cout << std::endl << s << std::endl << std::endl;
      }
    }
  }
}