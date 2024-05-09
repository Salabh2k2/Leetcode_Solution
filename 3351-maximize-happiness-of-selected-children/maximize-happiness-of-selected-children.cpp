class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(),happiness.end());
        long long ans = 0;
        int turn  = 0;
        for(int i = n-1;i>=0;i--)
        {
            if(k)
            {
                happiness[i]-=turn;
                turn++;
                if(happiness[i]<0) happiness[i] = 0;
                ans+=happiness[i];
                k--;
                if(happiness[i]==0) break;
            }
            else break;
        }
        return ans;
    }
};