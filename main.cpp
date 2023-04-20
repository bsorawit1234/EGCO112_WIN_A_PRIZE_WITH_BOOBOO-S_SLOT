#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

#include "ListUser.h"
#include "random.h"

void print_slot(string s1, string s2, string s3) {
  system("clear");
  cout << "   SLOT " << endl;
  cout << " -------" << endl;
  cout << " |" << s1 << "|" << s2 << "|" << s3 << "|" << endl;
  cout << " -------" << endl;
}

void check_result_slot(int n1, int n2, int n3, int &money) {
  if(n1 == n2 && n2 == n3) { 
    money *= 10;
  } else if(n3 - n2 == 1 && n2 - n1 == 1) {
    money *= 5;
  } else if(n3 - n2 == -1 && n2 - n1 == -1) {
    money *= 5;
  } else if(n1 == n3) {
    money *= 3;
  }
}

int main() {
  srand(time(NULL));
  int money = 10;
  string s[3] = {"0", "0", "0"};

  print_slot(s[0], s[1], s[2]);

  for(int k = 0; k < 5; k++) {
    int n[3] = {rand() % 10, rand() % 10, rand() % 10};
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 10; j++) {
        n[i]++;
        if(n[i] == 10) n[i] = 0;
        s[i] = to_string(n[i]);
        
        print_slot(s[0], s[1], s[2]);

        fflush(stdout);
        usleep(100000);
      }
    }

    check_result_slot(n[0], n[1], n[2], money);
  }
  cout << endl << "money: " << money << endl;



}