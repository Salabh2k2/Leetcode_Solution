class Solution {
public:
    void solve(int ind,vector<int>&arr,int target, vector<int>&res, vector<vector<int>>&ans)
    {
      if(target==0)
      {
          ans.push_back(res);
          return;
      }
        
        for(int i = ind;i<arr.size();i++)
        {
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            res.push_back(arr[i]);
            solve(i+1, arr,target-arr[i],res,ans);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>res;
        vector<vector<int>>ans;
        solve(0,candidates,target,res,ans);
        return ans;
    }
};