#include "numberTheoretic.h"
int mobiusFunction(int n) {
    if (n == 1) 
        return 1; 
    int p = 0; 
    for (int i = 1; i <= n; i++) { 
        if (n % i == 0 && isPrime(i)) {  
            if (n % (i * i) == 0) 
                return 0; 
            else 
                p++; 
        } 
    } 
    return (p % 2 != 0)? -1 : 1; 
}

uint64_t phiFunction(uint64_t n) {
    if (isPrime(n)) {
        return n-1;
    }
    double phi = n;
    for (uint64_t i = 2; i < n/2+1; i++) {
        if (n % i == 0 && isPrime(i)) {
            phi *= (1-1/static_cast<double>(i));
        }
    }
    return phi;
}

int tauFunction(int n) {
    int tau = 0;
    for (int i = 1; i < n/2+1; i++) {
        if (n % i == 0) {
            tau++;
        }
    }
    return tau;
}

int sigmaFunction(int n) {
    int sigma = 0;
    for (int i = 1; i < n/2+1; i++) {
        if (n % i == 0) {
            sigma += i;
        }
    }
    return sigma;
}





