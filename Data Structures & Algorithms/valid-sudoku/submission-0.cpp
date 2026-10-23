class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        for(int i = 0; i < n; i++) {
            set<int> st;
            for(int j = 0; j < n; j++) {
                if(board[i][j] != '.') {
                    if(st.find(board[i][j]) != st.end()) return false;
                    st.insert(board[i][j]);
                }
            }
        }

        for(int j = 0; j < n; j++) {
            set<int> st;
            for(int i = 0; i < n; i++) {
                if(board[i][j] != '.') {
                    if(st.find(board[i][j]) != st.end()) return false;
                    st.insert(board[i][j]);
                }
            }
        }

        for(int i = 0; i < n; i += 3) {
            for(int j = 0; j < n; j+= 3) {
                set<int> st;
                for(int ii = i; ii < i + 3; ii++) {
                    for(int jj = j; jj < j + 3; jj++) {
                        if(board[ii][jj] != '.') {
                            if(st.find(board[ii][jj]) != st.end()) return false;
                            st.insert(board[ii][jj]);
                        }
                    }
                }
            }
        }

        return true;
    }
};
