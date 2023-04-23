#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

#include "ListUser.h"
#include "User.h"

int main(int argc, char *argv[]) {
    ListUser A; 
    User B;
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
    

     int round=0;

     while(a){
        round++;
        if(round==1){
            B.bet();
        }
        if(round>1){
            check_result_slot(n[0], n[1], n[2], money);
            bet_amount();
        }
        print_slot(n[0], n[1], n[2], bet);
        check_credit(n[0], n[1], n[2], bet);
        cout<<
     }



    



    
    return 0;
}