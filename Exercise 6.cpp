//STT: 8
//Full Name: Tran Duy Hai Dang

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    explicit Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
    
    // Helper method to check height balance recursively
    // Returns height of current subtree and updates isBalanced flag
    int checkHeightBalanceRecursive(Node* node, bool& isBalanced) {
        if (node == nullptr) return 0;
        
        // Get heights of left and right subtrees
        int leftHeight = checkHeightBalanceRecursive(node->left, isBalanced);
        int rightHeight = checkHeightBalanceRecursive(node->right, isBalanced);
        
        // Check balance condition at current node
        if (abs(leftHeight - rightHeight) > 1) {
            isBalanced = false;
        }
        
        // Return height of current subtree
        return 1 + max(leftHeight, rightHeight);
    }
    
    // Helper method for inserting nodes recursively
    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }
    
public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}
    
    // Public method to insert a value
    void insert(int value) {
        root = insertRecursive(root, value);
    }
    
    // Public method to check if tree is height balanced
    bool isHeightBalanced() {
        bool isBalanced = true;
        checkHeightBalanceRecursive(root, isBalanced);
        return isBalanced;
    }
};

int main() {
    BinarySearchTree bst;
    
    // Insert values into the tree
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(2);
    bst.insert(8);
    
    // Check and print if tree is height balanced
    if (bst.isHeightBalanced()) {
        cout << "The tree is height-balanced." << endl;
    } else {
        cout << "The tree is not height-balanced." << endl;
    }
    
    return 0;
}
