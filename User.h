class User {
  protected:
    float money;
    float credits;
  public:
    std::string name;
    User* next;

    User(std::string = "Tee", float = 0, float = 0);
    ~User();
    void withdraw(float);
    virtual void deposit(float);
    float get_credits() { return credits; }
    float get_money() { return money; }
    void bet(float);
    void topup(float);
};

User::User(std::string n, float m, float c) {
  name = n;
  money = m;
  credits = c;
  next = nullptr;

  std::cout << "Create User success" << std::endl;
  std::cout << "name    : " << name << std::endl;
  std::cout << "money   : $" << money << std::endl;
  std::cout << "credits : $" << credits << std::endl;
}

User::~User() {
  std::cout << name << " has been logged out." << std::endl;
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

void User::topup(float t) {
  money += t;
}

class VIP: public User {
  virtual void deposit(float d) {
    if(money >= d) {
      credits += d*1.1;
      money -= d;
    }
  }
};