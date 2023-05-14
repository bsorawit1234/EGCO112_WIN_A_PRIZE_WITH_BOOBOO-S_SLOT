// #include "User.h"

void admin_page(ListUser A) {
  system("@cls||clear");
  std::string password;
  std::cout << "-------- ADMIN ---------" << std::endl;
  std::cout << "PASSWORD: ";
  std::cin.clear();
  std::cin.ignore(256, '\n');
  std::getline(std::cin, password);

  if(password != "1234") return;

  int choice, check_choice = 1;
  std::string name;
  User* temp;
  bool flag = true;
  std::string for_read, for_write, userss, target, pass, ranks, m, c, rank;
  std::ifstream read("Total.txt");
  std::ofstream write;

  system("@cls||clear");
  std::cout << "-------- ADMIN ---------" << std::endl;
  std::cout << "     1. GIVE MONEY" << std::endl;
  std::cout << "     2. GIVE VIP" << std::endl;
  std::cout << "     3. BACK HOME" << std::endl;
  std::cout << "------------------------" << std::endl;

  while(check_choice) {
    try {
      std::cout << "CHOICE: ";
      std::cin >> choice;

      if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        throw "ONLY NUMBER !!";
      }

      if(choice < 1 || choice > 3) {
        throw "CHOOSE BETWEEN 1-3";
      }
      check_choice = 0;
    } catch(const char* s) {
      std::cout << std::endl << s << std::endl << std::endl;
    }
  }
  
  if(choice == 1) {
    float m;
    int check_m = 1;
    
    std::cin.clear();
    std::cin.ignore(256,'\n');

    do {     
      try {
        std::cout << "Who do you want to give money: ";
        std::getline(std::cin, name);
        std::ifstream check_name("Total.txt"); 
        while(!check_name.eof()) {
          std::getline(check_name, for_read);
          std::istringstream ss(for_read);
          ss >> userss;
          if(userss == name) {
            flag = false;
          }
        }
        if(flag) throw "username doesn't exist.";
      } catch(const char*& e) {
        std::cout << e << std::endl;
      }
    } while(flag);
     
    while(check_m) {
      try {
        std::cout << "How much money: ";
        std::cin >> m;

        if(std::cin.fail()) {
          std::cin.clear();
          std::cin.ignore(256,'\n');
          throw "ONLY NUMBER !!";
        }
        if(m < 100) {
          throw "MINIMUM MONEY IS $100";
        }
        check_m = 0;
      } catch(const char* s) {
        std::cout << std::endl << s << std::endl << std::endl;
      }
    }
    temp = A.find_node(name);
    temp->topup(m);
    
  }

  if(choice == 2) {
    //change class. 

    std::cin.clear();
    std::cin.ignore(256,'\n');

    do {     
      try {
        std::cout << "Who do you want to give VIP: ";
        std::getline(std::cin, name);
        std::ifstream check_name("Total.txt"); 
        while(!check_name.eof()) {
          std::getline(check_name, for_read);
          std::istringstream ss(for_read);
          ss >> userss;
          if(userss == name) {
            flag = false;
          }
        }
        if(flag) throw "username doesn't exist.";
      } catch(const char*& e) {
        std::cout << e << std::endl;
      }
    } while(flag);
    temp = A.find_node(name);
    A.class_changes(temp);

  }

  write.open("Total2.txt", std::fstream::app);
  while(!read.eof()) {
    std::getline(read, for_read);
    if(for_read.length() == 0) continue;
    std::istringstream ss(for_read);
    ss >> target >> pass >> m >> c >> rank;
    if(target == temp->name) {
      if(choice == 2) write << target << ' ' << pass << ' ' << m << ' ' << c << ' ' << "vip" << std::endl; 
      else write << target << ' ' << pass << ' ' << temp->get_money() << ' ' << c << ' ' << rank << std::endl; 
    } else {
      write << for_read << std::endl;
    }
  }

  write.close();
  read.close();
  remove("Total.txt");
  rename("Total2.txt", "Total.txt");
  
  if(choice == 3) return;
}