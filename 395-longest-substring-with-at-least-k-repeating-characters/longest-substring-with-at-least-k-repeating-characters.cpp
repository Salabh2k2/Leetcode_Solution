class Solution {
public:
    int longestSubstring(string s, int k) {
    unordered_map<char,int> mp;
    for(auto x: s)
        mp[x]++;
    int j=0, i=0, n=s.length();
    while(j<n && mp[s[j]]>=k) 
        j++;
    if(j==n) return n;
    int ans1 = longestSubstring(s.substr(i,j),k);
    while(j<n && mp[s[j]]<k)
        j++;
    int ans2 = longestSubstring(s.substr(j),k);
    return max(ans1,ans2);
}
};