#pragma once
#include <iostream>
#include <string>
#include "queue.h"

class Cell{
public:
  int distance;
  int i, j;
  Cell();
  Cell(int x, int y, int z);
  std::string way;
  Cell(int x, int y, int z, std::string way);
};

Cell::Cell(){}

Cell::Cell(int x, int y, int z){
  distance = z;
  i = x;
  j = y;
}

Cell::Cell(int x, int y, int z, std::string where){
  distance = z;
  i = x;
  j = y;
  way = where;
}
