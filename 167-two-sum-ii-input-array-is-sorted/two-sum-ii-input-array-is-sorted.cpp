class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int k = target - numbers[i];
            auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), k);
            if (it != numbers.end() && *it == k) {
                int j = it - numbers.begin();
                return {i + 1, j + 1}; 
            }
        }
        return {}; 
    }
};
