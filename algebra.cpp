#include "algebra.h"
using namespace std;

uint32_t ipow(uint32_t base, uint32_t exp)
{
    uint32_t result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

vector<vector<uint32_t>> tuples(const vector<uint32_t> &set, uint32_t tupleSize)
{
    vector<vector<uint32_t>> result;

    uint32_t maxValue = ipow(set.size(), tupleSize);

    for (uint32_t counter = 0; counter < maxValue; counter++) {
        vector<uint32_t> tuple(tupleSize);

        uint32_t currentValue = counter;
        for (size_t i = 0; i < tupleSize; i++) {
            uint32_t digit = currentValue % set.size();
            tuple[tupleSize - i - 1] = set[digit];
            currentValue /= set.size();
        }

        result.push_back(tuple);
    }

    return result;
}

bool isIrr(vector<uint32_t> polynomial, vector<uint32_t> zNum) {
    uint32_t sum;
    //uint32_t var;
    uint32_t exp = polynomial.size() - 1;
    uint32_t zN = zNum.size();
    for (auto z : zNum) {
        //var = z;
        sum = 0;
        exp = polynomial.size() - 1;
        for (unsigned int i = 0; i < polynomial.size(); i++) {
            uint32_t poi =  pow(z, exp)*polynomial[i];
            sum += poi % zN;
            --exp;
        }
        if (sum % zN == 0) {
            return false;
        }
    }
    return true;
}

vector<vector<uint32_t>> irreduciblePolynom(uint32_t maxDeg, uint32_t zN) {
    vector<vector<uint32_t>> irrPolynomials;
    vector<uint32_t> zNnum;
    for (unsigned int i = 0; i < zN; i++) {
        zNnum.push_back(i);
    }
    auto tuplevec = tuples(zNnum, maxDeg+1);
    for (auto tup : tuplevec) {
        if (isIrr(tup, zNnum)) {
            irrPolynomials.push_back(tup);
        }
    }
    return irrPolynomials;
}

ostream& outputIrreduciblePolynom(vector<vector<uint32_t>> irrPolynomials, uint32_t zN, ostream& out) {
    uint32_t maxDeg = irrPolynomials[0].size() - 1;
    cout << "Irreducible polynomials from Z" << zN << " of degree " << maxDeg << endl;
    for (auto polynomial : irrPolynomials) {
        for (unsigned int i = 0; i < polynomial.size(); i++) {
            uint32_t val = polynomial[i];
            if (val != 0) {
                if (val != 1 || i == maxDeg) {
                    out << val;
                } 
                if (maxDeg - i > 1) {
                    out << "x^" << maxDeg - i << " ";
                }
                else if (maxDeg - i == 1) {
                    out << "x ";
                }
                else {
                    out << " ";
                }
            }
        }
        out << endl;
    }
    return out;
}

void write_to_file(string file, vector<vector<uint32_t>> irrPolynomials, uint32_t zN) {
    ofstream of {file};
    // Kanskje et unntak
    outputIrreduciblePolynom(irrPolynomials, zN, of);
}

void printIrreduciblePolynom(vector<vector<uint32_t>> irrPolynomials, uint32_t zN) {
    outputIrreduciblePolynom(irrPolynomials, zN, cout);
}