class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int, greater<int>> st;

        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            if(i >= k) {
                int li = i - k;
                st.erase(st.find(nums[li]));
            }

            if(i >= k - 1) {
                res.push_back(*st.begin());
            }
        }

        return res;
    }
};
