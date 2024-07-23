class Solution {
public:
    bool static cmp(pair<int,int>&a, pair<int,int>&b)
    {
        if(a.first<b.first) return true;
        else if(a.first>b.first) return false;
        else if(a.first==b.first){
            if(a.second>=b.second) return true;
            else return false;
        }
        return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        vector<pair<int,int>>vp;
        for(auto it:mp)
        {
            vp.push_back({it.second,it.first});
        }
        sort(vp.begin(),vp.end(),cmp);
        vector<int>ans;
        for(auto it:vp)
        {
          for(int i = 0;i<it.first;i++) ans.push_back(it.second);
        }
        return ans;
    }
};