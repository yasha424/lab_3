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
  while (current.i != end.i || current.j != end.j) {
    count++;

    if (visited[current.i-1][current.j] == 0 && mat[current.i-1][current.j] == ' ') {
      Cell tmp(current.i-1, current.j, current.distance+1, current.way + "up ");
      cells.push(tmp);
    }
    if (visited[current.i][current.j+1] == 0 && mat[current.i][current.j+1] == ' ') {
      Cell tmp(current.i, current.j+1, current.distance+1, current.way + "right ");
      cells.push(tmp);
    }
    if (visited[current.i+1][current.j] == 0 && mat[current.i+1][current.j] == ' ') {
      Cell tmp(current.i+1, current.j, current.distance+1, current.way + "down ");
      cells.push(tmp);
    }
    if (visited[current.i][current.j-1] == 0 && mat[current.i][current.j-1] == ' ') {
      Cell tmp(current.i, current.j-1, current.distance+1, current.way + "left ");
      cells.push(tmp);
    }
    visited[current.i][current.j] = 1;
    current = cells.back();
    Cell back = cells.pop();
  }
  cout << "shortest distance is: " << current.distance << endl;
  int i = start.i;
  int j = start.j;
  int k = 49;
  string way = current.way;
  // cout << way << endl;
  for (size_t l = 0; l < count; l++) {
    char ch = k;
    k++;
    int index = way.find(" ");
    string where = way.substr(0, index);
    way = way.substr(index+1);
    // cout << where << endl;
    if (where == "up") {
      i--;
      mat[i][j] = ch;
      // cout << "up" << endl;
      // print_mat(mat, 8, 8);
    }
    else if (where == "right") {
      j++;
      mat[i][j] = ch;
      // cout << "right" << endl;
      // print_mat(mat, 8, 8);
    }
    else if (where == "down") {
      i++;
      mat[i][j] = ch;
      // cout << "down" << endl;
      // print_mat(mat, 8, 8);
    }
    else if (where == "left") {
      j--;
      mat[i][j] = ch;
      // cout << "left" << endl;
      // print_mat(mat, 8, 8);
    }
    if (k == 58) {
      k = 97;
    }
  }
  print_mat(mat, 8, 8);
}
