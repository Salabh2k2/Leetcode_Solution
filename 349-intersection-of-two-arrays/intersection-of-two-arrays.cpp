class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        vector<int>ans;

        for(int i = 0;i<nums1.size();i++)
        {
            mp[nums1[i]]++;
        }
        for(auto it:nums2)
        {
            if(mp[it])
            {
                ans.push_back(it);
                mp.erase(it);
            }
        }
        return ans;
    }
};