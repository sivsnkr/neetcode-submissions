class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        map<int,int> cnt;
        for(int i : hand) cnt[i]++;

        for(int i = 0; i < hand.size() / groupSize; i++) {
            int mi = (*cnt.begin()).first;
            for(int j = 0; j < groupSize; j++) {
                auto it = cnt.find(mi);
                if(it == cnt.end()) return false;
                if(it->second-- == 1) {
                    cnt.erase(it);
                }
                mi++;
            }
        }

        return true;
    }
};
