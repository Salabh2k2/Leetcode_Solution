class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int m = nums.size();
        vector<pair<int, int>> transformed;
        
        // Transform each number using the mapping
        for (int i = 0; i < m; ++i) {
            string num_str = to_string(nums[i]);
            string mapped_str = "";
            for (char c : num_str) {
                mapped_str += to_string(mapping[c - '0']);
            }
            int transformed_num = stoi(mapped_str);
            transformed.push_back({transformed_num, nums[i]});
        }
        
        // Sort the transformed numbers and preserve the original values
        sort(transformed.begin(), transformed.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });
        
        // Extract the sorted original numbers
        vector<int> result;
        for (auto& p : transformed) {
            result.push_back(p.second);
        }
        
        return result;
    }
};
