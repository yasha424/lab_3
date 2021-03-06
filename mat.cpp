#include "mat.h"
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>

void print_mat(char **mat, int rows, int cols){
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      std::cout << mat[i][j];
    }
    std::cout << std::endl;
  }
}

int number_of_columns(std::string file_directory){
  std::ifstream in_file;
  in_file.open(file_directory);
  std::string str;
  getline(in_file, str);
  int i = 0, cols = 0;
  while (str[i] != '\0') {
    if (str[i] != ' ') {
      cols++;
    }
    i++;
  }
  return cols;
}

int number_of_rows(std::string file_directory){
  std::ifstream in_file;
  in_file.open(file_directory);
  std::string str;
  int rows = 0;
  while (!in_file.eof()) {
    getline(in_file, str);
    rows++;
  }
  return rows;
}

char** mat_fill(std::string file_directory){
  std::ifstream in_file;
  in_file.open(file_directory);
  int cols = number_of_columns(file_directory);
  int rows = number_of_rows(file_directory);
  char **mat = new char*[rows];
  for (size_t i = 0; i < rows; i++) {
    mat[i] = new char[cols];
  }
  std::string str;

  for (size_t i = 0; i < rows; i++) {
    getline(in_file, str);
    for (size_t j = 0; j < cols; j++) {
      mat[i][j] = str[j*2];
    }
  }
  return mat;
}

void create_file(std::string str, char** mat){
  std::ofstream outFile;
  outFile.open(str + "res.txt");
  for (size_t i = 0; i < number_of_rows(str); i++) {
    for (size_t j = 0; j < number_of_columns(str); j++) {
      outFile << mat[i][j] << ' ';
    }
    outFile << std::endl;
  }
  outFile.close();
}
