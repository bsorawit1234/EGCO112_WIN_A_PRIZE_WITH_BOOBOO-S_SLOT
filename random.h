int *random_slot() {
  int *random_num = new int[3];
  for(int i = 10; i >= 0; i--) {
    random_num[0] = rand() % 10;
    random_num[1] = rand() % 10;
    random_num[2] = rand() % 10;

    cout << "\r" << random_num[0] << random_num[1] << random_num[2]; // print the number with a carriage return to overwrite the previous number
    
    fflush(stdout); // flush the output buffer
    usleep(1000000 / i); // add a delay of 100ms between each frame
  }
  return random_num;
}

// // Rules
// int *random = random_slot();
// if(random[0] == random[1] && random[1] == random[2]) {
//   money *= 10;
// } else if(random[2] - random[1] == 1 && random[1] - random[0] == 1) {
//   money *= 5;
// } else if(random[2] - random[1] == -1 && random[1] - random[0] == -1) {
//   money *= 5;
// } else if(random[0] == random[2]) {
//   money *= 3;
// }