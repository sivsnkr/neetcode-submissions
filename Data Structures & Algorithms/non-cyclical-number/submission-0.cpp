class Solution {
    int cal(int val) {
        int res = 0;
        while(val > 0) {
            int ld = val % 10;
            res += ld * ld;
            val /= 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        vector<bool> vis(1000, 0);
        while(n != 1 && !vis[n]) {
            vis[n] = 1;
            n = cal(n);
        }

        if(n == 1) return true;
        return false;
    }
};
