#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std;

#include "ListUser.h"
// #include "random.h"

int *random_slot() {
  int *random_num = new int[3];
  for(int i = 10; i >= 0; i--) {
    random_num[0] = rand() % 10;
    random_num[1] = rand() % 10;
    random_num[2] = rand() % 10;

    cout << "\r" << random_num[0] << random_num[1] << random_num[2]; // print the number with a carriage return to overwrite the previous number
    
    fflush(stdout); // flush the output buffer
    // usleep(1000000 / i); // add a delay of 100ms between each frame
    sleep(i/10);
  }
  return random_num;
}

int main() {
  srand(time(NULL));
  int money = 10;
  
  for(int i = 0; i < 10; i++) {
    int *random = random_slot();
    if(random[0] == random[1] && random[1] == random[2]) { // same number
      money *= 10;
    } else if(random[2] - random[1] == 1 && random[1] - random[0] == 1) { // sequence
      money *= 5;
    } else if(random[2] - random[1] == -1 && random[1] - random[0] == -1) { // sequence
      money *= 5;
    } else if(random[0] == random[2]) { // palindrome
      money *= 3;
    }

    cout << endl << "money: " << money << endl;
  }

}