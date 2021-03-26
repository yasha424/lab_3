#include "dijkstra.h"
using namespace std;

int main(){
  string str;
  cin >> str;
  int rows = number_of_rows(str);
  int cols = number_of_columns(str);
  size_t distance = -1;
  Cell start(6, 1, 0);
  size_t x = -1;
  Cell end(1, 6, x);
  char** mat = find_way(str, start, end, rows, cols, distance);
  print_mat(mat, rows, cols);
  cout << "shortest distance is: " << distance << endl;
}
