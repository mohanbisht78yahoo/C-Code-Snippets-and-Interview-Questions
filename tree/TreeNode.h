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
void print_levelorder(NodePtr<T> root)
{
    if(!root) {cout << "root is null, nothing to print" << endl; return;}
    std::queue< NodePtr<T> > queue;
    queue.push(root); /* push the root element to the queue */
    int level = 1;
    while(!queue.empty() {
        cout << endl << "level " << level << endl;
        for(int i=0;i<queue.size();i++) {
            auto node = queue.front();
            cout << node->data << " ";
            if(node->left) { /*cout << "left: " << node->left->data; */ queue.push(node->left); }
            if(node->right) { /* cout << "right " << node->right->data; */ queue.push(node->right); }
            queue.pop();
        }
        level++;
    }
}

template <typename T>
int height(NodePtr<T> root) {
    if(root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

tempate <typename T>
bool is_balancedtree(NodePtr<T> root) {
   if(!root) return true;

   lheight = height(root->left);
   rheight = height(root->right);
   if(lheight != rheight) return false;
   
   return ( is_balancedtree(root->left) &&
       is_balancedtree(root->right) );  
}

/* modified but this is better than is_balancedtree version */
template <typename T>
int balanced_height_tree(NodePtr<T> root) {
   if(root == nullptr) return 0;
   auto lheight = balanced_height_tree(root->left);
   auto rheight = balanced_height_tree(root->right);
   if(lheight == -1 || rheight == -1) return -1;
   /* if height difference greater than 1, it is not a balanced binary tree */
   if( abs(lheight - rheight) > 1) return -1;
   return max(height(root->left), height(root->right)) + 1;
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

//add node
template <typename T>
NodePtr<T> sorted_insert(NodePtr<T> root, T val ) 
{    
    NodePtr<T> tmp = new NODE<T>(val);
    if(root == NULL) return tmp;    
    if(root->data > val)
       root->left = sorted_insert<T>(root->left, val);
    else 
       root->right = sorted_insert<T>(root->right, val);

    return root;
}
