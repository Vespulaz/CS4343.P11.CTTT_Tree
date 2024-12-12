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
    
    // Helper methods for tree operations
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
    
    Node* deleteRecursive(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (value < node->data) {
            node->left = deleteRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRecursive(node->right, value);
        } else {
            // Case 1: Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            // Case 2: Node with two children
            Node* temp = findMinimum(node->right);
            node->data = temp->data;
            node->right = deleteRecursive(node->right, temp->data);
        }
        return node;
    }
    
    Node* findMinimum(Node* node) {
        if (node == nullptr) return nullptr;
        
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    Node* findMaximum(Node* node) {
        if (node == nullptr) return nullptr;
        
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
    
    bool checkBalanced(Node* node) {
        if (node == nullptr) return true;
        
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }
        
        return checkBalanced(node->left) && checkBalanced(node->right);
    }
    
    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
    
    bool searchRecursive(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        
        if (node->data == value) {
            return true;
        }
        
        return value < node->data ? 
               searchRecursive(node->left, value) : 
               searchRecursive(node->right, value);
    }
    
public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}
    
    // Public interface methods
    void insert(int value) {
        root = insertRecursive(root, value);
    }
    
    void remove(int value) {
        root = deleteRecursive(root, value);
    }
    
    int findMinValue() {
        Node* minNode = findMinimum(root);
        return minNode ? minNode->data : -1;
    }
    
    int findMaxValue() {
        Node* maxNode = findMaximum(root);
        return maxNode ? maxNode->data : -1;
    }
    
    bool isBalanced() {
        return checkBalanced(root);
    }
    
    int height() {
        return getHeight(root);
    }
    
    void printInorder() {
        cout << "Inorder traversal: ";
        inorderTraversal(root);
        cout << endl;
    }
    
    bool search(int value) {
        return searchRecursive(root, value);
    }
};

int main() {
    BinarySearchTree bst;
    
    // Insert values
    bst.insert(50);
    bst.insert(43);
    bst.insert(10);
    bst.insert(73);
    bst.insert(33);
    bst.insert(52);
    bst.insert(86);
    
    // Display initial tree
    bst.printInorder();
    
    // Remove a node
    bst.remove(50);
    cout << "After deleting 50: ";
    bst.printInorder();
    
    // Display tree properties
    cout << "Minimum value: " << bst.findMinValue() << endl;
    cout << "Maximum value: " << bst.findMaxValue() << endl;
    cout << "Is balanced? " << (bst.isBalanced() ? "Yes" : "No") << endl;
    cout << "Tree height: " << bst.height() << endl;
    cout << "Search for 33: " << (bst.search(33) ? "Found" : "Not Found") << endl;
    
    return 0;
}
