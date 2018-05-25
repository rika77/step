#include <iostream>
using namespace std;

void divisor(int n) {
  for (int i = n; i > 0; --i) {
    if (!(n%i)) {
      cout << i << endl;
    }
  }
}

int main() {
  divisor(6);
  return 0;
}
