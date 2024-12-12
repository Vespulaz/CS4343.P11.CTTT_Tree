//STT: 8
//Full Name: Tran Duy Hai Dang

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
    
    // Helper method to calculate height recursively
    int calculateHeight(Node* node) {
        if (node == nullptr) return -1;
        
        return 1 + max(calculateHeight(node->left), calculateHeight(node->right));
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
    
    // Helper method for inorder traversal
    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
    
public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}
    
    // Public method to insert a value
    void insert(int value) {
        root = insertRecursive(root, value);
    }
    
    // Public method to get tree height
    int getHeight() {
        return calculateHeight(root);
    }
    
    // Public method to print inorder traversal
    void printInorder() {
        cout << "Inorder traversal: ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    
    // Insert values into the tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    
    // Print inorder traversal
    bst.printInorder();
    
    // Print height of the tree
    cout << "Height of the tree: " << bst.getHeight() << endl;
    
    return 0;
}
