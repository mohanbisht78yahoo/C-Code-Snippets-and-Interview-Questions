#include <iostream>
#include <limits.h>
#include <list>

using namespace std;

template <typename T>
struct NODE
{
  NODE<T>* next = nullptr;
  std::list<T> dataList;

  NODE(T val) 
  { 
    dataList.push_back(val);
  }

  void print()
  {
    if(dataList.size() > 1) 
    {
        cout << "[ ";
        for(auto itr = dataList.begin(); itr != dataList.end(); itr++)
            cout << *itr << ", ";
        cout << "]";
    }
    else cout << " " << dataList.front() << ", ";
  }

  ~NODE() { /*cout << endl << "destroying: " << dataList.front();*/}
};

/*
template <typename T>
std::ostream& operator<<(std::ostream& stream,
                     const NODE<T>& node) {
    node.print(stream); // Assuming you define print for matrix
    return stream;
 }
*/

template <typename T>
using NodePtr = NODE<T>*;

template <typename T>
using ConstNodePtr = const NODE<T>*;

template <
    typename T,
    unsigned int Capacity = UINT_MAX >
class CircularList 
{
    static_assert(Capacity >= 1, "Capacity must be >= 1");

private:
    NodePtr<T> head = nullptr;

public: 
    class Iterator
    {

    private:
        ConstNodePtr<T> currentNode;
        ConstNodePtr<T> head;
        bool started;

    public:

        Iterator(ConstNodePtr<T> p, ConstNodePtr<T> h, bool s = false)
            : currentNode(p), head(h), started(s) {}

        Iterator& operator=(NodePtr<T> pNode)
        {
            this->currentNode = pNode;
            return *this;
        }

        /* prefix overlaod */
        Iterator& operator++()
        {
            if (!currentNode) return *this;
                currentNode = currentNode->next;

            /* if looping started, and current node is at head
            set it to nullptr to break the loop */
            if (currentNode == head && started)
                currentNode = nullptr;     // mark end when loop completed
            started = true;
            return *this;
        }

        // Postfix ++ overload
        Iterator& operator++(int)
        {
            // reuse prefix logic
            return ++(*this);
        }

        bool operator!=(const Iterator& iterator)
        {
            return currentNode != iterator.currentNode;
        }
        
        /*std::list<T> operator*()
        {
            return currentNode->dataList;
        }*/
        T operator*()
        {
            return currentNode->dataList.front();
        }

    };


public:
    ~CircularList()
    {
        clear();
    }

    void clear() 
    {
        if(!head) return;
        NodePtr<T> tmpHead = head;
        NodePtr<T> deleteItr = nullptr;
        do
        {
            deleteItr = tmpHead;
            tmpHead = tmpHead->next;
            delete deleteItr;
        } while( tmpHead != head );
        head = nullptr;
    }

     // Root of LinkedList wrapped in Iterator type
    Iterator begin()
    {
        return Iterator(head, head);
    }

    Iterator end()
    {
        return Iterator(nullptr, head);
    }

    //void 
    void remove(T data)
    {

    }

    void push_front(T data) 
    {
        if(head == nullptr) {
            head = new NODE<T>(data);
            head->next = head;
            return;
        }

        int count = 2;
        NodePtr<T> tail = head;
        while(tail->next != head) {
            if(tail->dataList.front() == data) {
                tail->dataList.push_back(data);
                return;
            }

            tail = tail->next;
            count++;
        }

        if(tail->dataList.front() == data) {
            tail->dataList.push_back(data);
            return;
        }

        if(count <= Capacity) {
            NodePtr<T> newNode = new NODE<T>(data);
            newNode->next = head;  
            tail->next = newNode;
            head = newNode;
        }
        /* we have reached the capacity */
        else {
            ///head->dataL = data;
            head->dataList.clear(); head->dataList.push_back(data);
            head = head->next;
        }
    }

    void push_back(T data)
    {
        if(head == nullptr) {
            head = new NODE<T>(data);
            head->next = head;
            return;
        }

        int count = 2;
        NodePtr<T> tail = head;
        while(tail->next != head) {
            if(tail->dataList.front() == data) {
                tail->dataList.push_back(data);
                return;
            }
            tail = tail->next;
            count++;
        }

        if(tail->dataList.front() == data) {
            tail->dataList.push_back(data);
            return;
        }

        if(count <= Capacity) {
            NodePtr<T> newNode = new NODE<T>(data);
            newNode->next = head;  
            tail->next = newNode;
        }
        /* we have reached the capacity */
        else {
            ///head->dataL = data;
            head->dataList.clear(); head->dataList.push_back(data);
            head = head->next;
        }
    }

    void print()
    {
        if(!head) return;
        NodePtr<T> tmp = head;
        do 
        {
            tmp->print();            
            tmp = tmp->next;
        } while(tmp != head);

        cout << endl;
    }
};


int main()
{
    CircularList<int, 5> circularList;
    for(int i=1;i<=5;i++) {
        circularList.push_front((uint)i);
    }

    cout << "push_front list: "; 
    circularList.print();
    circularList.clear();

    for(int i=1;i<=5;i++) {
        circularList.push_back((uint)i);
    }
    cout << "push_back list:  ";
    circularList.print();

    for(auto itr = circularList.begin(); itr != circularList.end(); itr++)
    {
        cout << *itr << " ";
    }

    return 0;
}
