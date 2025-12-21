#include <iostream>
using namespace std;
template <typename T>
struct NODE {
   NODE* next = nullptr;
   T data;
};
template <typename T>
using NodePtr = NODE<T>; 

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

template <typename T>
void print_middle(const NodePtr<T>* head)
{
    const NodePtr<T>* fast = head;
    const NodePtr<T>* slow = head;
    
    if(head == nullptr) {
        cout << "empty list" << endl;
        return;
    }
    while(fast && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "middle val " << slow->data << endl;
}

int main() {

    NodePtr<int>* head = nullptr;
    head = SortedInsert(head, 4);
    head = SortedInsert(head, 1);
    head = SortedInsert(head, 14);
    head = SortedInsert(head, 7);
    print_list(head);
    print_middle(head);

    return 0;
}
