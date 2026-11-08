class Solution {
    pair<int,int> getSum(int a, int b) {
        int res = 0, c = 0;
        for(int i = 0; i < 32; i++) {
            int la = (1 & (a >> i));
            int lb = (1 & (b >> i));

            if((la ^ lb ^ c)) {
                res = res | (1 << i);
            }

            c = (la + lb + c) >= 2 ? 1 : 0;
        }

        if(res > 0 && (a < 0 && b < 0)) return {-1, -1};
        else if(res < 0 && (a > 0 && b > 0)) return {-1, -1};

        return {res, 0};
    }
    int getn(int x) {
        int res = 0;
        while(x > 0) {
            res++;
            x /= 10;
        }
        return res;
    }
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        int si = x;
        int res = 0;
        x = abs(x);
        int n = getn(x) - 1;
        int on = 0;
        while(x > 0) {
            int gl = x % 10;
            for(int it = 0; it < gl; it++) {
                if(si > 0) {
                    auto[su, va] = getSum(res, pow(10, n));
                    if(va == -1) return 0;
                    res = su;
                    // auto [osu, oval] = getSum(res, -pow(10, on));
                    // if(oval == -1) return 0;
                    // res = osu;
                }else {
                    auto[su, va] = getSum(res, -pow(10, n));
                    if(va == -1) return 0;
                    res = su;
                    // auto [osu, oval] = getSum(res, +pow(10, on));
                    // if(oval == -1) return 0;
                    // res = osu;
                }
            }

            n--, on++;
            x /= 10;
        }

        return res;
    }
};
