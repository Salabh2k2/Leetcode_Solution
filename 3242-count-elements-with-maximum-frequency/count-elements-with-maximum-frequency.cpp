class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(int i = 0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        int mx = -1;
        for(auto it: mp)
        {
            mx = max(mx,it.second);
        }
        int ans = 0;
        for(auto it:mp)
        {
            if(it.second==mx) ans+=it.second;
        }
        return ans;
    }
};