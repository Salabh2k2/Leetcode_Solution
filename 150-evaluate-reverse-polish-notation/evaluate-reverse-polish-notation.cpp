class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string>st;
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            string k = tokens[i];
            if(k=="+" || k=="-" || k=="*" ||  k=="/")
            {
                int u= stoi(st.top());
                st.pop();
                int v = stoi(st.top());
                st.pop();
                if(k=="+") st.push(to_string(u+v));
                else if(k=="-") st.push(to_string(v-u));
                else if(k=="*") st.push(to_string(v*u));
                else st.push(to_string(v/u));
            }
            else st.push(k);
        }
        string v = st.top();
        int u = stoi(v);
        return u;
    }
};