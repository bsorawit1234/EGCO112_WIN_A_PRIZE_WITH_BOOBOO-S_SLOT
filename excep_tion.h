class space : public exception {
    public : 
        virtual const char* what() const throw() {
            return "space isn't allowed.";
        }
};

class passwordmatch : public exception {
    public : 
        virtual const char* what() const throw() {
            return "password doesn't match.";
        }
};

class numonly : public exception {
    public :
        virtual const char* what() const throw() {
            return "only numbers are allowed.";
        }
};

void fill_info(const char *ask, string &fill) {
    space sp;
    int flag;
    do {
        flag = 0;
        try {
            cout << ask; getline(cin, fill);
            size_t found = fill.find(' ');
            if(found != string::npos) {
                throw sp;
            }
        } catch (space &e) {
            flag = 1;
            cout << e.what() << endl;
        }
    } while (flag);
}