class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==0) zero++;
            else if(nums[i]==1) one++;
            else two++;
        }
        nums.clear();
        while(zero)
        {
            nums.push_back(0);
            zero--;
        }
        while(one)
        {
            nums.push_back(1);
            one--;
        }
        while(two)
        {
            nums.push_back(2);
            two--;
        }
    }
};