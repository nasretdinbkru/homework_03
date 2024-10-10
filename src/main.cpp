//
// Created by ray on 05.10.2024.
//
#include <iostream>
#include <ctime>
#include <cstdlib>

#include <vector>
#include <string>
#include "helpers.h"

int main() {

  char answer = 0;
  setlocale(LC_ALL, "Russian");

  std::srand(std::time(nullptr));
  std::cout << "\"Guess the number game\"" << std::endl;
  std::vector<std::string> user_records;
  user_records = read_records();

  std::cout << "Created number in range from 1 to 100. Guess it!" << std::endl << std::endl;

  while (answer!='N' && answer!='n') {
	int enigma = (std::rand()%100) + 1;

	int guess = 0;

	do {
	  check_guess(guess, enigma);
	} while (enigma!=guess);

	std::cout << "Верно! Загадать еще число? (Y/N)" << std::endl;
	std::cout << "& ";
	std::cin >> answer;
  }
  std::cout << "До свидания!" << std::endl;

  return 0;
}