#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k == n) return "0";
        
        stack<char> st;
        
        for (char it : num) {
            while (!st.empty() && k > 0 && it < st.top()) {
                st.pop();
                k--;
            }
            st.push(it);
        }
        
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        string tmp = (i == ans.size()) ? "0" : ans.substr(i);
        
        return tmp;
    }
};