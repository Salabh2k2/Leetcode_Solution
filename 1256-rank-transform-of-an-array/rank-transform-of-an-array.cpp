class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>v = arr;
        sort(v.begin(),v.end());
        map<int,int>mp;
        int rank = 1;
        for(auto it:v)
        {
            if(mp.find(it)!=mp.end()) continue;
            else{
                mp[it] = rank;
                rank++;
            }
        }
        for(auto &it:arr)
        {
            it = mp[it];
        }
        return arr;

    }
};