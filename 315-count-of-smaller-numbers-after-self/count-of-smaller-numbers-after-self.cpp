class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);   // To store the count of smaller elements
        vector<int> v;        // A sorted list to maintain numbers processed so far
        
        for (int i = n - 1; i >= 0; i--) {
            // Find the position where nums[i] should be inserted in sorted order
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            
            // Calculate the number of elements smaller than nums[i]
            ans[i] = distance(v.begin(), it);
            
            // Insert nums[i] into the sorted list
            v.insert(it, nums[i]);
        }
        return ans;
    }
};
