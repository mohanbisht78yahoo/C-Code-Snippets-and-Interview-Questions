// Online C++ compiler to run C++ program online
/* are tree same */
#include <iostream>
using namespace std;
//SortedInsertedLinkedList
template <typename T>
struct NODE {
   NODE* left = nullptr;
   NODE* right = nullptr;
   T data;
   NODE<T>(T val) {data = val;}
};

template <typename T> using NodePtr = NODE<T>*;


template <typename T>
void print_inorder(NodePtr<T> root)
{
    if(!root) return;
    print_inorder(root->left);
    cout<< root->data << " ";
    print_inorder(root->right);
}

//add node
template <typename T>
NodePtr<T> sorted_insert(NodePtr<T> root, T val ) {
    
    NodePtr<T> tmp = new NODE<T>(val);
    if(root == NULL) return tmp;
    
    if(root->data > val)
       root->left = sorted_insert<T>(root->left, val);
    else 
       root->right = sorted_insert<T>(root->right, val);

    return root;
}

int main() {
    // Write C++ code here
    NodePtr<int> root = nullptr;
    root = sorted_insert(root, 5);
    root = sorted_insert(root, 6);
    root = sorted_insert(root, 7);
    root = sorted_insert(root, 2);

    print_inorder(root);
    
    return 0;
}
