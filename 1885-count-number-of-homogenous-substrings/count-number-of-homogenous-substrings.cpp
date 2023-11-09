class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        long long ans = 0;
        int start = 0;
        int end = 0;
        while(end<n)
        {
            if(s[start]==s[end])
            {
                ans+=end-start+1;
            }
            if(s[start]!=s[end])
            {
                ans++;
                start = end;
            }
            end++;
        }
        return (int) ( ans% (1000000007));
    }
};