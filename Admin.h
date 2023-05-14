// #include "User.h"

void admin_page(ListUser A) {
  int choice, check_choice = 1;
  std::string name;
  User* temp;
  std::string for_read, for_write, target, pass, ranks, m, c, rank;
  std::ifstream read("Total.txt");
  std::ofstream write;

  system("@cls||clear");
  std::cout << "-------- ADMIN ---------" << std::endl;
  std::cout << "     1. GIVE MONEY" << std::endl;
  std::cout << "     2. GIVE VIP" << std::endl;
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

      if(choice != 1 && choice != 2) {
        throw "CHOOSE BETWEEN 1 AND 2";
      }
      check_choice = 0;
    } catch(const char* s) {
      std::cout << std::endl << s << std::endl << std::endl;
    }
  }
  
  if(choice == 1) {
    std::cout << "Who do you want to give money: ";
    std::getline(std::cin, name);
    
    float m;
    int check_m = 1;
    
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
        check_choice = 0;
      } catch(const char* s) {
        std::cout << std::endl << s << std::endl << std::endl;
      }
    }

    A.find_node(name)->topup(m);
  }

  if(choice == 2) {
    //change class. 
    std::cout << "Who do you want to give VIP: " << std::endl;
    std::getline(std::cin, name);
    
    temp = A.find_node(name);
    A.class_changes(temp);

    write.open("Total2.txt", std::fstream::app);
    while(!read.eof()) {
      std::getline(read, for_read);
      if(for_read.length() == 0) continue;
      std::istringstream ss(for_read);
      ss >> target >> pass >> m >> c >> rank;
      if(target == temp->name) {
        write << target << ' ' << pass << ' ' << m << ' ' << c << ' ' << "vip" << std::endl;
      } else {
        write << for_read << std::endl;
      }
    }
    write.close();
    read.close();
    remove("Total.txt");
    rename("Total2.txt", "Total.txt");
  }

}