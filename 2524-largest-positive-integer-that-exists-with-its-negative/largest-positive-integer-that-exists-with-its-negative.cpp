class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = n-1;
        while(left<right)
        {
            int a = nums[left];
            int b = nums[right];
             if(a>=0) break;
            if(a<0) a = -1*a;
           
            if(a==b) return a;
            else if(a<b) right--;
            else left++;
        }
        return -1;
    }
};