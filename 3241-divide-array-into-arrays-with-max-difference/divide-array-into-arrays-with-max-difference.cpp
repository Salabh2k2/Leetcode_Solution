class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int i = 0;
        int j = 2;
        while(j<n && i<n)
        {
            if(nums[j]-nums[i]<=k)
            {
                vector<int>temp;
                for(int k = i;k<=j;k++)
                {
                    temp.push_back(nums[k]);
                }
                i = j+1;
                j+=3;
                ans.push_back(temp);
            }
            else return {};
        }
        return ans;
    }
};