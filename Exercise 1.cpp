//STT: 8
//Full Name: Tran Duy Hai Dang

#include <iostream>
using namespace std;

// Cấu trúc Node cho cây nhị phân tìm kiếm
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor với giá trị khởi tạo
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;
    
    // Các hàm helper private
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
    
    Node* findMinimum(Node* node) {
        Node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }
    
    Node* deleteRecursive(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        
        // Tìm node cần xóa
        if (value < node->data) {
            node->left = deleteRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRecursive(node->right, value);
        } else {
            // Trường hợp node lá hoặc chỉ có 1 con
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            // Trường hợp node có 2 con
            Node* successor = findMinimum(node->right);
            node->data = successor->data;
            node->right = deleteRecursive(node->right, successor->data);
        }
        return node;
    }
    
    bool searchRecursive(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        
        if (node->data == value) {
            return true;
        }
        
        if (value < node->data) {
            return searchRecursive(node->left, value);
        }
        return searchRecursive(node->right, value);
    }
    
    void inorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
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
    
    bool search(int value) {
        return searchRecursive(root, value);
    }
    
    void printInorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    
    // Thêm các phần tử vào cây
    bst.insert(42);
    bst.insert(64);
    bst.insert(87);
    bst.insert(12);
    bst.insert(1);
    bst.insert(25);
    bst.insert(70);
    
    cout << "Inorder traversal: ";
    bst.printInorder();
    
    // Xóa node có giá trị 12
    bst.remove(12);
    
    cout << "Inorder traversal after deleting 12: ";
    bst.printInorder();
    
    return 0;
}
