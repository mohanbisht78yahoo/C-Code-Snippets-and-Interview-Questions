template<typename T>
NodePtr<T>* reverse(NodePtr<T>*head)
{
    NodePtr<T>* curr = head;
    NodePtr<T>* prev = nullptr;
    while(curr)
    {   
        NodePtr<T>* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}
