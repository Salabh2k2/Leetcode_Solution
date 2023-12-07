class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int ind = -1;
        for(int i = n-1;i>=0;i--)
        {
           char ch = num[i];
            int v = ch-'0';
            if(v%2!=0)
            {
                ind = i;
                break;
            }
        }
        if(ind==-1) return "";
        string ans = "";
        ans = num.substr(0,ind+1);
        return ans;
    }
};