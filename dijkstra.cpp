#pragma once
#include "Cell.h"
#include "dijkstra.h"
#include "queue.h"
#include <iostream>
#include "mat.h"

using namespace std;


char** find_way(string str, Cell start, Cell end, int rows, int cols, size_t &distance){
  Queue <Cell> cells;
  // char **mat = mat_fill(str);
  char **mat = mat_fill(str);
  bool** visited = new bool*[rows];
  for (size_t i = 0; i < rows; i++) {
    visited[i] = new bool[cols];
    for (size_t j = 0; j < cols; j++) {
      visited[i][j] = 0;
    }
  }
  Cell current = start;
  int count = 0;
  while (current.i != end.i || current.j != end.j) {
    count++;

    if (visited[current.i-1][current.j] == 0 && mat[current.i-1][current.j] != 'X') {
      Cell tmp(current.i-1, current.j, current.distance+1, current.way + "up ");
      cells.push(tmp);
    }
    if (visited[current.i][current.j+1] == 0 && mat[current.i][current.j+1] != 'X') {
      Cell tmp(current.i, current.j+1, current.distance+1, current.way + "right ");
      cells.push(tmp);
    }
    if (visited[current.i+1][current.j] == 0 && mat[current.i+1][current.j] != 'X') {
      Cell tmp(current.i+1, current.j, current.distance+1, current.way + "down ");
      cells.push(tmp);
    }
    if (visited[current.i][current.j-1] == 0 && mat[current.i][current.j-1] != 'X') {
      Cell tmp(current.i, current.j-1, current.distance+1, current.way + "left ");
      cells.push(tmp);
    }
    visited[current.i][current.j] = 1;
    current = cells.back();
    Cell back = cells.pop();
    // cout << cells.size() << endl; // for check
  }
  distance = current.distance;
  int i = start.i;
  int j = start.j;
  int k = 49;
  string way = current.way;
  for (size_t l = 0; l < count; l++) {
    char ch = k;
    k++;
    int index = way.find(" ");
    string where = way.substr(0, index);
    way = way.substr(index+1);
    if (where == "up") {
      i--;
      mat[i][j] = ch;
    }
    else if (where == "right") {
      j++;
      mat[i][j] = ch;
    }
    else if (where == "down") {
      i++;
      mat[i][j] = ch;
    }
    else if (where == "left") {
      j--;
      mat[i][j] = ch;
    }
    if (k == 58) {
      k = 97;
    }
  }
  return mat;
}

int heuristic(Cell current, Cell end, string str){
  if (str == "up") {
    return abs(current.i - 1 - end.i) + abs(current.j - end.j);
  }
  if (str == "right") {
    return abs(current.i - end.i) + abs(current.j + 1 - end.j);
  }
  if (str == "down") {
    return abs(current.i + 1 - end.i) + abs(current.j - end.j);
  }
  if (str == "left") {
    return abs(current.i - end.i) + abs(current.j - 1 - end.j);
  }
}

char** AStar(string str, Cell start, Cell end, int rows, int cols, size_t &distance){
  Queue <Cell> cells;
  char **mat = mat_fill(str);
  bool** visited = new bool*[rows];
  for (size_t i = 0; i < rows; i++) {
    visited[i] = new bool[cols];
    for (size_t j = 0; j < cols; j++) {
      visited[i][j] = 0;
    }
  }
  Cell current = start;
  int count = 0;
  while (current.i != end.i || current.j != end.j) {
    count++;
    int dist;
    if (visited[current.i-1][current.j] == 0 && mat[current.i-1][current.j] != 'X') {
      dist = current.distance + heuristic(current, end, "up") + 1;
      Cell tmp(current.i-1, current.j, current.distance+1, current.way + "up ");
      cells.push(tmp);
    }
    if (visited[current.i][current.j+1] == 0 && mat[current.i][current.j+1] != 'X') {
      dist = current.distance + heuristic(current, end, "right") + 1;
      Cell tmp(current.i, current.j+1, current.distance+1, current.way + "right ");
      cells.push(tmp);
    }
    if (visited[current.i+1][current.j] == 0 && mat[current.i+1][current.j] != 'X') {
      dist = current.distance + heuristic(current, end, "down" + 1);
      Cell tmp(current.i+1, current.j, current.distance+1, current.way + "down ");
      cells.push(tmp);
    }
    if (visited[current.i][current.j-1] == 0 && mat[current.i][current.j-1] != 'X') {
      dist = current.distance + heuristic(current, end, "left") + 1;
      Cell tmp(current.i, current.j-1, current.distance+1, current.way + "left ");
      cells.push(tmp);
    }
    visited[current.i][current.j] = 1;
    current = cells.back();
    Cell back = cells.pop();
  }
  distance = current.distance;
  int i = start.i;
  int j = start.j;
  int k = 49;
  string way = current.way;

  for (size_t l = 0; l < count; l++) {
    char ch = k;
    k++;
    int index = way.find(" ");
    string where = way.substr(0, index);
    way = way.substr(index+1);
    if (where == "up") {
      i--;
      mat[i][j] = ch;
    }
    else if (where == "right") {
      j++;
      mat[i][j] = ch;
    }
    else if (where == "down") {
      i++;
      mat[i][j] = ch;
    }
    else if (where == "left") {
      j--;
      mat[i][j] = ch;
    }
    if (k == 58) {
      k = 97;
    }
  }
  return mat;
}
