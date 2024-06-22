class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int ans = 0;
        int ct = 0;
        int oddCountPrefix = 0;

        for(int right = 0; right < n; right++) {
            if(nums[right] % 2 != 0) ct++;
            if(ct == k) {
                oddCountPrefix = 0;
                while(ct == k) {
                    if(nums[left] % 2 != 0) ct--;
                    left++;
                    oddCountPrefix++;
                }
                ans += oddCountPrefix;
            } else if (ct > k) {
                while(ct > k) {
                    if(nums[left] % 2 != 0) ct--;
                    left++;
                }
                oddCountPrefix = 0;
                while(ct == k) {
                    if(nums[left] % 2 != 0) ct--;
                    left++;
                    oddCountPrefix++;
                }
                ans += oddCountPrefix;
            } else {

                ans += oddCountPrefix;
            }
        }
        
        return ans;
    }
};
