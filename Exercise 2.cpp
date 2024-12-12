//STT: 8
//Full Name: Tran Duy Hai Dang

#include <iostream>
#include <queue>
using namespace std;

// Node structure for Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
    
    // Private helper methods for tree operations
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
            // Case 1: Leaf node
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: Node with one child
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
            // Case 3: Node with two children
            Node* successor = findMinimum(node->right);
            node->data = successor->data;
            node->right = deleteRecursive(node->right, successor->data);
        }
        return node;
    }
    
    Node* findMinimum(Node* node) {
        Node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }
    
    // Tree traversal helper methods
    void traversePreOrder(Node* node) {
        if (node == nullptr) return;
        
        cout << node->data << " ";
        traversePreOrder(node->left);
        traversePreOrder(node->right);
    }
    
    void traverseInOrder(Node* node) {
        if (node == nullptr) return;
        
        traverseInOrder(node->left);
        cout << node->data << " ";
        traverseInOrder(node->right);
    }
    
    void traversePostOrder(Node* node) {
        if (node == nullptr) return;
        
        traversePostOrder(node->left);
        traversePostOrder(node->right);
        cout << node->data << " ";
    }
    
    void traverseLevelOrder(Node* node) {
        if (node == nullptr) return;
        
        queue<Node*> nodeQueue;
        nodeQueue.push(node);
        
        while (!nodeQueue.empty()) {
            Node* current = nodeQueue.front();
            nodeQueue.pop();
            cout << current->data << " ";
            
            if (current->left) nodeQueue.push(current->left);
            if (current->right) nodeQueue.push(current->right);
        }
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
    
    // Public traversal methods
    void displayPreOrder() {
        cout << "Pre-order Traversal: ";
        traversePreOrder(root);
        cout << endl;
    }
    
    void displayInOrder() {
        cout << "In-order Traversal: ";
        traverseInOrder(root);
        cout << endl;
    }
    
    void displayPostOrder() {
        cout << "Post-order Traversal: ";
        traversePostOrder(root);
        cout << endl;
    }
    
    void displayLevelOrder() {
        cout << "Level-order Traversal: ";
        traverseLevelOrder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    
    // Insert values into the tree
    bst.insert(25);
    bst.insert(34);
    bst.insert(79);
    bst.insert(56);
    bst.insert(98);
    bst.insert(69);
    bst.insert(96);
    
    cout << "Binary Tree Traversals:" << endl;
    bst.displayPreOrder();
    bst.displayInOrder();
    bst.displayPostOrder();
    bst.displayLevelOrder();
    
    return 0;
}
