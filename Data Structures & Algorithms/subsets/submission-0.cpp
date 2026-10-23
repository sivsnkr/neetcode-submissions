class Solution {
    void rec(int i, vector<int> &nums, vector<vector<int>> &res, vector<int> &buf) {
        if(i == nums.size()) {
            res.push_back(buf);
            return;
        }

        buf.push_back(nums[i]);
        rec(i + 1, nums, res, buf);
        buf.pop_back();
        rec(i + 1, nums, res, buf);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> buf;
        vector<vector<int>> res;

        rec(0, nums, res, buf);
        return res;
    }
};
