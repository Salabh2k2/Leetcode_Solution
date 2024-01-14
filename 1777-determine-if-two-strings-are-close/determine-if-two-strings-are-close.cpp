class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n!=m) return false;
        map<char,int>mp;
        map<char,int>mp1;
        vector<int>v1;
        vector<int>v2;
        vector<char>s1;
        vector<char>s2;
        for(int i = 0;i<n;i++)
        {
            mp[word1[i]]++;
            mp1[word2[i]]++;
        }
        for(auto i:mp)
        {
            v1.push_back(i.second);
            s1.push_back(i.first);
        }
        for(auto it:mp1)
        {
            v2.push_back(it.second);
            s2.push_back(it.first);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return (v1==v2) && (s1==s2);

    }
};