#pragma once
#include "dijkstra.cpp"
#include "queue.h"
#include "mat.h"
#include "Cell.h"
#include <iostream>
#include <string>
#include <vector>

int heuristic(Cell current, Cell end, string str);
char** AStar(string str, Cell start, Cell end, int rows, int cols, size_t &distance);
