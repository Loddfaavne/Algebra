#pragma once
#include "numberTheoretic.h"
using namespace std;
bool isPrimitiveRoot(uint64_t num, uint64_t of);
set<uint64_t> allPrimitiveRootsOf(uint64_t of);
void printPrimitiveRoots(uint64_t of);
void writePrimitiveRoots(uint64_t of, string filename);
void outPrimitiveRoots1_99 (string filename);
void clearPrimitive(string filename);
set<int> primesto(int high);
void outPrimes(string filename, int high);