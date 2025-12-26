// Online C++ compiler to run C++ program online
/* are tree same */
#include <iostream>
#include <treenode.h>

using namespace std;



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
