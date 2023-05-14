/*
            Total.txt
    username password money credits
*/
std::string login_register(int choose) {
    ListUser Players;
    User *for_return;
    std::string user, pass, repass, read_from_file, users, passe; 
    const std::string USER = "user", VIP = "vip";
    int flag;
    float money, Money, credits, credit;
    const float STARTER_CREDITS = 20;
    space sp;
    passwordmatch pm;
    numonly nu;
    min_money mm;
    
    std::cin.clear();
    std::cin.ignore(256,'\n');
    // system("cls||clear");
    switch(choose) {
        //register 
        case 1 : {
            std::ofstream opened;
            opened.open("Total.txt", std::fstream::app);
            opened.close();
            std::cout << "*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*" << std::endl;
            std::cout << "                        Register" << std::endl;
            std::cout << "*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*" << std::endl;

            do { // username that user entered has already been taken or not.
                flag = 0;
                std::ifstream file("Total.txt");
                try {
                    fill_info("username : ", user); //fil_info for check user has space or not.
                    while(!file.eof()) {
                        getline(file, read_from_file);
                        std::istringstream ss(read_from_file);
                        ss >> users >> passe;
                        if(user == users) {
                            throw "username has already been taken.";
                        }
                    }
                } catch (const char *&e) {
                    flag = 1;
                    std::cout << e << std::endl;
                }
                file.close();
            } while (flag); 
            fill_info("password : ", pass);

            do { // check password = re-password ???
                flag = 0;
                try {
                    std::cout << "re-enter password : "; getline(std::cin, repass);
                    std::cin.clear();
                    if( pass != repass ) {
                        throw pm;
                    }
                } catch (passwordmatch &e) { 
                    flag = 1;
                    std::cout << e.what() << std::endl;
                }
            } while (flag);

            do { //insert money.
                flag = 0;
                try {
                    std::cout << "money : "; std::cin >> money;
                    if(std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        throw nu;
                    }
                    if(money < 100) {
                        std::cin.clear();
                        std::cin.ignore(256, '\n');
                        throw mm;
                    }
                } catch (numonly &e) {
                    flag = 1;
                    std::cout << e.what() << std::endl;
                } catch (min_money &e) {
                    flag = 1;
                    std::cout << e.what() << std::endl;
                }
            } while (flag);
            opened.open("Total.txt", std::fstream::app);
            opened << user << ' ' << pass << ' ' << money << ' ' << STARTER_CREDITS << ' ' << USER << std::endl;
            opened.close();

        } break;

        case 2 : {
            int count = 3; //if user entered username or password incorrect 3 times, program will terminate.
            bool user_correct;

            std::cout << "*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*" << std::endl;
            std::cout << "                          Login" << std::endl;
            std::cout << "*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*-*-*--*-*--*" << std::endl;
            do {
                std::fstream file("Total.txt");
                flag = 0;
                std::cout << "username : "; std::getline(std::cin, user);
                std::cout << "password : "; std::getline(std::cin, pass);

                while(!file.eof()) {
                    std::getline(file, read_from_file);
                    std::istringstream ss(read_from_file);
                    ss >> users >> passe;
                    user_correct = false;
                    if(users != user) {
                        if(!file.eof()) continue;
                        count--;
                        flag = 1;
                        std::cerr << "The username that you entered isn't connected to an account." << " (" << count << " times left)" << std::endl;
                    } else {
                        user_correct = true;
                        break;
                    }
                } 

                if(user_correct) {
                    if(passe != pass) {
                        count--;
                        flag = 1;
                        std::cerr << "The password that you have entered is incorrect." << " (" << count << " times left)" << std::endl;
                    }
                }

                file.close();
                if(count == 0) exit(1);
            } while (flag);
        } break;

    }

    return user;
}