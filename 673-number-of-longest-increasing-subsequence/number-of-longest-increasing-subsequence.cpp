class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1); 
        vector<int> count(n, 1); 

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp1[j] + 1 > dp1[i]) {
                        dp1[i] = dp1[j] + 1;
                        count[i] = count[j]; 
                    } else if (dp1[j] + 1 == dp1[i]) {
                        count[i] += count[j]; 
                    }
                }
            }
        }

        int max_length = *max_element(dp1.begin(), dp1.end()); 

        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (dp1[i] == max_length) {
                result += count[i]; 
            }
        }
        return result;
    }
};
