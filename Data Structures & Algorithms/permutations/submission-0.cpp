class Solution {
    bool next_permutation(vector<int> &nums) {
        auto rbegin = make_reverse_iterator(nums.end());
        auto rend = make_reverse_iterator(nums.begin());
        auto left = is_sorted_until(rbegin, rend);
        if(left == rend) return false;

        auto lb = lower_bound(rbegin, left, *left);
        iter_swap(lb, left);
        reverse(left.base(), nums.end());
        return true;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do {
            res.push_back(nums);
        }while(next_permutation(nums));
        return res;
    }
};
