class Solution {
    bool ispos(vector<int> &n1, vector<int> &n2, const int k, int val) {
        int n1count = upper_bound(n1.begin(), n1.end(), val) - n1.begin();
        int n2count = upper_bound(n2.begin(), n2.end(), val) - n2.begin();

        return n1count + n2count >= k;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        if((n + m) % 2) {
            int kth = (n + m + 1) / 2;
            int l = -1e6, r = 1e6, res;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(ispos(nums1, nums2, kth, mid)) {
                    res = mid;
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }

            return res;
        }else {
            int kth = (n + m) / 2;
            int l = -1e6, r = 1e6, kres;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(ispos(nums1, nums2, kth, mid)) {
                    kres = mid;
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }


            kth++;
            l = -1e6, r = 1e6;
            int k1res;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(ispos(nums1, nums2, kth, mid)) {
                    k1res = mid;
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }

            return ((double)0 + kres + k1res) / 2;
        }

        return -1;
    }
};
