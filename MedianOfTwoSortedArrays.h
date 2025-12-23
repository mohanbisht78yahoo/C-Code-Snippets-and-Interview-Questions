  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::list<int> _list;
        std::multiset<int> _set;
        double median = 0;

        //int nsize = nums1.size() > nums2.size() ? nums1.size() : nums2.size(); 

        for(int idx=0;idx<nums1.size();idx++) {
            _set.insert(nums1[idx]);
        }

        for(int idx=0;idx<nums2.size();idx++) {
            _set.insert(nums2[idx]);
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
            //printf("x: %d ", x);
            //printf("y: %d", y);
            median = (double)(x+y)/2.0;
        }

        return median;
}        
    }
