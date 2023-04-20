#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void print_slot(string s1, string s2, string s3) {
  system("clear");
  cout << "   SLOT " << endl;
  cout << " -------" << endl;
  cout << " |" << s1 << "|" << s2 << "|" << s3 << "|" << endl;
  cout << " -------" << endl;
  cout << " |     |" << endl;
  cout << " |     |" << endl;
}

int main() {
  string s1 = "-";
  string s2 = "-";
  string s3 = "-";

  print_slot(s1, s2, s3);

  for(int i = 0; i < 10; i++) {
    int n1 = rand() % 10;
    int n2 = rand() % 10;
    int n3 = rand() % 10;

    s1 = to_string(n1);
    s2 = to_string(n2);
    s3 = to_string(n3);

    fflush(stdout); // flush the output buffer
    usleep(100000);
    print_slot(s1, s2, s3);
  }
  
  return 0;
}