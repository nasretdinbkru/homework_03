//
// Created by ray on 10.10.2024.
//
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "helpers.h"

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

void get_records_fd(std::ifstream &records) {

  if (!records) {
	std::cout << "Record file not found.";
	std::ofstream tmp(RECORDS, std::ostream::out);
	tmp.close();
  }
  records.open(RECORDS);
  if (!records.is_open()) {
	std::cout << "Cannot open records.txt." << std::endl;
  }
}

void print_last_result(std::ifstream& records, const std::string& username){
  std::string new_record;
  while (std::getline(records, new_record)) {
	if (new_record.find(username) != std::string::npos) {
	  std::string result(new_record.substr(new_record.find(';') + 1));
	  std::cout << "Your last result is: " << result << std::endl;
	  records.close();
	  break;
	}
  }
}