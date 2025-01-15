class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int k = __builtin_popcount(num2); // Count of 1 bits in num2
        int ans = 0;

        // Step 1: Set the bits in 'ans' based on the bits in 'num1'
        for (int i = 31; i >= 0 && k > 0; --i) {
            if (num1 & (1 << i)) {
                ans |= (1 << i);
                --k;
            }
        }

        // Step 2: If there are still bits left to set, set the lowest unset bits
        for (int i = 0; i <= 31 && k > 0; ++i) {
            if (!(ans & (1 << i))) {
                ans |= (1 << i);
                --k;
            }
        }

        return ans;
    }
};
