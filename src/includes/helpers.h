//
// Created by ray on 10.10.2024.
//

#ifndef HOMEWORK_03_SRC_INCLUDES_HELPERS_H_
#define HOMEWORK_03_SRC_INCLUDES_HELPERS_H_
const std::string RECORDS = "/home/ray/otus_cpp/otuscpp_nasretdinbkru/homework_03/cmake-build-debug/src/records.txt";

void check_guess(int &guess, int &enigma);
void get_records_fd(std::ifstream& records);
void print_last_result(std::ifstream& records, const std::string& username);

#endif //HOMEWORK_03_SRC_INCLUDES_HELPERS_H_
