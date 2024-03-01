class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n  = s.size();
        int one = 0;
        for(auto it:s)
        {
            if(it=='1') one++;
        }
        string ans = "";
        if(one == 0)
        {
            for(int i = 0;i<n;i++)
            {
                ans+='0';
            }
        }

        else if( one == 1)
        {
            for(int  i =0;i<n-1;i++)
            {
                ans+='0';
            }
            ans+='1';
        }
        else{
            one--;
            for(int i = 0;i<n-1;i++)
            {
                if(one>0)
                {
                    ans+='1';
                    one--;
                }
                else 
                ans+='0';
            }
            ans+='1';
        }
        return ans;
    }
};