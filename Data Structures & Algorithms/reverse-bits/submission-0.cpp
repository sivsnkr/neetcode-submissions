class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bi(n);
        // reverse(bi.begin(), bi.end());
        int i = 0, j = 31;
        while(i < j) {
            int val = bi[i];
            int val1 = bi[j];
            bi[i] = val1;
            bi[j] = val;
            i++, j--;
        }
        return bi.to_ulong();
    }
};
