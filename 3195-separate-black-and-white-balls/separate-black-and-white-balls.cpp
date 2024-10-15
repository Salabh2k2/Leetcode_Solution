class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int n = s.size();
        int j = n-1;
        while( j>=0 && s[j]=='1' )
        {
            j--;
        }
        int last = j;
        cout<<"last"<<last<<endl;
        for(int i = j;i>=0;i--)
        {
            if(s[i]=='1') {
                ans+=last-(i);
                last--;
            }
        }
        return ans;
    }
};