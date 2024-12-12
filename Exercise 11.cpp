//STT: 8
//Full Name: Tran Duy Hai Dang

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Tree {
private:
    Node* buildTreeHelper(int* inorder, int* postorder, int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd) {
            return NULL;
        }

        int rootVal = postorder[postIndex];
        Node* root = new Node(rootVal);
        postIndex--;

        int inIndex;
        for (inIndex = inStart; inIndex <= inEnd; inIndex++) {
            if (inorder[inIndex] == rootVal) {
                break;
            }
        }

        root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
        root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex);

        return root;
    }

public:
    Node* buildTree(int* inorder, int* postorder, int n) {
        int postIndex = n - 1; 
        return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex);
    }

    void inorderTraversal(Node* root) {
        if (root == NULL) return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void postorderTraversal(Node* root) {
        if (root == NULL) return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
};

int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Tree tree;
    Node* root = tree.buildTree(inorder, postorder, n);

    cout << "Inorder traversal of constructed tree: ";
    tree.inorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal of constructed tree: ";
    tree.postorderTraversal(root);
    cout << endl;

    return 0;
}
