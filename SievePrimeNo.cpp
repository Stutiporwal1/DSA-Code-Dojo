// Solving leetcode problem no. 204 - count primes (Give an integer n, return the no. of prime no.s that are strictly less than n) using Sieve of Eratosthenes 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; // No primes less than 2
        
        vector<bool> prime(n, true); // only need size n
        prime[0] = prime[1] = false; // 0 and 1 are not prime
        
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) cnt++;
        }
        return cnt;
    }
};
