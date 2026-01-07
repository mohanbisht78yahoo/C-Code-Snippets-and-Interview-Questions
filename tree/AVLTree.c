/* Balanced binary search tree (AVL Tree) */

#include <iostream>
#include <algorithm> // For max function

using namespace std;

// Node structure for AVL tree
struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
};

// Helper function to get the height of a node
int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Helper function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function to create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return(node);
}

// Right rotation (for LL case)
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotation (for RR case)
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalanceFactor(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key into the AVL tree
Node* insert(Node* node, int key) {
    // 1. Perform standard BST insertion
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys not allowed
        return node;

    // 2. Update height of ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor and balance the tree
    int balance = getBalanceFactor(node);

    // Left Left Case (Right Rotation)
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case (Left Rotation)
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case (Left Rotation then Right Rotation)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case (Right Rotation then Left Rotation)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to print the tree (inorder traversal for verification)
void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Main function to demonstrate the AVL tree
int main() {
    Node *root = NULL;

    /* Constructing an AVL tree */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal of the constructed AVL tree is: \n";
    inOrder(root);

    return 0;
}
