class User {
  private:
    float money;
    float credits;
  public:
    string name;
    User* next;

    User(string = "Tee", float = 0, float = 0);
    ~User();
    void withdraw(float);
    void deposit(float);
    float get_credits() { return credits; }
    float get_money() { return money; }
    void bet(float);
};

User::User(string n, float m, float c) {
  name = n;
  money = m;
  credits = c;
  next = nullptr;

  cout << "Create User success" << endl;
  cout << "name    : " << name << endl;
  cout << "money   : $" << money << endl;
  cout << "credits : $" << credits << endl;
}

User::~User() {
  cout << name << " has been logged out." << endl;
}

void User::withdraw(float w) {
  if(credits > 0 && credits >= w) {
    credits -= w;
    money += w;
  }
}

void User::deposit(float d) {
  if(money >= d) {
    credits += d;
    money -= d;
  }
}

void User::bet(float b) {
  credits += b;
}

