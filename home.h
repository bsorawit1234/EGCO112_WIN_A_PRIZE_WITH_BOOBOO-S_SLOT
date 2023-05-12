#include "game.h"

void status(User &player) {
  clear_screen();
  cout << "-------- HOME ---------" << endl;
  cout << "  User    : " << player.name << endl;
  cout << "  Money   : " << player.get_money() << endl;
  cout << "  Credits : " << player.get_credits() << endl;
  cout << "-----------------------" << endl;
}

void deposit(User &player) {
  status(player);
  int check_d = 1, check_m = 1;
  char m;
  float d;
  cout << "        DEPOSIT" << endl;
  cout << "How much do you want to deposit?" << endl;
  while(check_d) {
    try {
      cout << ": ";
      cin >> d;
      if(cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        throw "ONLY NUMBER!!!";
      }
      if(d > player.get_money()) {
        cin.clear();
        cin.ignore(256, '\n');
        throw "You don't have enough money to deposit";
      }
      check_d = 0;
    } catch(const char* s) {
      cout << endl << s << endl << endl;
    }
  }

  player.deposit(d);
  status(player);
  cout << endl << player.name << " deposited " << d << "$" << endl;
  
  if(player.get_money() == 0) return;
  cout << endl << "Do you want to deposit more?" << endl;
  while(check_m) {
    try {
      cout << "(Y/N) : ";
      cin >> m;
      m = tolower(m);
      if(m != 'y' && m != 'n') {
        cin.clear();
        cin.ignore(256, '\n');
        throw "ONLY Y AND N !!!";
      }
      check_m = 0;
    } catch(const char* s) {
      cout << endl << s << endl;
    }
  }
  if(m == 'y') {
    deposit(player);
  }
}

void withdraw(User &player) {
  status(player);
  int check_w = 1, check_m = 1;
  char m;
  float w;
  cout << "        WITHDRAW" << endl;
  cout << "How much do you want to withdraw?" << endl;
  while(check_w) {
    try {
      cout << ": ";
      cin >> w;
      if(cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        throw "ONLY NUMBER!!!";
      }
      if(w > player.get_credits()) {
        cin.clear();
        cin.ignore(256, '\n');
        throw "You don't have enough credits to withdraw";
      }
      check_w = 0;
    } catch(const char* s) {
      cout << endl << s << endl << endl;
    }
  }

  player.withdraw(w);
  status(player);
  cout << endl << player.name << " withdrew " << w << "$" << endl;
  
  if(player.get_credits() == 0) return;
  cout << endl << "Do you want to withdraw more?" << endl;
  while(check_m) {
    try {
      cout << "(Y/N) : ";
      cin >> m;
      m = tolower(m);
      if(m != 'y' && m != 'n') {
        cin.clear();
        cin.ignore(256, '\n');
        throw "ONLY Y AND N !!!";
      }
      check_m = 0;
    } catch(const char* s) {
      cout << endl << s << endl;
    }
  }
  if(m == 'y') {
    withdraw(player);
  }
}

void home(User &player) {
  int choice, check_choice = 1;
  status(player);
  cout << "   1. PLAY" << endl;
  cout << "   2. DEPOSIT" << endl;
  cout << "   3. WITHDRAW" << endl;
  cout << "   4. LOGOUT" << endl;
  while(check_choice) {
    try {
      cout << "choice: ";
      cin >> choice;
      if(cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        throw "ONLY NUMBER !!!";
      }
      if(choice < 1 || choice > 4) {
        cin.clear();
        cin.ignore(256, '\n');
        throw "CHOICE BETWEEN 1-4";
      }
      check_choice = 0;
    } catch(const char* s) {
      cout << endl << s << endl << endl;
    }
  }
  
  switch(choice) {
    case 1:
      if(player.get_credits() > 0) {
        game(player);
      } else {
        int check_h = 1;
        char h;
        cout << "Your credits is not enough to play slot" << endl;
        cout << "Type H for back to home" << endl;
        while(check_h) {
          try {
            cout << ": ";
            cin >> h;
            h = tolower(h);
            if(h != 'h') {
              cin.clear();
              cin.ignore(256, '\n');
              throw "ONLY H !!!";
            }
            check_h = 0;
          } catch(const char* s) {
            cout << endl << s << endl << endl;
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