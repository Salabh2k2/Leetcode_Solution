class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int j = 0,i=0;
        int ans = 0;
        int mx = INT_MAX;
        while(j<n)
        {
            ans+=nums[j];
             if(ans>=target)
            {
                
                while(ans>=target)
                {
                    ans-=nums[i];
                    mx = min(mx,j-i+1);
                    i++;
                }
            }
            j++;

        }
        if(mx==INT_MAX)
        {
            return 0;
        }
        else return mx;
    }
};