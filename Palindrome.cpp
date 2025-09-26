#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int sum = 0;
  int original = n;
  while(n != 0) {
  int ld = n % 10;
  sum = (sum * 10) + ld;
  n = n / 10;
  }

  if (sum == original){
    cout << "Palindrome Number" << endl;
  }
  else {
  cout << "Not a Palindrome" << endl;
  }

  return 0;
  
}
