class Solution {
public:

    vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
    if (n == 0) return {}; // Handle the case when the input array is empty
    vector<int> dp(n, 1);
    vector<int> hash(n, -1); // Correct initialization

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i] && arr[i]%arr[j]==0) {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
    }

    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i < n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    while (lastIndex != -1) {
        temp.push_back(arr[lastIndex]);
        lastIndex = hash[lastIndex];
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> temp = printingLongestIncreasingSubsequence(nums,n);
        return temp;
    }
};