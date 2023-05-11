#include "User.h"


void home(User &player) {
  int choice;
  do {
    // system("@cls||clear");
    cout << "---- HOME ----" << endl;
    cout << "User: " << player.name << endl;
    cout << "1. PLAY" << endl;
    cout << "2. DEPOSIT" << endl;
    cout << "3. WITHDRAW" << endl;
    cout << "4. LOGOUT" << endl;
    cout << "choice: ";
    cin >> choice;
  } while(choice < 1 || choice > 4);
  
  switch(choice) {
    case 1:
      // play();
      break;
    case 2:
      // deposit
      float d;
      cout << "---- DEPOSIT ----" << endl;
      cout << "How much do you want to deposit: ";
      cin >> d;
      player.deposit(d);
      home(player);
      break;
    case 3:
      // withdraw();
      float w;
      cout << "---- WITHDRAW ----" << endl;
      cout << "How much do you want to withdraw: ";
      cin >> w;
      player.withdraw(w);
      home(player);
      break;
    case 4:
      // logout();
      break;
    default:
      cout << "eiei" << endl;
  }
}