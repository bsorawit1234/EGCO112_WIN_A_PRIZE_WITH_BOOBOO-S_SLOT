#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <sstream>

#include <chrono>
#include <thread>  

using namespace std;

#include "ListUser.h"
#include "excep_tion.h"
#include "login_register.h"
#include "home.h"

void start(User &player) {
  int choose, check_choose = 1;
  int round=0;
  clear_screen();
  if(round==0){

  cout<<"*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--* "<<endl;
  cout<<"       WELCOME TO WIN A PRIZE WITH BOO BOO'S SLOT      "<<endl;
  cout<<"*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--* "<<endl;
  cout<<" "<<endl;
  cout<<"                   PRESS 1 TO REGISTER                "<<endl;
  cout<<"                   PRESS 2 TO LOGIN "<<endl;
  cout<<" "<<endl;
  cout<<"*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--* "<<endl;

  while(check_choose) {
    try {
      cout << "choose: ";
      cin >> choose;
      
      if(cin.fail()) {
        cin.clear();
        cin.ignore(256,'\n');
        throw "ONLY NUMBER !!";
      }

      if(choose < 1 || choose > 2) {
        throw "CHOOSE 1 OR 2";
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
  }
  }

  else{
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
  round++;
}

int main() {
  srand(time(NULL));

  this_thread::sleep_for(chrono::milliseconds(2000));
     
    cout << R"(
                    __    __  __  __  ___          _          __ ___   __  __   __  ______   __  __
                   |  |  |  ||  ||  \|   |        / \        |  |\   \|  |\  \'|  ||___  /  |  |\  \  
                   | '|/\| '|| '|| '|\  '|      '/  '\       |  '|/__/| '|/  / | '|   /'/__ |  _''>
                   |__,/\'__||__||__|'|__|      /_____\      |__|    '|__|'\__\|__|''/_____/|__|/__/  )" <<endl;

    this_thread::sleep_for(chrono::milliseconds(1200));

    cout << R"(
                                      __    __  __  ________  __    __
                                     |  |  |  ||  ||__    __||_ |  | _| 
                                     | '|/\| '|| '|   | '|  ' | ';=; |
                                     |__,/\'__||__|  '|__|'''|__|  |__| )" <<endl;


    this_thread::sleep_for(chrono::milliseconds(1200));

    cout << R"(
     __  __    ____     ____        __  __    ____     ____       ______       ______  __       ____    ________
    |  |\  \ /  /\  \'/  /\  \'    |  |\  \ /  /\  \'/  /\  \'   /  /\__\     /  /\__\|  |   '/  /\  \'|__    __|
    | '|( '(|  |  | '|| |  | '|    | '|( '(|  |  | '|| |  | '|  _\  \''      _\  \''  | '|__ |  |  | '|   | '| '
    |__|/__/ \__\/__/'\__\/__/'    |__|/__/ \__\/__/'\__\/__/' \__\/__/     \__\/__/  |_____| \__\/__/'  '|__|''  
    
     )" <<endl;
     
    this_thread::sleep_for(chrono::milliseconds(3000));

    clear_screen();


  User u1("boom", 5000, 5000); // for testing
  start(u1);
}
