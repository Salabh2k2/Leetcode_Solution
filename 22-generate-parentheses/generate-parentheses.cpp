#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }

    void generateParentheses(int n, int open, int close, std::vector<std::string>& result, std::string current) {
        if (open == 0 && close == 0) {
            if (true) {
                result.push_back(current);
            }
            return;
        }

        if (open > 0) {
            generateParentheses(n, open - 1, close, result, current + "(");
        }
        if (close > open) {
            generateParentheses(n, open, close - 1, result, current + ")");
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generateParentheses(n, n, n, result, "");
        return result;
    }
};
