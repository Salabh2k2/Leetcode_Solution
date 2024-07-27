class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        int i = 0;
        int ans = 0;
        while(i<n)
        {
            if(flag)
            {
                
                if(nums[i]!=1){
                    flag = !flag;
                    ans++;
                }
            }
            else{
                 
                if(nums[i]!=0) {
                    flag = !flag;
                    ans++;
                }
            }
            i++;
        }
        return ans;
    }
};