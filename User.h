class User {
  private:
    float credits;
    float money;
    float bet;
  public:
    string name;
    User* next;

    User(string = "Tee", float = 0);
    ~User();
    void withdraw(float);
    void deposit(float);
    void bet_amount(float);
    void display_credits(){
      cout << credits;
    }
    float show_credits() {
      return credits; 
    }
    void insert_bet(float &);
};

User::User(string n, float m) {
  name = n;
  money = m;
  credits = 20;
  next = NULL;

  cout << "Create User success" << endl;
  cout << "name : " << name << endl;
  cout << "money: $" << money << endl;
}

User::~User() {
  cout << name << " has been logged out." << endl;
}

void User::withdraw(float w) {
  if(credits > 0 && credits >= w) {
    credits -= w;
    money += w;

    cout << name << " withdraw money: $" << w << endl;
    cout << "Credits: $" << credits << endl;
    cout << "Money  : $" << money << endl;
  }
}

void User::deposit(float d) {
  if(money >= d) {
    credits += d;
    money -= d;

    cout << name << " deposit money: " << d << endl;
    cout << "Credits: $" << credits << endl;
    cout << "Money  : $" << money << endl;
  }
}

void User::bet_amount(float b){
  bet = b;
  credits -= b;

  cout<<"Credit : "<<credits<<"$"<<endl;
  //return credits;
}

void User::insert_bet(float &bet_amountt) {
  User *t;
  int flags;
  float deposit;
  char yes_or_no;
  try{
    cout << "Bet Amount : ";
    cin >> bet_amountt;
    cin.clear();
    cout << "\033[F\033[K";
    cout << "Bet Amount : " << '$' << bet_amountt << endl;
    if(bet_amountt > t->show_credits()) {
      cout << "You have insufficient credit." << endl;
      do {
        flags = 0;
        cout << "Do you want to deposit money?(Y/N) ";
        cin >> yes_or_no;
        cin.clear();
        if(yes_or_no == 'y' || yes_or_no == 'Y') {
          /* add credits */
          cout << "How much credit do you want to deposit? : ";
          cin >> deposit;
          cin.clear();
          t->deposit(deposit);
        } else if(yes_or_no == 'n' || yes_or_no == 'N') {
          /* exit program */
          for(int i = 0; i < 2; i++) {
            cout << "\033[F\033[K"; /* clear 2 lines before error message. */
          }
          throw "You have insufficient credits.";
        } else {
          flags = 1;
        }
      } while(flags);
    } else {
      t->bet_amount(bet_amountt);
    }
  } catch(const char* e) {
    cout << e << endl;
  }
  
}

