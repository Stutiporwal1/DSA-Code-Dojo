// Palindrome Number - A palindrome number is a number which after reverse gets the same. (eg - Before Reversing 121 After reversing  121)

#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int sum = 0;
  int original = n;
  while(n != 0) {
  int ld = n % 10; // get last digit
  sum = (sum * 10) + ld; // add last digit
  n = n / 10; // remove last digit from n
  }

  if (sum == original){
    cout << "Palindrome Number" << endl;
  }
  else {
  cout << "Not a Palindrome" << endl;
  }

  return 0;
  
}
