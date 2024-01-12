class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int n = s.size();
        int j = 0;
        int i = 0;
        int ans = 0;
        while(j<n)
        {
            if(!mp[s[j]])
            {
                mp[s[j]]++;
                 ans = max(ans, j-i+1);
                j++;
               
            }
            else{
               while(mp[s[j]])
               {
                   mp[s[i]]--;
                   i++;
                   
               }
            }
        }
        return ans;
    }
};