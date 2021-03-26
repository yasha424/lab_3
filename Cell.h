#pragma once
#include <iostream>
#include "queue.h"

class Cell{
public:
  int distance;
  int i, j;
  Cell();
  Cell(int x, int y, int z);
};

Cell::Cell(){}

Cell::Cell(int x, int y, int z){
  distance = z;
  i = x;
  j = y;
}
