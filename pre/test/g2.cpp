#include <iostream>
using namespace std;

int fibonacci(int n) {
  int dp[101] = {};
  dp[1] = 1;
  dp[2] = 1;

  for (int i = 3; i <= n; i++) {
	  dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}

int main() {
  cout << fibonacci(10) << endl;
  return 0;
}
