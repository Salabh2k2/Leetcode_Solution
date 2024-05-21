class Solution {
public:
    void solve(int ind, vector<int>nums, vector<int>&res, vector<vector<int>>&ans)
    {
        if(ind==nums.size())
        {
            ans.push_back(res);
            return;
        }
        res.push_back(nums[ind]);
        solve(ind+1,nums,res,ans);
        res.pop_back();
        solve(ind+1,nums,res,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        vector<vector<int>>ans;
        solve(0,nums,res,ans);
        return ans;
    }
};