class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0 ; 
        int n = nums.size() ; 
        vector<vector<int>> v(n , vector<int>(32 , 0)) ; 
        for(int i = 0 ; i < n ; i++){
            int t = i+1 ; // Max no of subarrays which can end at this index 
            int z = 0 ;
            for(int j = 0 ; j < 32 ; j++){
                if(nums[i] & (1<<j) ){
                    v[i][j] = (i>0)?1+v[i-1][j]:1 ;
                }

                if(k & (1<<j)){
                    t = min(t , v[i][j]) ;
                }else{
                    z = max(z , v[i][j]) ;
                }
            }
            if(t > z){
                ans += t-z ;
            }
        }

        return ans ; 
    }
};