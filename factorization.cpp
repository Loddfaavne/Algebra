#include "factorization.h"

vector<vector<int>> factorize(int x) {
    set<int> primes = primesto(int(x/2));
    vector<vector<int>> facts;
    for (set<int>::iterator it = primes.begin(); it != primes.end(); it++) {
        int counter = 0;
        if (x % *it == 0) {
            ++counter;
            x /= *it;
            while (x % *it == 0)
            {
                ++counter;
                x /= *it;
            }
            vector<int> inner;
            inner.push_back(*it);
            inner.push_back(counter);
            facts.push_back(inner);
        }
    }
    return facts;
}

void print_factorize(int x, ostream& os) {
    os << x << ": ";
    if (isPrime(x)) {
        os << "Prime number \n";
        return;
    }
    auto fact = factorize(x);
    for (auto p : fact) {
        os << p[0];
        if (p[1] != 1) {
            os << "^" << p[1];
        }
        os << " ";
    }
    os << "\n";
}