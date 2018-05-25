#include <iostream>
using namespace std;

struct Node {
  Node* left;
  Node* right;
  int val;
};

void printTree(Node* root) {
  if (root == nullptr)
    return;
  printTree(root->left);
  cout << root->val << endl;
  printTree(root->right);
}

int main() {
  Node nodeL, nodeR, node;
  nodeL.val = 4;
  nodeL.left = nullptr;
  nodeL.right = nullptr;
  nodeR.val = 5;
  nodeR.left = nullptr;
  nodeR.right = nullptr;
  node.val = 3;
  node.left = &nodeL;
  node.right = &nodeR;

  node.right = node;

  printTree(&node);
  return 0;
}
