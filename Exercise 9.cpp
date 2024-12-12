//STT: 8
//Full Name: Tran Duy Hai Dang

#include <iostream>
#include <climits>
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
    
    // Helper method to find maximum path sum recursively
    // Returns the maximum path sum that includes current node and at most one child
    // Updates globalMax with maximum path sum found so far (may include both children)
    int findMaxPathSumRecursive(Node* node, int& globalMax) {
        // Base case: empty node contributes 0 to path sum
        if (node == nullptr) return 0;
        
        // Get maximum path sums from left and right subtrees
        // Take max with 0 to handle negative values - we can choose not to include a path
        int leftMaxSum = max(0, findMaxPathSumRecursive(node->left, globalMax));
        int rightMaxSum = max(0, findMaxPathSumRecursive(node->right, globalMax));
        
        // Current max path through this node (may include both children)
        int currentMax = leftMaxSum + rightMaxSum + node->data;
        
        // Update global maximum if current path is larger
        globalMax = max(globalMax, currentMax);
        
        // Return maximum path sum including current node and at most one child
        // This is what can be used by parent nodes
        return max(leftMaxSum, rightMaxSum) + node->data;
    }
    
public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}
    
    // Public method to insert a value
    void insert(int value) {
        root = insertRecursive(root, value);
    }
    
    // Public method to find maximum path sum in the tree
    int findMaximumPathSum() {
        int globalMax = INT_MIN;
        findMaxPathSumRecursive(root, globalMax);
        return globalMax;
    }
};

int main() {
    BinarySearchTree bst;
    
    // Insert values to create the test tree
    bst.insert(10);
    bst.insert(2);
    bst.insert(10);
    bst.insert(20);
    bst.insert(1);
    bst.insert(-25);
    bst.insert(3);
    bst.insert(4);
    
    // Find and print maximum path sum
    cout << "Maximum Path Sum: " << bst.findMaximumPathSum() << endl;
    
    return 0;
}
