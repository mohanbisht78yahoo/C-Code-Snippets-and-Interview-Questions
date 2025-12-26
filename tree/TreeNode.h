#include <iostream>
using namespace std;
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

template <typename T>
void print_preorder(NodePtr<T> root)
{
    if(!root) return;
    cout<< root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

template <typename T>
int height(NodePtr<T> root) {
    if(root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

template <typename T>
bool is_subtree(NodePtr<T> root1, NodePtr<T> root2) {
    
    if(root1 == nullptr && root2 == nullptr) return true;    
    if( is_sametree(root1, root2)) return true;
    if( is_subtree(root1->left, root2)) return true;
    if( is_subtree(root1->right, root2)) return true;
    return false;
}

template <typename T>
bool is_sametree(NodePtr<T> root1, NodePtr<T> root2) 
{
    if(root1 == nullptr && root2 == nullptr) return true;
    if(root1 == nullptr || root2 == nullptr) return false;
    if(root1->data != root2->data) return false;
    
    return is_sametree(root1->left, root2->left) &&
        is_sametree(root1->right, root2->right);
}

