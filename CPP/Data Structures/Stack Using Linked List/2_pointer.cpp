#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};
Node *insertIntoBST(Node *root, int d) {
  if (root == NULL) {
    root = new Node(d);
    return root;
  }

  if (d > root->data) {
    root->right = insertIntoBST(root->right, d);
  } else {
    root->left = insertIntoBST(root->left, d);
  }
  return root;
}
Node *deleteFromBST(Node *root, int val) {
  // base case
  if (root == NULL) {
    return root;
  }
  if (root->data == val) {
    // 0 child
    if (root->right == NULL && root->left == NULL) {
      delete root;
      return NULL;
    }
    // 1 child
    // left child
    if (root->left != NULL && root->right == NULL) {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    // right child
    if (root->right != NULL && root->left == NULL) {
      Node *temp = root->right;
      delete root;
      return temp;
    }

    // 2 child
    if (root->right != NULL && root->left != NULL) {
      int min = minVal(root->right)->data;
      root->data = min;
      root->right = deleteFromBST(root->right, min);
      return root;
    }
    // o(n) time and space both
  } else if (root->data > val) {
    root->left = deleteFromBST(root->left, val);
    return root;
  } else {
    root->right = deleteFromBST(root->right, val);
    return root;
  }
}

void levelOrderTraversal(Node *root) {
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();
    if (temp == NULL) { // purana level complete traverse ho chuka hai
      cout << endl;
      if (!q.empty()) { // queue still has some child nodes
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
}
void takeInput(Node *&root) {
  int data;
  cin >> data;
  while (data != -1) {
    root = insertIntoBST(root, data);
    cin >> data;
  }
}
int main() {
  Node *root = NULL;
  cout << "enter data " << endl;
  takeInput(root);
  cout << "printing BST" << endl;
  levelOrderTraversal(root);
}

// insertion in BST logn
