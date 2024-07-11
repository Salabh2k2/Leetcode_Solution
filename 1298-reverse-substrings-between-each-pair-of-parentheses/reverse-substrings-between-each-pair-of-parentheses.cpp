class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char>st;
        for(auto it:s)
        {
            if(it!=')')
            {
                st.push(it);
            }
            else{
                string v = "";
                while(st.top()!='(')
                {
                    v+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto i:v)
                {
                    st.push(i);
                }
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};