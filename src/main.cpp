//
// Created by ray on 05.10.2024.
//
#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>

int main() {

  char answer = 0;
  setlocale(LC_ALL, "Russian");
  std::srand(std::time(nullptr));
  std::cout << "\"Угадай число\"" << std::endl;
  std::cout << "Загадано число от 1 до 100. Угадай его!" << std::endl << std::endl;

  do {
	int n = (std::rand()%100) + 1;

	int guess = 0;

	do {
	  std::cout << "Введите число:" << std::endl;
	  std::cout << "$ ";
	  std::cin >> guess;

	  if (std::cin.fail() || (guess <= 0 || guess > 100)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите натуральное число от 1 до 100!" << std::endl;
		continue;
	  }

	  if (n > guess) {
		std::cout << "Загаданное число больше." << std::endl;
	  } else if (n < guess) {
		std::cout << "Загаданное число меньше." << std::endl;
	  }
	} while (n!=guess);

	std::cout << "Верно! Загадать еще число? (Y/N)" << std::endl;
	std::cout << "& ";
	std::cin >> answer;
  } while (answer != 'N' && answer != 'n');
  std::cout << "До свидания!" << std::endl;

  return 0;
}