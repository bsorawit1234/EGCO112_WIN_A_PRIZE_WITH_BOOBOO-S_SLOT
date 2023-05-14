// #include "User.h"

void admin_page(ListUser A) {
  int choice = 2;
  std::string name = "boom";
  User* temp;
  std::string for_read, for_write, target, pass, ranks, m, c, rank;
  std::ifstream read("Total.txt");
  std::ofstream write;

  system("@cls||clear");
  std::cout << "-------- ADMIN ---------" << std::endl;
  std::cout << "  1. TOPUP" << std::endl;
  std::cout << "  2. GIVE VIP" << std::endl;
  std::cout << "-----------------------" << std::endl;
  std::cout << "CHOICE: " << std::endl;

  if(choice == 2) {
    //change class. 
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