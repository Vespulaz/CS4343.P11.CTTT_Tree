//STT: 8
//Full Name: Tran Duy Hai Dang

#include <iostream>
#include <algorithm>
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
    
    // Helper method to calculate height of a node
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
    
    // Helper method to calculate diameter recursively
    int calculateDiameterRecursive(Node* node, int& diameter) {
        if (node == nullptr) return 0;
        
        // Get heights of left and right subtrees
        int leftHeight = calculateDiameterRecursive(node->left, diameter);
        int rightHeight = calculateDiameterRecursive(node->right, diameter);
        
        // Update diameter if path through current node is longer
        diameter = max(diameter, leftHeight + rightHeight);
        
        // Return height of current node
        return 1 + max(leftHeight, rightHeight);
    }
    
    // Helper method for inserting nodes
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
    
    // Public method to calculate diameter
    int getDiameter() {
        int diameter = 0;
        calculateDiameterRecursive(root, diameter);
        return diameter;
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
    bst.insert(65);
    bst.insert(12);
    bst.insert(37);
    bst.insert(40);
    bst.insert(98);
    bst.insert(84);
    bst.insert(5);
    
    // Print inorder traversal
    bst.printInorder();
    
    // Calculate and print diameter
    cout << "Diameter of the tree: " << bst.getDiameter() << endl;
    
    return 0;
}
