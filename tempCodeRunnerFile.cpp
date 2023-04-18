  random_num[0] = rand() % 10;
      random_num[1] = rand() % 10;
      random_num[2] = rand() % 10;

      cout << "\r" << random_num[0] << random_num[1] << random_num[2]; // print the number with a carriage return to overwrite the previous number
      
      fflush(stdout); // flush the output buffer
      usleep(100000); // add a delay of 100ms between each frame
    }