//STT: 8
//Full Name: Tran Duy Hai Dang

#include <iostream>
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
    
    // Helper method to find Lowest Common Ancestor recursively
    Node* findLCARecursive(Node* node, int value1, int value2) {
        // Base case: empty tree
        if (node == nullptr) return nullptr;
        
        // If both values are less than current node, LCA must be in left subtree
        if (value1 < node->data && value2 < node->data) {
            return findLCARecursive(node->left, value1, value2);
        }
        
        // If both values are greater than current node, LCA must be in right subtree
        if (value1 > node->data && value2 > node->data) {
            return findLCARecursive(node->right, value1, value2);
        }
        
        // If one value is less and other is greater, or one equals current node,
        // current node is the LCA
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
    
    // Public method to find Lowest Common Ancestor
    Node* findLowestCommonAncestor(int value1, int value2) {
        return findLCARecursive(root, value1, value2);
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
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(35);
    
    // Print tree structure using inorder traversal
    bst.printInorder();
    
    // Find and print LCA
    int value1 = 5, value2 = 15;
    Node* lca = bst.findLowestCommonAncestor(value1, value2);
    
    if (lca) {
        cout << "Lowest Common Ancestor (LCA) of " << value1 << " and " 
             << value2 << " is: " << lca->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }
    
    return 0;
}
