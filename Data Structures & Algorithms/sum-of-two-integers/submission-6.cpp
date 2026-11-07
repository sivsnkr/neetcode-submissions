class Solution {
public:
    int getSum(int a, int b) {
        int res = 0, c = 0;
        for(int i = 0; i < 32; i++) {
            int la = (1 & (a >> i));
            int lb = (1 & (b >> i));

            if((la ^ lb ^ c)) {
                res = res | (1 << i);
            }

            c = (la + lb + c) >= 2 ? 1 : 0;
        }


        return res;
    }
};
