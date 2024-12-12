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

class BinaryTree {
private:
    // Helper method to build tree recursively from inorder and postorder traversals
    Node* buildTreeRecursive(const int* inorder, const int* postorder, 
                            int inStart, int inEnd, int& postIndex) {
        // Base case: invalid range
        if (inStart > inEnd) {
            return nullptr;
        }
        
        // Create root node from current postorder element
        int rootValue = postorder[postIndex];
        Node* root = new Node(rootValue);
        postIndex--; // Move to next element in postorder (right to left)
        
        // Find position of root in inorder traversal
        int rootPosition;
        for (rootPosition = inStart; rootPosition <= inEnd; rootPosition++) {
            if (inorder[rootPosition] == rootValue) {
                break;
            }
        }
        
        // Build right subtree first (since we're moving backwards in postorder)
        root->right = buildTreeRecursive(inorder, postorder, 
                                       rootPosition + 1, inEnd, postIndex);
        
        // Then build left subtree
        root->left = buildTreeRecursive(inorder, postorder, 
                                      inStart, rootPosition - 1, postIndex);
        
        return root;
    }
    
    // Helper methods for tree traversals
    void printInorderTraversal(Node* node) const {
        if (node == nullptr) return;
        printInorderTraversal(node->left);
        cout << node->data << " ";
        printInorderTraversal(node->right);
    }
    
    void printPostorderTraversal(Node* node) const {
        if (node == nullptr) return;
        printPostorderTraversal(node->left);
        printPostorderTraversal(node->right);
        cout << node->data << " ";
    }
    
public:
    // Construct binary tree from inorder and postorder traversals
    Node* constructTree(const int* inorder, const int* postorder, int size) {
        int postIndex = size - 1; // Start from last element of postorder
        return buildTreeRecursive(inorder, postorder, 0, size - 1, postIndex);
    }
    
    // Print inorder traversal of the tree
    void printInorder(Node* root) const {
        cout << "Inorder traversal of constructed tree: ";
        printInorderTraversal(root);
        cout << endl;
    }
    
    // Print postorder traversal of the tree
    void printPostorder(Node* root) const {
        cout << "Postorder traversal of constructed tree: ";
        printPostorderTraversal(root);
        cout << endl;
    }
};

int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int size = sizeof(inorder) / sizeof(inorder[0]);
    
    BinaryTree tree;
    
    // Construct the tree
    Node* root = tree.constructTree(inorder, postorder, size);
    
    // Print traversals to verify construction
    tree.printInorder(root);
    tree.printPostorder(root);
    
    return 0;
}
