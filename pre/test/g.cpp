#include <iostream>
using namespace std;

int fibonacci(int n) {
  if (n == 1) {
    return 1;
  } else if (n == 2) {
    return 1;
  }

  return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
  cout << fibonacci(10) << endl;
  return 0;
}