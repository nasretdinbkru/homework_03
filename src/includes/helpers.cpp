//
// Created by ray on 10.10.2024.
//
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <fstream>

void check_guess(int &guess, int &enigma) {
  std::cout << "Enter number:" << std::endl;
  std::cout << "$ ";
  std::cin >> guess;

  if (std::cin.fail() || (guess <= 0 || guess > 100)) {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter natural number from 1 to 100!" << std::endl;
	return;
  }

  if (enigma > guess) {
	std::cout << "Загаданное число больше." << std::endl;
  } else if (enigma < guess) {
	std::cout << "Загаданное число меньше." << std::endl;
  }
}

std::vector<std::string> read_records() {
  const std::string RECORDS = "records.txt";
  std::fstream records{RECORDS};

  if (!records) {
	std::cout << "Record file not found";
	std::ofstream tmp(RECORDS, std::ostream::out);
	tmp.close();
  }
  records.open(RECORDS, std::fstream::in | std::fstream::out | std::fstream::app);
  std::vector<std::string> user_records;
  while (records) {
	std::string new_record;
	std::getline(records, new_record);
	user_records.push_back(new_record);
  }
  return user_records;
}