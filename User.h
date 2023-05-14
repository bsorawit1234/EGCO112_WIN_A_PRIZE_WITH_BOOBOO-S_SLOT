class User {
  protected:
    float money;
    float credits;
  public:
    std::string name;
    std::string USER = "";
    User* next;

    User(std::string = "Tee", float = 0, float = 0);
    virtual ~User();
    virtual std::string get_rank();
    void withdraw(float);
    virtual void deposit(float);
    float get_credits() { return credits; }
    float get_money() { return money; }
    void bet(float);
    virtual void topup(float);
    void insert(User *);
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

void User::insert(User *x) {
  x->next = this;
}

std::string User::get_rank() {
  return USER;
}

class VIP: public User {
  public :
    std::string vip = "[VIP]";
    void deposit(float d) {
      if(money >= d) {
        credits += d*1.1;
        money -= d;
      }
    }
    std::string get_rank() {
      return vip;
    }
    VIP(std::string, float = 0, float = 0);
    ~VIP();
};

VIP::VIP(std::string n, float m, float c) : User(n, m, c) {
  name = n;
  money = m;
  credits = c;
  next = nullptr;

  std::cout << "Create User(VIP) success" << std::endl;
  std::cout << "name    : " << name << std::endl;
  std::cout << "money   : $" << money << std::endl;
  std::cout << "credits : $" << credits << std::endl;
}

VIP::~VIP() {
  std::cout << name << "(VIP) has been logged out." << std::endl;
}
