class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0;i<n;i++)
        {
            bool found = false;
            for(int j = 1;j<=nums[i];j++)
            {
                int k = j+1;
                if((j|k)==nums[i]){
                    ans.push_back(j);
                    found = true;
                    break;
                }
            }
            if(!found) ans.push_back(-1);
        }
        return ans;
    }
};