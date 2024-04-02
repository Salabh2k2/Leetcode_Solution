#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        int n = s.size();
        int m = t.size();
        std::unordered_map<char, char> mp1, mp2;
        if (n != m) return false;
        
        for (int i = 0; i < n; ++i) {
            if (mp1.find(s[i]) != mp1.end()) {
                if (mp1[s[i]] != t[i]) return false;
            } else {
                mp1[s[i]] = t[i];
            }
            
            if (mp2.find(t[i]) != mp2.end()) {
                if (mp2[t[i]] != s[i]) return false;
            } else {
                mp2[t[i]] = s[i];
            }
        }
        return true;
    }
};
