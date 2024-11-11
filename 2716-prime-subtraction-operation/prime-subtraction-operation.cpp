class Solution {
public:
    bool isprime(int n)
    {
        for(int i = 2;i*i<=n;i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        int peak = nums[n-1];
        for(int i = n-2;i>=0;i--)
        {
            if(peak>nums[i]) {
                peak = nums[i];
                continue;
            }
            else{
                bool flag = false;
                for(int j = 2;j<nums[i];j++)
                {
                    if(isprime(j) && (nums[i]-j)<peak)
                    {
                        nums[i]-=j;
                        peak = nums[i];
                        flag = true;
                        break;
                    }
                }
                if(!flag) return false;
            }
        }
        return true;
    }
};