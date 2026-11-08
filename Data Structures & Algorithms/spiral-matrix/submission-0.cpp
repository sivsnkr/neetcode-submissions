class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = 0;
        vector<int> res;
        while(i < n && j < m) {
            for(int it = j; it < m; it++) {
                res.push_back(matrix[i][it]);
            }
            i++;
            for(int it = i; it < n; it++) {
                res.push_back(matrix[it][m - 1]);
            }
            m--;
            for(int it = m - 1; it >= j && i < n; it--) {
                res.push_back(matrix[n - 1][it]);
            }
            n--;
            for(int it = n - 1; it >= i && j < m; it--) {
                res.push_back(matrix[it][j]);
            }
            j++;
        }
        return res;
    }
};
