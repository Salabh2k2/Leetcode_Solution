class Solution {
public:
    map<string, int> mp;

    void rec(int start, string &s, string temp, vector<string> &ans) {
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            string word = s.substr(start, end - start + 1);
            if (mp[word]) {
                string newTemp = temp + (temp.empty() ? "" : " ") + word;
                rec(end + 1, s, newTemp, ans);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        vector<string> ans;
        for (auto it : wordDict) {
            mp[it]++;
        }
        rec(0, s, "", ans);
        return ans;
    }
};
