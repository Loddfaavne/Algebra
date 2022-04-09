#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
double constexpr EulerMascheroni = 0.577215664901532;
double constexpr EulerConstant = 2.718281828459045;
double Gammafunction(double z, int iterations);
void printGamma(double max, double min, double dx, int iterations);
void writeGamma(double max, double min, double dx, int iterations, string filename);

