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

void print_slot(string s1, string s2, string s3) {
  clear_screen();
  cout << "   -------" << endl;
  cout << "   |" << s1 << "|" << s2 << "|" << s3 << "|" << endl;
  cout << "   -------" << endl;
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
  } else {
    bet *= -1;
  }
}

void slot_game(float bet, string s[], User &player) {
  print_slot(s[0], s[1], s[2]);

  int n[3] = {rand() % 10, rand() % 10, rand() % 10};
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 10; j++) {
      n[i]++;
      if(n[i] == 10) n[i] = 0;
      s[i] = to_string(n[i]);
      
      print_slot(s[0], s[1], s[2]);
      cout << "Credits: " << player.get_credits() << endl;
      cout << "Bet amount: " << bet << endl;
      fflush(stdout);
      msleep(100); 
    }
  }
  
  check_result_slot(n[0], n[1], n[2], bet);
  player.bet(bet);

  clear_screen();
  print_slot(s[0], s[1], s[2]);
  cout << "Credits: " << player.get_credits() << endl;

  if(bet >= 0) {
    cout << endl << "Congrats! You got " << bet << "$" << endl;
  } else {
    cout << endl <<"Sorry! You lose " << abs(bet) << "$" << endl;
  }
}

void game(User &player) {
  int check_bet = 1, check_choice = 1;
  string s[3] = {"0", "0", "0"};
  print_slot(s[0], s[1], s[2]);
  cout << "Credits: " << player.get_credits() << endl;

  float bet;
  while(check_bet) {
    try {
      cout << "Bet amount: ";
      cin >> bet;
      if(cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        throw "ONLY NUMBER!";
      }
      if(player.get_credits() < bet) {
        throw "YOU DON'T HAVE ENOUGH CREDITS.";
      }
      check_bet = 0;
    } catch(char const* s) {
      cout << s << endl;
    }
  }

  slot_game(bet, s, player);

  char choice;
  if(player.get_credits() > 0) {
    while(check_choice) {
      try {
        cout << endl << "Do you want to play again?" << endl << "(Y/N): ";
        cin >> choice;
        choice = tolower(choice);
        if(choice != 'y' && choice != 'n') {
          cin.clear();
          cin.ignore(256, '\n');
          throw "ONLY Y AND N !!!";
        }
        check_choice = 0;
      } catch(const char* s) {
        cout << endl << s << endl;
      }
    }
    if(choice == 'y') game(player);
  } else {
    cout << endl << "Your credits is not enough to play slot" << endl;
    cout << "Type H for back to home" << endl;
    while(check_choice) {
      try {
        cout << ": ";
        cin >> choice;
        choice = tolower(choice);
        if(choice != 'h') {
          cin.clear();
          cin.ignore(256, '\n');
          throw "ONLY H !!!";
        }
        check_choice = 0;
      } catch(const char* s) {
        cout << endl << s << endl << endl;
      }
    }
  }
}