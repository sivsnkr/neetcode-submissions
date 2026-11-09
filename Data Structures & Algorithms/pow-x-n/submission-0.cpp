class Solution {
    double cp(double x, int n) {
        if(n == 0) return 1;
        double val = myPow(x, n / 2);
        if(n % 2 == 0) return val * val;
        return val * val * x;
    }
public:
    double myPow(double x, int n) {
        if(n >= 0) return cp(x, n);
        return (double)1 / cp(x, abs(n));
    }
};
