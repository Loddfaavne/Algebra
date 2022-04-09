#include "primitive.h"
bool isPrimitiveRoot(uint64_t num, uint64_t of) {
    if (gcd(num, of) != 1) {return false;}
    uint64_t i = 1;
    uint64_t ipow = 1;
    while (i != phiFunction(of)) {
        ipow *= num;
        if (ipow % of == 1) {
            return false;
        }
        ipow = ipow % of;
        i++;
    }
    cout << "Calculating";
    return true;
}

set<uint64_t> allPrimitiveRootsOf(uint64_t of) {
    set<uint64_t> primitiveRoots;
    for (uint64_t j = 1; j < of; j++) {
        if (isPrimitiveRoot(j, of)) {
            primitiveRoots.insert(j);
        }
    }
    return primitiveRoots;
}

void writePrimitiveRoots(uint64_t of, string filename) {
    ofstream out;
    out.open(filename, fstream::app);
    set<uint64_t> primitiveRoots = allPrimitiveRootsOf(of);
    primitiveRoots = allPrimitiveRootsOf(of);
    out << "Primitive roots of " << of << ":\n";
    if (primitiveRoots.empty() || ((primitiveRoots.size() == 1) && (primitiveRoots.find(1) != primitiveRoots.end()))) {
        out << "Has no primitive roots\n";
    }
    else {
        for (set<uint64_t>::iterator it = primitiveRoots.begin(); it != primitiveRoots.end(); it++) {
            out << *it << endl;
        }
    }
    out << endl;
    /*
    time_t now = time(NULL);
    tm * ptm = localtime(&now);
    char buffer[32];
    // Format: Mo, 15.06.2009 20:20:00
    std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
    */
    out.close();
}

void printPrimitiveRoots(uint64_t of) {
    set<uint64_t> primitiveRoots = allPrimitiveRootsOf(of);
    primitiveRoots = allPrimitiveRootsOf(of);
    cout << "Primitive roots of " << of << ":\n";
    if (primitiveRoots.empty() || ((primitiveRoots.size() == 1) && (primitiveRoots.find(1) != primitiveRoots.end()))) {
        cout << "Has no primitive roots\n";
    }
    else {
        for (set<uint64_t>::iterator it = primitiveRoots.begin(); it != primitiveRoots.end(); it++) {
            cout << *it << endl;
        }
    }
    cout << endl;  
}

void outPrimitiveRoots1_99 (string filename) {
    ofstream out {filename};
    //fstream out;
    //out.open(filename, fstream::app);
    set<uint64_t> primitiveRoots;
    for (int of = 2; of < 100; of++) {
        primitiveRoots = allPrimitiveRootsOf(of);
        out << "Primitive roots of " << of << ":\n";
        if (primitiveRoots.empty() || ((primitiveRoots.size() == 1) && (primitiveRoots.find(1) != primitiveRoots.end()))) {
            out << "Has no primitive roots\n";
        }
        else {
            for (set<uint64_t>::iterator it = primitiveRoots.begin(); it != primitiveRoots.end(); it++) {
                out << *it << endl;
            }
        }
        out << endl;
    }
    //out.close();
}

void clearPrimitive(string filename) {
    ofstream out {filename};
    out.clear();
}

set<int> primesto(int high) {
    set<int> primes;
    for (int i = 1; i < high + 1; i++) {
        if (isPrime(i)) {
            primes.insert(i);
        }
    }
    return primes;
}

void outPrimes(string filename, int high) {
    ofstream out {filename};
    set<int> primes = primesto(high);
    out << "Prime numbers to " << high << endl;
    for (set<int>::iterator it = primes.begin(); it != primes.end(); it++) {
        out << *it << endl;
    }
}