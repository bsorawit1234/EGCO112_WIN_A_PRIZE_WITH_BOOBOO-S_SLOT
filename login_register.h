/*
              Total.txt
    username password money credits
*/

void login_register() {
    ListUser Players;
    string user, pass, repass, read_from_file, users, passe; 
    int choose = 1, flag;
    float money, Money, credits;
    const float STARTER_CREDITS = 20;
    space sp;
    passwordmatch pm;
    numonly nu;

    system("cls");
    switch(choose) {
        //register 
        case 1 : {
            ofstream opened;
            opened.open("Total.txt", fstream::app);
            opened.close();
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\tRegister" << endl;
            cout << "------------------------------------------------------------------------------------" << endl;

            do { // username that user entered has already been taken or not.
                flag = 0;
                fstream file("Total.txt");
                try {
                    fill_info("username : ", user); //fil_info for check user has space or not.
                    while(!file.eof()) {
                        getline(file, read_from_file);
                        istringstream ss(read_from_file);
                        ss >> users >> passe;
                        if(user == users) {
                            throw "username has already been taken.";
                        }
                    }
                } catch (const char *&e) {
                    flag = 1;
                    cout << e << endl;
                }
                file.close();
            } while (flag); 
            fill_info("password : ", pass);

            do { // check password = re-password ???
                flag = 0;
                try {
                    cout << "reenter password : "; getline(cin, repass);
                    cin.clear();
                    if( pass != repass ) {
                        throw pm;
                    }
                } catch (passwordmatch &e) { 
                    flag = 1;
                    cout << e.what() << endl;
                }
            } while (flag);

            do { //insert money.
                flag = 0;
                try {
                    cout << "money : "; cin >> money;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(256,'\n');
                        throw nu;
                    }
                } catch (numonly &e) {
                    flag = 1;
                    cout << e.what() << endl;
                }
            } while (flag);

            opened.open("Total.txt", fstream::app);
            opened << user << ' ' << pass << ' ' << money << ' ' << STARTER_CREDITS << endl;
            opened.close();

        } break;

        case 2 : {
            int count = 3; //if user entered username or password incorrect 3 times, program will terminate.
            bool user_correct;
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\tLogin" << endl;
            cout << "------------------------------------------------------------------------------------" << endl;
            do {
                fstream file("Total.txt");
                flag = 0;
                cout << "username : "; getline(cin, user);
                cout << "password : "; getline(cin, pass);

                while(!file.eof()) {
                    getline(file, read_from_file);
                    istringstream ss(read_from_file);
                    ss >> users >> passe;
                    if(users != user) {
                        if(!file.eof()) continue;
                        count--;
                        flag = 1;
                        cerr << "The username that you entered isn't connected to an account." << " (" << count << " times left)" << endl;
                    } else {
                        user_correct = true;
                        break;
                    }
                } if(user_correct) {
                    if(passe != pass) {
                        count--;
                        flag = 1;
                        cerr << "The password that you have entered is incorrect." << " (" << count << " times left)" << endl;
                    }
                }

                file.close();
                if(count == 0) exit(1);
            } while (flag);

        } break;

        default : cout << "eiei" << endl;
    }

    /* insert users in LL. */
    ifstream insert_ll("Total.txt");
    while(!insert_ll.eof()) {
        getline(insert_ll, read_from_file);
        if(read_from_file.length() == 0) continue;
        istringstream ss(read_from_file);
        ss >> users >> passe >> Money >> credits;
        Players.insert(users, Money, credits);
    }
    insert_ll.close();

}