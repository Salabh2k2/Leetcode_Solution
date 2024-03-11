class Solution {
public:
    static map<char, int> mp;

    static bool comp(char &a, char &b) {
        if (mp[a] != 0 && mp[b] != 0)
            return mp[a] < mp[b];
        else if (mp[a] == 0 && mp[b] == 0)
            return a < b;
        else
            return mp[a] != 0;
    }

    string customSortString(string order, string s) {
        int n = order.size();
        int m = s.size();

        int k = 1;
        for (auto it : order) {
            mp[it] = k;
            k++;
        }

        for (int i = 0; i < m; i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = k;
                k++;
            }
        }

        sort(s.begin(), s.end(), comp);
        return s;
    }
};

map<char, int> Solution::mp; // Definition of static member variable