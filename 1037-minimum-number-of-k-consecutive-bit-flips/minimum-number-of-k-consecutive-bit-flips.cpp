class Solution {
public:
    int minKBitFlips(std::vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        std::deque<int> q;

        for (int i = 0; i < n; i++) {
           
            if (!q.empty() && i >= q.front() + k) {
                q.pop_front();
            }

           
            if (q.size() % 2 == nums[i]) {
                if (i + k > n) return -1;
                q.push_back(i);
                ans++;
            }
        }

        return ans;
    }
};
