//
// Created by ray on 05.10.2024.
//
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include "helpers.h"

const std::string records_file = "records.txt";

int main() {

  char answer = 0;

  std::srand(std::time(nullptr));
  std::cout << "\"Guess the number game\"" << std::endl;

  std::cout << "Enter your username:" << std::endl;
  std::string username;
  std::cin >> username;
  std::fstream records_filestream = get_records_file(records_file);
  records_filestream = print_last_result(records_filestream, username);

  std::cout << "Created number in range from 1 to 100. Guess it!" << std::endl << std::endl;

  while (answer!='N' && answer!='n') {
	int enigma = (std::rand()%100) + 1;

	int guess = 0;

	do {
	  check_guess(guess, enigma);
	} while (enigma!=guess);

	std::cout << "Excellent! Any more? (Y/N)" << std::endl;
	std::cout << "& ";
	std::cin >> answer;
  }
  std::cout << "Good by!" << std::endl;

  return 0;
}