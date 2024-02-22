class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int>mp;
        if(trust.size()==0 && n>1) return -1;
        if(trust.size()==0 && n==1) return 1;
        for(auto it:trust)
        {
            mp[it[1]]++;
        }
        vector<int>v;
        for(auto it:mp)
        {
            if(it.second==n-1) v.push_back(it.first);
        }
        for(auto it:v) cout<<it<<" ";
        for(int i = 0;i<v.size();i++)
        {
            bool flag = true;
            for(auto it:trust)
            {
                if(v[i]==it[0]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return v[i];
        }
        return -1;
    }
};