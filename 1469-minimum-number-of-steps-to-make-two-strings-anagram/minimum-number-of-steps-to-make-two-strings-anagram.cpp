class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp;
      //  map<char,int>mp1;
        for(int i = 0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(int i = 0;i<t.size();i++)
        {
            if(mp[t[i]]){
                mp[t[i]]--;
            }
           // else mp1[t[i]]++;
            if(mp[t[i]]==0) mp.erase(t[i]);
        }
        int ans = 0;
        for(auto it:mp)
        {
            ans+=it.second;
        }
        return ans;
    }
};