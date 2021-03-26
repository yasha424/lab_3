#pragma once

#include "mat.cpp"
#include <iostream>
#include <fstream>
#include <string>

char** mat_fill(std::string file_directory);
int number_of_columns(std::string file_directory);
int number_of_rows(std::string file_directory);
void print_mat(char **mat, int rows, int cols);
void create_file(std::string str, char** mat);
