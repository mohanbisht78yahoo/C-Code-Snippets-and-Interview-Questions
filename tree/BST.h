// Online C++ compiler to run C++ program online
/* are tree same */
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
NodePtr<T> insert_iterative(NodePtr<T> root, T val ) 
{   
    if(root == NULL) 
       return new NODE<T>(val);

   NodePtr<t> parent = nullptr;
   NodePtr<T> curr = root;
   while(curr != null) {
      parent = curr;
      if (curr->data < val)
         curr = curr->right;
      else if(curr->data > val)
         curr = curr->left;
      else { /* duplicate entry case */
         break;
      }
   }

   if(parent->data < val)
      parent->right = new NodePtr<T>(val); 
   else if(parent->data > val)
      parent->left = new NodePtr<T>(val);
   else {
      /* duplicate entry case */
   }
   return root;
}

template <typename T>
NodePtr<T> insert_recursive(NodePtr<T> root, T val ) 
{    
    if(root == NULL) return new NODE<T>(val);

    if(root->data > val)
       root->left = insert_recursive<T>(root->left, val);
    else 
       root->right = insert_resursive<T>(root->right, val);
    
   return root;
}


/* get closest lower value to the root which will be on the left side 
the closest lower value on left side is the max value on the left side
which is the right most leaf node */
template <typename T>
NodePtr<T> get_ClosestMinSuccessor(NodePtr<T> root ) 
{
   NodePtr<T> curr = root->left;
   while(curr != nullptr && curr->right != nullptr)
      curr = curr->right;  
   return curr;
}

/* get closest higher value to the root which will on the right side 
the closest highest value on right side is the minimum value
which is the left most leaf node */
template <typename T>
NodePtr<T> get_ClosestMaxSuccessor(NodePtr<T> root, NodePtr<T>* parent ) 
{
   NodePtr<T> curr = root->right;
   while(curr != nullptr && curr->left != nullptr) {
      *parent = curr;
      curr = curr->left;
   }
   return curr;
}

template <typename T>
NodePtr<T> delete_recursive(NodePtr<T> root, T val ) 
{
   if(root == nullptr) return null;
   
   if(root->data < val)
      root = delete_recursive(root->right, val);
   else if(root->data > val)
      root = delete_recursive(root->left, val);
   
   else /* values match */ 
   {
      /* when no node at left return right */
      if(root->left == nullptr) {
         NodePtr<T> rightN = root->right;
         delete root;
         return rightN;
      }
      else if(root->right == nullptr)
      {
         NodePtr<T> leftN = root->left;
         delete root;
         return leftN;
      }
      else {
         NodePtr<T> parent = nullptr;
         NodePtr<T> successorN = get_ClosestMaxSuccessor(root, &parent);
         parent->left = nullptr;
         std::swap(root->data, successorN->data);
         return root;
      }
   }
}



int main() {
    // Write C++ code here
    NodePtr<int> root = nullptr;
    root = insert_recursive(root, 5);
    root = sorted_recursive(root, 6);
    root = sorted_recursive(root, 7);
    root = sorted_recursive(root, 2);

    print_inorder(root);
    
    return 0;
}
