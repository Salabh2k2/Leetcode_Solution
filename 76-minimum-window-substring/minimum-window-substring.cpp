class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        string ans = "";
        if(m>n) return ans;
        map<char,int>mp;
       // int ct = 0;
        for(auto it:t)
        {
            mp[it]++;
          //  ct++;
        }
        int i = 0;
        int j = 0;
        int ct = mp.size();
       int size = INT_MAX;
        while(j<n)
        {
            char v= s[j];
            if(mp.find(v)!=mp.end())
            {
                mp[v]--;
                if(mp[v]==0) ct--;
            }
            if(ct>0){
                j++;
                continue;
            }
            while(mp.find(s[i])==mp.end() || mp[s[i]]<0){
                if(mp.find(s[i])!=mp.end())
                {
                    mp[s[i]]++;
                }
                i++;
            }
            if(size>j-i+1){
                size = j-i+1;
                ans = s.substr(i,j-i+1);
            }
            if(mp.find(s[i])!=mp.end())
            {
                mp[s[i]]++;
                if(mp[s[i]]==1) ct++;
            }
            i++;
            j++;
        }
        return ans;
    }
};