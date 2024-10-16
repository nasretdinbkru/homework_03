//
// Created by ray on 10.10.2024.
//
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <filesystem>
#include "helpers.h"

std::fstream get_records_file(const std::string &filename) {
  std::fstream records_{filename, std::fstream::in | std::fstream::out | std::fstream::app};
  if (!records_.is_open()) {
	std::cout << "Record file not found. Will be created" << std::endl;
	std::fstream new_file;
	new_file.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
	return new_file;
  }
  return records_;
}

std::fstream print_last_result(std::fstream &records, const std::string &username) {
  std::string record;
  const char *tmp_file_name = "tmp.txt";
  std::fstream tmp_file(tmp_file_name, std::fstream::out);
  bool is_familiar = false;
  while (std::getline(records, record)) {
	if (record.find(username)!=std::string::npos) {
	  std::string result(record.substr(record.find(';') + 1));
	  std::cout << "Your last result is: " << result << std::endl;
	  is_familiar = true;
	} else {
	  if (record!="\n" && !record.empty()) {
		tmp_file << record << std::endl;
		tmp_file.flush();
	  }
	}
  }
  tmp_file.close();
  if (!is_familiar) {
	std::cout << "Looks like you're new. Welcome!" << std::endl;
  }
  records.close();
  std::remove(RECORDS);
  std::filesystem::rename(tmp_file_name, RECORDS);
  return tmp_file;
}

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
	std::cout << "My number is greater." << std::endl;
  } else if (enigma < guess) {
	std::cout << "My number is less." << std::endl;
  }
}

