class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);  // Initialize prefix array with n+1 elements
        
        // Compute the prefix XOR array
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        
        int ans = 0;
        
        // Iterate through possible i, j, and k
        for (int k = 0; k < n; k++) {
            for (int i = k + 1; i < n; i++) {
                for (int j = i; j < n; j++) {
                    // Compute the XOR for the subarrays
                    if (prefix[i] ^ prefix[k] == prefix[j + 1] ^ prefix[i]) {
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};
