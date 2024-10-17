//
// Created by ray on 10.10.2024.
//

#ifndef HOMEWORK_03_SRC_INCLUDES_HELPERS_H_
#define HOMEWORK_03_SRC_INCLUDES_HELPERS_H_
const char *const RECORDS = "records.txt";


std::fstream get_records_file(const std::string &filename);
std::fstream print_last_result(std::fstream &records, const std::string &username);
void write_result(std::fstream &records, const std::string &username, uint8_t result);
void check_guess(int &guess, int &enigma);

#endif //HOMEWORK_03_SRC_INCLUDES_HELPERS_H_
