/*
  std::multiset is an associative container in the C++ Standard Template Library (STL) 
  that stores elements in a sorted order and, unlike std::set, allows duplicate values. 
  It is typically implemented as a balanced binary search tree, ensuring logarithmic time complexity for most operations. 
  */

#include <iostream>
#include <set>

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::multiset<int> _set;
        double median = 0;
        int size1 = nums1.size(), size2=nums2.size();
        for(int idx=0;idx< (size1>size2?size1:size2);idx++) {
          if(idx < size1) _set.insert(nums1[idx]);
          if(idx < size2) _set.insert(nums2[idx]);
        }

        int n = _set.size();
        int x = 0, y = 0;

        if(n % 2) {
           median = *std::next(_set.begin(), n/2);
        }
        else {
            std::set<int>::iterator it = _set.begin();
            std::advance(it, n/2);
            x = *it;
            std::advance(it, -1);
            y = *it;
            median = (double)(x+y)/2.0;
        }
        return median;
}
