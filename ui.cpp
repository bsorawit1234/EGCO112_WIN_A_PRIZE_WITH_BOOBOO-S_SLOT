#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

#include "ListUser.h"
#include "random.h"

int main(int argc, char *argv[]) {
    ListUser A; 
    string name;
    float money, bet;
    bool check_user;
    //User fill the information.
    for(int i = 1; i < argc; i+=2) {
        A.insert(argv[i], atof(argv[i+1]));
    }
    system("cls");
    cout << "User : ";
    getline(cin, name);
    cout << "\033[F";
    check_user = A.checkUser(name);
    if(check_user == true) {
        cout << "Bet Amount : ", cin >> bet;
        cin.clear();
        cout << "\033[F";
        cout << "Bet Amount : " << bet << " $" << endl;
    } else {
        cerr << "Username is invalid." << endl;
    }





    
    return 0;
}