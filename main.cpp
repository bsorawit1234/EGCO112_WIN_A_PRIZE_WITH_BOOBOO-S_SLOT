#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

#include "ListUser.h"
#include "random.h"

int main() {
  srand(time(NULL));
  int money = 10;
  
  for(int i = 0; i < 10; i++) {
    int *random = random_slot();
    if(random[0] == random[1] && random[1] == random[2]) {
      money *= 10;
    } else if(random[2] - random[1] == 1 && random[1] - random[0] == 1) {
      money *= 5;
    } else if(random[2] - random[1] == -1 && random[1] - random[0] == -1) {
      money *= 5;
    } else if(random[0] == random[2]) {
      money *= 3;
    }

    cout << endl << "money: " << money << endl;
  }

}