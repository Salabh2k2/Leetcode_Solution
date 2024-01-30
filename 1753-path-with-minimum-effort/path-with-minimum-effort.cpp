#include <vector>
#include <set>
#include <climits>
#include <utility>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        set<pair<int, pair<int, int>>> st;
        dist[0][0] = 0; // Initialize the starting point
        st.insert({0, {0, 0}});
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while (!st.empty()) {
            auto it = st.begin();
            int dis = it->first;
            int x = (it->second).first;
            int y = (it->second).second;
            st.erase(st.begin());
            for (int i = 0; i < 4; i++) {
                int newr = x + dx[i];
                int newc = y + dy[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m) { // Boundary check
                    int newDis = max(dis, abs(heights[x][y] - heights[newr][newc])); // Calculate the effort
                    if (newDis < dist[newr][newc]) {
                        st.erase({dist[newr][newc], {newr, newc}}); // Remove old entry
                        dist[newr][newc] = newDis;
                        st.insert({newDis, {newr, newc}}); // Insert the updated distance
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
