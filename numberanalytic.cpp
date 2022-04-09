#include "numberanalytic.h"

double Gammafunction(double z, int iterations) {
    z--; // Dette er visst gamma(z+1)
    double gamma = 1;
    for (int i = 1; i < iterations + 1; i++) {
        gamma *= pow((1+ z/static_cast<double>(i)), -1)*pow(EulerConstant, z/static_cast<double>(i));
    }
    gamma *= pow(EulerConstant, -EulerMascheroni*z);
    return gamma;
}

void printGamma(double max, double min, double dx, int iterations) {
    std::cout << "List of values for the gamma function:" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    double g = 0;
    for (double i = min; i <= max; i += dx) {
        if (i == 0) { 
            g = 1;
        }
        else {
            g = Gammafunction(i, iterations);
        }
        std::cout << "Gamma of " << i << " = " << g << std::endl;
    }
}

void writeGamma(double max, double min, double dx, int iterations, string filename) {
    std::ofstream out {filename};
    double g = 0;
    out << "Gamma function values from " << min << " to " << max << ". Interval " << dx << endl;
    for (double i = min; i <= max; i += dx) {
        if (i == 0) { 
            g = 1;
        }
        else {
            g = Gammafunction(i, iterations);
        }
        out << "Gamma of " << i << " = " << g << std::endl;
    }
}