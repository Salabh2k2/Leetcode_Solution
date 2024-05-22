class Solution {
public:
    std::string getSubstringBetween(const std::string& str, int start, int end) {
        if (start < 0 || end >= str.length() || start > end) {
            return "";
        }
        int length = end - start + 1;
        return str.substr(start, length);
    }

    // Function to check if a string is a palindrome
    bool isPalindrome(const std::string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void rec(int level, int prev, const std::string& s, std::vector<std::string>& temp, std::vector<std::vector<std::string>>& ans) {
        if (level == s.size()) {
            if (prev <= level - 1) {
                std::string v = getSubstringBetween(s, prev, level - 1);
                if (isPalindrome(v)) {
                    temp.push_back(v);
                    ans.push_back(temp);
                    temp.pop_back();
                }
            }
            return;
        }

        std::string k = getSubstringBetween(s, prev, level);
        if (isPalindrome(k) && k != "") {
            temp.push_back(k);
            rec(level + 1, level + 1, s, temp, ans);
            temp.pop_back();
        }

        rec(level + 1, prev, s, temp, ans);
    }

    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> temp;
        rec(0, 0, s, temp, ans);
        return ans;
    }
};
