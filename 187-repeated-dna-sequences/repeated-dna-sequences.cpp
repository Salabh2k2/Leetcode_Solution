class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>mp;
        vector<string>ans;
        int  n = s.size();
        if(n<10) return {};
        int i = 0;
        while(i<=n-10)
        {
            string k = s.substr(i,10);
            mp[k]++;
            i++;
        }
    for(auto it:mp)
    {
        if(it.second>1)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}
};