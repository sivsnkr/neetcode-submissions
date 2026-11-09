class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstColZero = false;

        // Pass 1: record which rows and columns must become zero.
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) firstColZero = true;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;   // mark row i
                    matrix[0][j] = 0;   // mark column j
                }
            }
        }

        // Pass 2: fill zeros, going bottom-up and right-to-left
        // so the markers in row 0 and column 0 are read before they are overwritten.
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (firstColZero) matrix[i][0] = 0;
        }
    }
};