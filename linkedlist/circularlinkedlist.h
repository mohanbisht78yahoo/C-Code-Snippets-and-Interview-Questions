template <typename T>
typedef struct NODE
{
  NODE* next;
  T data;
}Node;

template <typename T>
using NodePtr = Node<T>*;

template <typename T>
void print_list(NodePtr<T> * head)
{
  if(!head) return;

  NodePtr<T>* tmp = head;
  do 
  {
    cout << tmp->data << " ";
    tmp = tmp->next;
  } while(tmp != head);
}

