class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int l = 0;
        int r = n-1;
        int lmax = INT_MIN;
        int rmax = INT_MIN;
        int ans = 0;
        while(l<r)
        {
            lmax = max(lmax,height[l]);
            rmax = max(rmax,height[r]);
            if(lmax>rmax)
            {
                ans+=rmax-height[r];
                r--;
            }
            else{
                ans+=lmax-height[l];
                l++;
            }
        }
        return ans;
   }
};