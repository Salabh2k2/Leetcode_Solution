class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = target.size();
        int m = deadends.size();
        unordered_set<string> visited; // Use unordered_set to store visited combinations
        map<string, int> mp;
        for (auto it : deadends) {
            mp[it]++;
        }
        
        if (mp["0000"] > 0) return -1; // Check if the initial combination is a deadend
        
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        
        while (!q.empty()) {
            string v = q.front().first;
            int turn = q.front().second;
            q.pop();
            
            if (v == target) {
                return turn;
            }
          
            for (int i = 0; i < 4; i++) {

                string inc_v = v;
                if (inc_v[i] == '9') {
                    inc_v[i] = '0';
                } else {
                    inc_v[i]++;
                }
                
                if (mp[inc_v] == 0 && visited.find(inc_v) == visited.end()) {
                    q.push({inc_v, turn + 1});
                    visited.insert(inc_v); 
                }
                
                string dec_v = v;
                if (dec_v[i] == '0') {
                    dec_v[i] = '9';
                } else {
                    dec_v[i]--;
                }
                
                if (mp[dec_v] == 0 && visited.find(dec_v) == visited.end()) {
                    q.push({dec_v, turn + 1});
                    visited.insert(dec_v); 
                }
            }
        }
        return -1;
    }
};