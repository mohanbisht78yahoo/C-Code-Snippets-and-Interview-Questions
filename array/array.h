#include <numeric>
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

void mergedSortedArray(int* array1, int size1, int* array2, int size2, 
    int** mergedArray, int bound=-1)
{
    int idx1=0, idx2=0, idx3=0;
    int newSize = bound;

    if(newSize == -1) {
        newSize = size1 + size2;
    }
    *mergedArray = new int[newSize];

  /* loop till we can loop either size1, size2 or the newSize */
    while(idx1 < size1 && idx2 < size2 && idx3 < newSize) {
        if(array1[idx1] < array2[idx2]) {
            (*mergedArray)[idx3++] = array1[idx1++];
        }
        else {
            (*mergedArray)[idx3++] = array2[idx2++];
        }
    }
    while(idx1 < size1 && idx3 < newSize) {
        (*mergedArray)[idx3++] = array1[idx1++];
    }
    while(idx2 < size2 && idx3 < newSize) {
        (*mergedArray)[idx3++] = array2[idx2++];
    }
}
int main()
{
    int array1[] = {1, 2, 5, 7, 9, 10, 20};
    int array2[] = {7, 9, 11, 19, 21, 23, 27};
    int* sortedArray = nullptr;
    int size1 = sizeof(array1)/sizeof(int);
    int size2 = sizeof(array2)/sizeof(int);

    cout << "size 1: " << sizeof(array1)/sizeof(int) << endl;
    cout << "size 2: " << sizeof(array2)/sizeof(int) << endl;

    mergedSortedArray(array1, size1, 
        array2, size2, &sortedArray, 10);
    
    if(sortedArray) {
        for(int idx=0;idx<10;idx++)
            cout << sortedArray[idx] << " ";
    }

    return 0;
}

