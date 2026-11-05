class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char,int>> st;
        set<int> ast;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                ast.insert(i);
                continue;
            }

            if(st.empty() || s[i] == '(') {
                st.emplace(s[i], i);
            }else {
                if(st.top().first == '(') {
                    st.pop();
                }else {
                    st.emplace(s[i], i);
                }
            }
        }

        while(!st.empty()) {
            auto [ch, ind] = st.top();
            st.pop();

            if(ch == '(') {
                auto ub = ast.upper_bound(ind);
                if(ub == ast.end()) return false;
                ast.erase(ub);
            }else {
                auto ub = ast.upper_bound(ind);
                if(ub == ast.begin()) return false;
                ub--;
                ast.erase(ub);
            }
        }

        return true;
    }   
};
