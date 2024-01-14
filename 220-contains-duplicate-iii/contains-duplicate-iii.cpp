class Solution {
public:
   bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();
    std::map<long long, int> mp; 
    for (int i = 0; i < n; i++) {
        
        auto it = mp.lower_bound((long long)nums[i] - valueDiff);
        if (it != mp.end() && std::abs(it->first - nums[i]) <= valueDiff) {
            return true;
        }

        mp[nums[i]] = i; 

        if (i >= indexDiff) {
            mp.erase(nums[i - indexDiff]);
        }
    }
    return false;
}
};