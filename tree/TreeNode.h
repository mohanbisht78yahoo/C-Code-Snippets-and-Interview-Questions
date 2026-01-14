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

/* use stack LIFO data struct */
template <typename T>
void iterate_inorder(NodePtr<T> root)
{
   std::stack<NodePtr<T>> st;
   NodePtr<T> curr = root;
   while(curr != nullptr || !st.empty()) {
      /* keep going to left; */
      while(curr != nullptr) {
         st.push(curr);
         curr=curr->left;
      }
      /* get the one at the top */
      curr = s.top(); s.pop();
      cout << curr->data << " ";
      curr = curr->right;
   }
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
void printkthnode(NodePtr<T> root, int k)
{
  if(!root) return;
   
  if(k == 0)  {
     cout << root->data ;
  }
  else { 
    printkthnode(root->left, k-1);
    printkthnode(root->right, k-1);
  }
}

template <typename T>
int height(NodePtr<T> root) {
    if(root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

/* For iterative approach use level order traversal with a counter
increment the counter whenever we add nodes to the queue */
template <typename T>
int size(NodePtr<T> root) {
   if(root == nullptr) return 0;
   return (1 + size(root->left) + size(root->right));
}

tempate <typename T>
int width(NodePtr<T> root) {
   if(!root) { return 0;}
   int width=0;
   std::queue< NodePtr<T> > queue;
   queue.push(root); /* push the root element to the queue */
   while(!queue.empty() {
      width = queue.size() > width : queue.size() : width;
      for(int i=0;i<queue.size();i++) {
         auto node = queue.front();
         if(node->left) { queue.push(node->left); }
         if(node->right) { queue.push(node->right); }
         queue.pop();
      } 
   }
   return width;
}

template <>
int maxValue(NodePtr<int> root) {
   if(root == nullptr) return INT_MIN;
   return max(root->data, max(maxValue(root->left), maxValue(root->right)));  
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
   return max(lheight, rheight) + 1;
}


/* longest path also called diameter of binary tree */
template <typename T>
int longest_path_height((NodePtr<T> root)
{
   int maxH = 0;
   max_height(root, &maxH);
   return maxH;
}

/* longest path length, diameter of a tree */
template <typename T>
int max_height(NodePtr<T> root, int& maxH) {
   if(root == nullptr) return 0;
   auto lheight = max_height(root->left, maxH);
   auto rheight = max_height(root->right, maxH);
   maxH = max(maxH, lheight + rheight);
   return 1 + max(lheight, rheight);
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
