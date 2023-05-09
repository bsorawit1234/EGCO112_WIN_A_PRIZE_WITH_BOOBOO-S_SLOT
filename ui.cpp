#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <unistd.h>

using namespace std;

#include "ListUser.h"

int main(int argc, char *argv[]) {
    ListUser A; 
    User *pointer_for_insert_bet;  
    string name;
    int flags; 
    float money, bet;
    bool check_user;
    //User fill the information.
    for(int i = 1; i < argc; i+=2) {
        A.insert(argv[i], atof(argv[i+1]));
    } 
    cout << "----------------------------------" << endl;
    do{
        try {
            flags = 0;
            cout << "User : ";
            getline(cin, name);
            cout << "\033[F";
            pointer_for_insert_bet = A.checkUser(name);
            pointer_for_insert_bet->insert_bet(bet);
        } catch(const char*& e) {
            flags = 1;
            cerr << e << endl;
        }
    } while(flags);
    cout << "End program." << endl;
    int round=0;

    /*while(a){
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
    }*/


    
    return 0;
}