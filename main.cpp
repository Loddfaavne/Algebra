#include "std_lib_facilities.h"
#include "algebra.h"
#include "primitive.h"
#include "tests.h"
#include "encrypt.h"
#include "numberanalytic.h"
#include "factorization.h"
using namespace std;



int main()
{	
	// ofstream os {"factorization.txt"};
	// for (unsigned int i = 1; i < 10000; i++) {
	// 	print_factorize(i, os);
	// }
	// uint32_t t = 6;
	// uint32_t n = 7;
	// auto vec = irreduciblePolynom(t, n);
	// write_to_file("polynom.txt", vec, n);
	
	// string file = "primitiveroots.txt";
	// clearPrimitive(file);
	// uint64_t big_number = 9811;
	// writePrimitiveRoots(big_number, file);
	// printPrimitiveRoots(big_number);
	
	/*
	string filename = "primes.txt";
	int high = 900;
	outPrimes(filename, high);
	*/
	// test_mobius();
	// test_phiFunction();
	// test_sigmaFunction();
	// test_tauFunction();
	test_specialFunction();

	// string h = encrypt("Hallaballa");
	// cout << h << endl;
	//printGamma(5, -1.5, 0.2, 100000);
	//writeGamma(10.1, -10.1, 0.2, 100000, "gamma.txt");
}
