#include "tests.h"

void test_mobius() {
    std::cout << "Values of the Mobius function for the integers from 0 to 100." << std::endl;
    for (unsigned int u = 0; u < 101; u++) {
        std::cout << "Mobius(" << u << ") = " << mobiusFunction(u) << std::endl;
    }
}

void test_phiFunction() {
     std::cout << "Values of the Phi function for the integers from 0 to 100." << std::endl;
    for (unsigned int u = 0; u < 101; u++) {
        std::cout << "Phi(" << u << ") = " << phiFunction(u) << std::endl;
    }
}

void test_tauFunction() {
     std::cout << "Values of the Tau function for the integers from 0 to 100." << std::endl;
    for (unsigned int u = 0; u < 1000; u++) {
        std::cout << "Tau(" << u << ") = " << tauFunction(u) << std::endl;
    }
}

void test_sigmaFunction() {
     std::cout << "Values of the Sigma function for the integers from 0 to 100." << std::endl;
    for (unsigned int u = 0; u < 101; u++) {
        std::cout << "Sigma(" << u << ") = " << sigmaFunction(u) << std::endl;
    }
}


void test_specialFunction() {
     std::cout << "Values of the special function for the integers from 0 to 100." << std::endl;
    for (unsigned int u = 0; u < 1000; u++) {
        std::cout << "Special(" << u << ") = " << int(pow(double(tauFunction(u)*phiFunction(u)), mobiusFunction(u))*sigmaFunction(u) + phiFunction(u)*mobiusFunction(u)) << std::endl;
    }
}