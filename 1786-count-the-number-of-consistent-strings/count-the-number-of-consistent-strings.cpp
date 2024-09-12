class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = allowed.size();
        map<char,int>mp;
        int ans = 0;
        for(auto it: allowed)
        {
            mp[it]++;
        }
        for(auto it:words)
        {
            bool flag = true;
            for(auto c:it)
            {
                if(mp.find(c)==mp.end())
                {
                    flag = false;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};