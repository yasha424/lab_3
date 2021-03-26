#pragma once
#include "Cell.h"
#include "dijkstra.h"
#include "queue.h"
#include <iostream>
#include "mat.h"

using namespace std;


char** find_way(string str, Cell start, Cell end){
  Queue<Cell> cells;
  char **mat = mat_fill(str);
  int rows = number_of_rows(str);
  int cols = number_of_columns(str);
  bool** visited = new bool*[rows];
  for (size_t i = 0; i < rows; i++) {
    visited[i] = new bool[cols];
    for (size_t j = 0; j < cols; j++) {
      cout << mat[i][j];
    }
    cout << endl;
  }
  Cell current = start;
  int count = 0;
  while ((current.i != end.i || current.j != end.j) && count < 50) {
    count++;
    
    if (visited[current.i-1][current.j] == 0 && mat[current.i-1][current.j] == ' ') {
      Cell tmp(current.i-1, current.j, 1);
      cout << "element " << current.i-1 << ", " << current.j << " was added" << endl;
      cells.push(tmp);
    }
    if (visited[current.i][current.j+1] == 0 && mat[current.i][current.j+1] == ' ') {
      Cell tmp(current.i, current.j+1, 1);
      cells.push(tmp);
      cout << "element " << current.i << ", " << current.j+1 << " was added" << endl;
    }
    if (visited[current.i+1][current.j] == 0 && mat[current.i+1][current.j] == ' ') {
      cells.push(Cell(current.i+1, current.j, 1));
      cout << "element " << current.i+1 << ", " << current.j << " was added" << endl;
    }
    if (visited[current.i][current.j-1] == 0 && mat[current.i][current.j-1] == ' ') {
      cells.push(Cell(current.i, current.j-1, 1));
      cout << "element " << current.i << ", " << current.j-1 << " was added" << endl;
    }
    visited[current.i][current.j] = 1;
    current = cells.back();
    Cell back = cells.pop();

    cout << "element " << back.i << ", " << back.j << " was deleted" << endl;
  }
}
