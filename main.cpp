// #include "mat.h"
// #include "queue.h"
#include "dijkstra.h"
using namespace std;

int main(){
  string str;
  cin >> str;
  Cell start(6, 1, 0);
  size_t x = -1;
  Cell end(1, 6, x);
  find_way(str, start, end);

}
