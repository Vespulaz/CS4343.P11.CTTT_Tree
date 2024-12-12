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
    // Helper method to find Lowest Common Ancestor recursively
    Node* findLCARecursive(Node* root, int value1, int value2) const {
        // Base case: empty tree
        if (root == nullptr) {
            return nullptr;
        }

        // If either value matches root, root is LCA
        if (root->data == value1 || root->data == value2) {
            return root;
        }

        // Recursively search in left and right subtrees
        Node* leftLCA = findLCARecursive(root->left, value1, value2);
        Node* rightLCA = findLCARecursive(root->right, value1, value2);

        // If both values found in different subtrees, current node is LCA
        if (leftLCA != nullptr && rightLCA != nullptr) {
            return root;
        }

        // Return non-null result from either subtree
        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }

    // Helper method for inorder traversal
    void printInorderTraversal(Node* node) const {
        if (node == nullptr) return;
        printInorderTraversal(node->left);
        cout << node->data << " ";
        printInorderTraversal(node->right);
    }

public:
    // Insert a new value into the BST
    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }

        return root;
    }

    // Find Lowest Common Ancestor of two nodes
    Node* findLCA(Node* root, int value1, int value2) const {
        return findLCARecursive(root, value1, value2);
    }

    // Print inorder traversal of the tree
    void printInorder(Node* root) const {
        cout << "Inorder Traversal: ";
        printInorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    Node* root = nullptr;

    // Build the binary search tree
    root = bst.insert(root, 20);
    bst.insert(root, 10);
    bst.insert(root, 30);
    bst.insert(root, 5);
    bst.insert(root, 15);
    bst.insert(root, 25);
    bst.insert(root, 35);

    // Print tree structure using inorder traversal
    bst.printInorder(root);

    // Find and print LCA for two nodes
    int node1 = 5, node2 = 15;
    Node* lca = bst.findLCA(root, node1, node2);
    
    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of " << node1 << " and " << node2 
             << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
