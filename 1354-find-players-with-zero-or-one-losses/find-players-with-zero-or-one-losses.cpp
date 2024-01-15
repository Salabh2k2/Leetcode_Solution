class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;
        map<int,int>mp1;
        for(int i = 0;i<matches.size();i++)
        {
            mp[matches[i][0]]++;
        }
        for(int i= 0;i<matches.size();i++)
        {
            mp1[matches[i][1]]++;
        }
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>temp1;
        for(auto it:mp)
        {
            if(!mp1[it.first])
            {
                temp.push_back(it.first);
            }
        }
        for(auto it:mp1)
        {
            if(it.second==1) temp1.push_back(it.first);
        }
        ans.push_back(temp);
        ans.push_back(temp1);
        return ans;
    }
};