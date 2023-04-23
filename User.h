class User {
  private:
    float credits;
    float money;
    float bet;
  public:
    string name;
    User* next;

    User(string, float);

    void withdraw(float);
    void deposit(float);
    int bet();
    void bet_amount(float);
    void display_credits(){
      cout << credits;
    }
    float show_credits() {
      return credits; 
    }
};

User::User(string n, float m) {
  name = n;
  money = m;
  credits = 20;
  next = NULL;

  cout << "Create User success" << endl;
  cout << "name : " << name << endl;
  cout << "money: " << money << endl;
}

void User::withdraw(float w) {
  if(credits > 0 && credits >= w) {
    credits -= w;
    money += w;

    cout << name << " withdraw money: " << w << endl;
    cout << "Credits: " << credits << endl;
    cout << "Money  : " << money << endl;
  }
}

void User::deposit(float d) {
  if(money >= d) {
    credits += d;
    money -= d;

    cout << name << " deposit money: " << d << endl;
    cout << "Credits: " << credits << endl;
    cout << "Money  : " << money << endl;
  }
}

int User::bet(float b){
  bet=b;
  credits -= b;\

  cout<<"Credit : "<<credits<<"$"<<endl;
  return credits;
}


void User::bet_amount()

