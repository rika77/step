#include <iostream>
using namespace std;

bool isEven(int n) {
  if ((n-(n/10)*10)==0 || (n-(n/10)*10)==2 || (n-(n/10)*10)==4 || (n-(n/10)*10)==6 || (n-(n/10)*10)==8)
	return true;
  else
    return false;
}

int main() {
  cout << isEven(271) << endl;
  cout << isEven(314) << endl;
  return 0;
}
