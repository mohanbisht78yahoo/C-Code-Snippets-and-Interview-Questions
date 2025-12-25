#include <iostream>
using namespace std;
//SortedInsertedLinkedList
template <typename T>
struct NODE {
   NODE* next = nullptr;
   T data;
};
template <typename T>
using NodePtr = NODE<T>; 

template <class T>
NodePtr<T>* NthNodeFromLast(NodePtr<T>*head, int n)
{
    NodePtr<T>* ahead = head;
    NodePtr<T>* curr = head;
    
    for(int i=1;i<n && ahead != nullptr ;i++) {
        ahead = ahead->next;
    }

    if(ahead == nullptr)
        return nullptr;
    
    while(ahead->next) {
        curr = curr->next;
        ahead=ahead->next;
    }
    
    return curr;
}

template <class T>
void print_list(const NodePtr<T>* head)
{
    cout << "printing list" << endl;
    if(head == nullptr) {
        cout << "list is empty"<< std::endl;
        return;
    }
    
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

template <class T>
NodePtr<T>* SortedInsert(NodePtr<T>*head, T data)
{
    NodePtr<T>* tmp = new NodePtr<T>{nullptr, data};
    if(head == nullptr) return tmp;
    
    if(head->data > data) {
        tmp->next = head;
        return tmp;
    }
    
    /* check one step ahead,  */
    NodePtr<T>* curr = head;
    while(curr->next != nullptr 
        && curr->next->data < data)
    {
        curr = curr->next;
    }
    tmp->next = curr->next;
    curr->next = tmp;
    
    return head;
}


int main() {

    NodePtr<int>* head = nullptr;
    head = SortedInsert(head, 4);
    head = SortedInsert(head, 1);
    head = SortedInsert(head, 14);
    head = SortedInsert(head, 7);
    print_list(head);

    int n = 1;
    auto node = NthNodeFromLast(head, n);
    if(node) {
        cout << n << "th node: " << node->data << endl;
    }
    else { cout << n << "th node not found";  }
    return 0;
}




