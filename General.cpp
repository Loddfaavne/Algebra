#include "General.h"

uint64_t gcd(uint64_t a, uint64_t b) 
{  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a;  
    if (a == b) 
        return a;  
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 

bool isPrime(uint64_t n) 
{ 
    if (n < 2) 
        return false; 
    for (uint64_t i = 2; i * i <= n; i++)  
        if (n % i == 0) 
            return false;     
    return true; 
} 
