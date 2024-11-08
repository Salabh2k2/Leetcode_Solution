#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxlimit = (1 << maximumBit) - 1; // Maximum number with `maximumBit` bits set.
        vector<int> prefixXor(n);
        
        // Calculate prefix XOR
        prefixXor[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixXor[i] = prefixXor[i - 1] ^ nums[i];
        }
        
        vector<int> result;
        for (int i = n - 1; i >= 0; i--) {
            result.push_back(prefixXor[i] ^ maxlimit); // Max XOR with the limit
        }
        
        return result;
    }
};
