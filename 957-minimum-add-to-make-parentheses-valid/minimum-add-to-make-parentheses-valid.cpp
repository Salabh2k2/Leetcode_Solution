class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        if(n==0) return 0;

        stack<char>st;
        for(auto it:s)
        {
            if(st.empty() || it=='(') st.push(it);
            else{
                if(st.top()!=')')
                {
                    st.pop();
                }
                else st.push(it);
            }
        }
        return st.size();
    }
};