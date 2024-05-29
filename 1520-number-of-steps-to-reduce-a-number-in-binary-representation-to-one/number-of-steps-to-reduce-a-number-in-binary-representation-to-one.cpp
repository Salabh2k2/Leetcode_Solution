class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        map<int, vector<int>> mp;
        int ans = 0;

       
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                mp[0].push_back(i);
            }
        }

        int j = n - 1;
        while (j >= 0) {
           
            while (!mp[0].empty() && mp[0].back() >= j) {
                mp[0].pop_back();
            }
            
            if (s[j] == '0') {
                j--;
                ans++;
            } else {
                vector<int>& temp = mp[0];
                int k = temp.size();
                if (k == 0) {
                    if(j==0) break;
                    ans += (j + 2);
                    break;
                }
                int ind = temp.back();
                s[ind] = '1';
                s[j] = '0';
                ans++;
                temp.pop_back();
            }
        }
        return ans;
    }
};
