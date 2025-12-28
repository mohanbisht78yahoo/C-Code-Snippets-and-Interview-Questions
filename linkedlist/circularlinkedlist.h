#include <iostream>
using namespace std;

template <typename T>
struct NODE
{
  NODE<T>* next;
  T data;
  NODE(T val) { data = val;}
};

template <typename T>
using NodePtr = NODE<T>*;

template <typename T>
NodePtr<T> insert(NodePtr<T> head, T data)
{
    NodePtr<T> newNode = new NODE<T>(data);
    if(head == nullptr) {
        head = newNode;
        head->next = head;
        return head;
    }

    NodePtr<T> tmp = head;
    while(tmp->next != head) {
        tmp = tmp->next;
    }
  
    newNode->next = head;  
    tmp->next = newNode;
    return head;
}

template <typename T>
void print_list(NodePtr<T> head)
{
  if(!head) return;

  NodePtr<T> tmp = head;
  do 
  {
    cout << tmp->data << " ";
    tmp = tmp->next;
  } while(tmp != head);
}

int main()
{
    NodePtr<int> head = nullptr;

    head = insert(head, 6);
    head = insert(head, 8);
    head = insert(head, 1);
    print_list(head);

    return 0;
}
