class Solution {
    bool ispos(vector<int> &piles, int h, int mid) {
        long long res = 0;
        for(int i : piles) {
            res += (i + mid - 1) / mid;
        }
        return res <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h < piles.size()) return -1;
        int l = 1, r = 1e9, res = -1;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(ispos(piles, h, mid)) {
                res = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }

        return res;
    }
};
