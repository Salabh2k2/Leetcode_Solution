class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string,vector<int>>mp;
        for(int i = 0;i<n;i++)
        {
            string s = strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>>ans;
       
        for(auto it:mp)
        {
             vector<string>temp;
            vector<int>v = it.second;
            for(int i = 0; i<v.size();i++)
            {
                temp.push_back(strs[v[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};