class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.length();
        int totalCount = 0;
        vector<int> freq(26, 0); // Frequency of each character in the current window
        int left = 0; // Left pointer of the sliding window
        
        // Iterate over each character with right pointer expanding the window
        for (int right = 0; right < n; right++) {
            // Update frequency of the current character
            freq[s[right] - 'a']++;
            
            // Check if there is any character with frequency >= k
            while (any_of(freq.begin(), freq.end(), [k](int count) { return count >= k; })) {
                // If condition met, count all substrings from left to the current right
                totalCount += (n - right);
                // Contract the window from the left side by moving left pointer
                freq[s[left] - 'a']--;
                left++;
            }
        }
        
        return totalCount;
    }
};