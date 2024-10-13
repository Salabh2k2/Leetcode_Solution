class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int, vector<int>> mp;
        int smallest = INT_MAX;
        int largest = INT_MIN;
        int index = 0;
        
        // Populate the map with values and track smallest and largest values.
        for (auto& list : nums) {
            index++;
            for (int val : list) {
                mp[val].push_back(index);
                smallest = min(smallest, val);
                largest = max(largest, val);
            }
        }
        
        int k = 0;
        int left = smallest;
        int right = smallest;
        map<int, int> mx;
        int ansLength = INT_MAX;
        int start = smallest, end = largest;

        // Start sliding window
        while (right<= largest) {
            while (right <= largest && k < n) {
                if (mp.find(right) != mp.end()) {
                    for (int idx : mp[right]) {
                        if (mx[idx] == 0) {
                            k++;
                        }
                        mx[idx]++;
                    }
                }
                right++;
            }

            while (k == n) {
                // Update the smallest range
                if (right - left < ansLength) {
                    ansLength = right - left;
                    start = left;
                    end = right - 1;
                }

                if (mp.find(left) != mp.end()) {
                    for (int idx : mp[left]) {
                        mx[idx]--;
                        if (mx[idx] == 0) {
                            k--;
                        }
                    }
                }
                left++;
            }
        }
        
        return {start, end};
    }
};
