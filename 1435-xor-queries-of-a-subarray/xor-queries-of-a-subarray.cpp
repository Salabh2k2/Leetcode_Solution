class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        for(int i = 1;i<n;i++)
        {
            arr[i]^=arr[i-1];
        }
        vector<int>ans;
        for(int i = 0;i<queries.size();i++)
        {
            int left =  queries[i][0];
            int right = queries[i][1];
            if(left==0) ans.push_back(arr[right]);
            else  ans.push_back(arr[right]^arr[left-1]);
        }
        return ans;
    }
};