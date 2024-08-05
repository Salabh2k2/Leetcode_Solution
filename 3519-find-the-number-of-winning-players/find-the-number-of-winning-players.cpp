class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<int, map<int, int>> mp;

        // Sorting the 'pick' vector
        sort(pick.begin(), pick.end());

        // Populating the map with counts
        for (int i = 0; i < pick.size();) {
            int c = pick[i][0];
            map<int, int> temp;
            while (i < pick.size() && pick[i][0] == c) {
                temp[pick[i][1]]++;
                i++;
            }
            mp[c] = temp;
        }

        // Debug output (optional)
        /*
        for (auto it : mp) {
            cout << it.first << " ";
            for (auto itr : it.second) {
                cout << itr.first << " " << itr.second << endl;
            }
        }
        */

        int ans = 0;
        // Counting winning players
        for (auto it : mp) {
            bool isWinner = false;
            for (auto itr : it.second) {
                if (itr.second > it.first) {
                    isWinner = true;
                    break;
                }
            }
            if (isWinner) {
                ans++;
            }
        }
        return ans;
    }
};
