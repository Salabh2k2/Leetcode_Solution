class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            int k = nums[i]%3;
            if(k==0) continue;
            if(k==1) ans++;
            if(k==2) ans++;
        }
        return ans;
    }
};