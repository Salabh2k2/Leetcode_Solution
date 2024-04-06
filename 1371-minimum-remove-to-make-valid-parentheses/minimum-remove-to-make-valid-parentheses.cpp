#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<pair<char,int>> st;
        string ans = "";
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push({'(', i});
            } else if (s[i] == ')') {
                if (!st.empty() && st.top().first == '(') {
                    st.pop();
                } else {
                    s[i] = '*'; 
                }
            }
        }
        
        while (!st.empty()) {
            s[st.top().second] = '*'; 
            st.pop();
        }
        
        for (char c : s) {
            if (c != '*') {
                ans += c;
            }
        }
        
        return ans;
    }
};
