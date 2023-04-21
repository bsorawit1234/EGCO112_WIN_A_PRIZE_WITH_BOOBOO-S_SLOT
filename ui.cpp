#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <unistd.h>

using namespace std;

#include "ListUser.h"
#include "random.h"

int main(int argc, char *argv[]) {
    ListUser A; 
    string name;
    int flags;
    float money, bet;
    bool check_user;
    //User fill the information.
    for(int i = 1; i < argc; i+=2) {
        A.insert(argv[i], atof(argv[i+1]));
    }
    do{
        try {
            flags = 0;
            system("cls");
            cout << "User : ";
            getline(cin, name);
            cout << "\033[F";
            A.checkUser(name, bet);
        } catch(const char*& e) {
            flags = 1;
            cerr << e << endl;
        }
    } while(flags);




    
    return 0;
}