class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[n - 1];
        int ans = 0;
        
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < mn) {
                mn = nums[i];
            } else {
                int c = nums[i];
                while (c > mn) {
                    int divisor = 1;
                    cout<<c<<endl;
                    for (int j = 2; j * j <= c; j++) {
                        if (c % j == 0) {
                            divisor = c / j; // Largest divisor found
                            break;
                        }
                    }
                    if (divisor == 1) {
                       return -1;
                    } else {
                        c/= divisor;
                    }
                    ans++;
                }
                nums[i] = c;
                mn = c;
            }
        }
        
        return ans;
    }
};
