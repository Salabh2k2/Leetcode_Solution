class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(nums[i]<0) nums[i] = -1*nums[i];
        }

        sort(nums.begin(),nums.end());

        for(int i = 0;i<n;i++)
        {
            nums[i] = pow(nums[i],2);
        }

        return nums;
    }
};