//STT: 8
//Full Name: Tran Duy Hai Dang

#include <iostream>
#include <vector>
#include <queue>
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
    
    // Helper method to perform level-order traversal
    vector<vector<int>> getLevelOrderTraversal() {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        // Use queue for level-order traversal
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size(); // Number of nodes at current level
            vector<int> currentLevel; // Store values of current level
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                Node* currentNode = nodeQueue.front();
                nodeQueue.pop();
                
                currentLevel.push_back(currentNode->data);
                
                // Add child nodes to queue for next level processing
                if (currentNode->left) nodeQueue.push(currentNode->left);
                if (currentNode->right) nodeQueue.push(currentNode->right);
            }
            
            result.push_back(currentLevel);
        }
        
        return result;
    }
    
public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}
    
    // Public method to insert a value
    void insert(int value) {
        root = insertRecursive(root, value);
    }
    
    // Public method to print level-order traversal
    void printLevelOrder() {
        vector<vector<int>> levels = getLevelOrderTraversal();
        
        cout << "Level-order traversal (by levels):" << endl;
        for (size_t i = 0; i < levels.size(); i++) {
            cout << "Level " << i + 1 << ": ";
            for (int value : levels[i]) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    BinarySearchTree bst;
    
    // Insert values to create a balanced BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    
    // Print tree structure level by level
    bst.printLevelOrder();
    
    return 0;
}
