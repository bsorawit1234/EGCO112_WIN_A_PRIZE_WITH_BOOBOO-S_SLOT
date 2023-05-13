class space : public std::exception {
    public : 
        virtual const char* what() const throw() {
            return "space isn't allowed.";
        }
};

class passwordmatch : public std::exception {
    public : 
        virtual const char* what() const throw() {
            return "password doesn't match.";
        }
};

class numonly : public std::exception {
    public :
        virtual const char* what() const throw() {
            return "only numbers are allowed.";
        }
};

class my_password : public std::exception {
    public : 
        virtual const char* what() const throw() {
            return "Password is at least 4 characters long.";
        }
};

class my_username : public std::exception {
    public : 
        virtual const char* what() const throw() {
            return "Username is at least 4 characters long.";
        }
};

class min_money : public std::exception {
    public : 
        virtual const char* what() const throw() {
            return "Minimum opening account $100.";
        }
};


void fill_info(const char *ask, std::string &fill) {
    space sp;
    int flag;
    do {
        flag = 0;
        try {
            std::cout << ask; 
            getline(std::cin, fill);
            size_t found = fill.find(' ');
            if(found != std::string::npos) {
                throw sp;
            }
            if(ask == "username : ") {
                if(fill.length() < 4) {
                    my_username mu;
                    throw mu;
                }
            } else if(ask == "password : ") {
                if(fill.length() < 4) {
                    my_password mp;
                    throw mp;
                }
            }
        } catch (space &e) {
            flag = 1;
            std::cout << e.what() << std::endl;
        } catch (my_username &e) {
            flag = 1;
            std::cout << e.what() << std::endl;
        } catch (my_password &e) {
            flag = 1;
            std::cout << e.what() << std::endl;
        }

    } while (flag);
}

