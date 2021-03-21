#include "mat.h"

int main(){
  std::string str;
  std::cin >> str;
  char **mat = mat_fill(str);
  print_mat(mat, 8, 8);
}
