class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        // n <= m
        if(n > m) return findMedianSortedArrays(nums2, nums1);

        int tot = (n + m + 1) / 2;
        int l = -1, r = n - 1;
        while(l <= r) {
            int i1 = (l + r) / 2;
            int i2 = tot - 2 - i1;

            int vli1 = i1 < 0 ? INT_MIN : nums1[i1], vri1 = i1 + 1 < n ? nums1[i1 + 1] : INT_MAX;
            int vli2 = i2 < 0 ? INT_MIN : nums2[i2], vri2 = i2 + 1 < m ? nums2[i2 + 1] : INT_MAX;

            if(vli1 > vri2) {
                r = i1 - 1;
            }else if(vli2 > vri1) {
                l = i1 + 1;
            }else {
                if((n + m) % 2) 
                    return max(vli1, vli2);
                else {
                    int v1 = max(vli1, vli2), v2 = min(vri1, vri2);
                    return ((double)0 + v1 + v2) / 2;
                }
            }
        }        
        return -1;
    }
};
