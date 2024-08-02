
class Solution {
public:
    int minimumAddedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();

        int min1_1 = INT_MAX, min1_2 = INT_MAX, min1_3 = INT_MAX;
        for (int val : nums1) {
            if (val < min1_1) {
                min1_3 = min1_2;
                min1_2 = min1_1;
                min1_1 = val;
            } else if (val < min1_2) {
                min1_3 = min1_2;
                min1_2 = val;
            } else if (val < min1_3) {
                min1_3 = val;
            }
        }

        int min2 = INT_MAX;
        for (int val : nums2) {
            min2 = std::min(min2, val);
        }

        std::vector<int> candidates = {min2 - min1_1, min2 - min1_2, min2 - min1_3};

        std::vector<int> numberOccurs(1001, 0);
        for (int i = 0; i < n; i++) {
            int n1 = nums1[i];
            numberOccurs[n1]++;
        }

        int minX = INT_MAX;
        for (int possibleX : candidates) {
            std::vector<int> numberCounts(1001, 0);
            bool isPossible = true;
            for (int i = 0; i < n - 2 && isPossible; i++) {
                int target = nums2[i] - possibleX;
                if (target < 0 || target > 1000 || numberOccurs[target] == 0 || numberCounts[target] == numberOccurs[target]) {
                    isPossible = false;
                } else {
                    numberCounts[target]++;
                }
            }
            if (isPossible) {
                minX = std::min(minX, possibleX);
            }
        }
        return minX;
    }
};
