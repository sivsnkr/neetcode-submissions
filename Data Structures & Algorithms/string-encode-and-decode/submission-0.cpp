class Solution {
    string padint(int val) {
        string te = to_string(val);
        while(te.length() < 3) {
            te = "0" + te;
        }
        return te;
    }
public:

    string encode(vector<string>& strs) {
        string te = "";
        for(string &it : strs) {
            int le = it.length();
            string sle = padint(le);
            string temp = sle + it;
            te += temp;
        }
        return te;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int st = 0;
        while(st < s.length()) {
            int len = stoi(s.substr(st, 3));
            st += 3;
            res.push_back(s.substr(st, len));
            st += len;
        }
        return res;
    }
};
