#pragma once
#include <vector>
#include <iostream>
#include <set>
#include <ctgmath>
#include "std_lib_facilities.h"
using namespace std;
vector<vector<uint32_t>> irreduciblePolynom(uint32_t maxDeg, uint32_t zN);
uint32_t ipow(uint32_t base, uint32_t exp);
vector<vector<uint32_t>> tuples(const vector<uint32_t> &set, uint32_t tupleSize);
bool isIrr(vector<uint32_t> polynomial, vector<uint32_t> zNum);
ostream& otputIrreduciblePolynom(vector<vector<uint32_t>> irrPolynomials, uint32_t zN, ostream& out);
void printIrreduciblePolynom(vector<vector<uint32_t>> irrPolynomials, uint32_t zN);
void write_to_file(string file, vector<vector<uint32_t>> irrPolynomials, uint32_t zN);