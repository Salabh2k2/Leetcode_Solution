class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>>vp;
        for(auto it: arr)
        { 
            int ct = 0;
            int k = it;
            while(k)
            {
                if(k&1)
                {
                    ct++;
                }
                k>>=1;
            }
            vp.push_back({ct,it});
        }
        sort(vp.begin(),vp.end());
        vector<int>ans;
        for(auto it:vp)
        {
            ans.push_back(it.second);
        }
        return ans;

    }
};