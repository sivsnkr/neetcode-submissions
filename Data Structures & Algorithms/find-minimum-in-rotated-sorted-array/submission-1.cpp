class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(mid + 1 < n && nums[mid + 1] < nums[mid]) return nums[mid + 1];

            if(nums[mid] > nums.back()) {
                // left
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }

        return nums[l];
    }
};
