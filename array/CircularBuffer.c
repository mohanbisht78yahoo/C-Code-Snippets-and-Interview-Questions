#include <numeric>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
class CircularBuffer {
    std::vector<T> buf;
    size_t head = 0, tail = 0, count = 0;

public:
    CircularBuffer(size_t capacity) : buf(capacity) {}

    bool push(T v) {
        
        //if (count == buf.size()) return false;
        buf[tail] = v;
        cout << " for: " << v << " tail: " << tail <<endl;

        tail = (tail + 1) % buf.size();

        if(tail == head) head++;
        if(head == buf.size()-1) head = 0;
        cout << " next tail: " << tail << " head: " << head << endl;

        if(count < buf.size()) count++;

        return true;
    }
    void dump()
    {
        cout << "head: " << head << " tail: " << tail << endl;
        for(auto v : buf) {
            cout << v << " " << endl;
        }
    }

    bool pop(T &v) {

        if (count == 0) return false;

        v = buf[head];
        head = (head + 1) % buf.size();
        count--;
        return true;
    }
};

int main()
{
    CircularBuffer<int> cbuffer(10);
    for(int i=0;i<22;i++) {
        cout << i << ": " << cbuffer.push(i) << endl;
    }

    for(int i=0;i<22;i++) {
        int val=-1;
        cout << endl << "idx:" << i+1 << " exists:" << cbuffer.pop(val) << " val:" << val << " ";
    }
    cout << endl;
    cbuffer.dump();
    return 0;
}

