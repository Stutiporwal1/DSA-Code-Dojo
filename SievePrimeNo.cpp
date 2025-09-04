// Solving leetcode problem no. 204 - count primes (Give an integer n, return the no. of prime no.s that are strictly less than n) using Sieve of Eratosthenes 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int countPrimes(int n) {

        int cnt = 0;
        vector<bool> prime(n+1, true);

        prime[0] = prime[1] = false;

        for(int i =2; i < n; i++) {

            if(prime[i]) {
                cnt++;

                for(int j = 2*i; j<n; j = j+i){
                    prime[j] = 0;
                }

            }
        }
        return cnt;
    }
}; 
