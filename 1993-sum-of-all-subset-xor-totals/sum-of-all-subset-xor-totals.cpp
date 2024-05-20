class Solution {
public:
    void rec(int level, vector<int>& nums, int &sum, int n, int currentXor) {
        if (level == n) {
            sum += currentXor;
            return;
        }
        
        // choose the current element
        rec(level + 1, nums, sum, n, currentXor ^ nums[level]);
        
        // not choose the current element
        rec(level + 1, nums, sum, n, currentXor);
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int currentXor = 0;
        rec(0, nums, sum, n, currentXor);
        return sum;
    }
};
