#include <iostream>
using namespace std;

struct Node {
  Node* next;
  int val;
};

int sum(Node* root) {
  if (root == nullptr)
    return 0;
  return root->val + sum(root->next);
}

int main() {
  Node* root = new Node;
  root->val = 1;

  Node* n = root;
  for (int i = 2; i <= 10; ++i) {
    n->next = new Node;
    n = n->next;
    n->val = i;
  }
  n->next = nullptr;
  cout << sum(root) << endl;
  return 0;
}
