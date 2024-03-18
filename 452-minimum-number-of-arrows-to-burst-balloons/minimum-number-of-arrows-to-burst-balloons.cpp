class Solution {
public:
   static bool comp(const std::vector<int>& a, const std::vector<int>& b) {
    return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),comp);
        int arrow = 1;
        int end = points[0][1];
        for(int i = 1;i<points.size();i++)
        {
            if(end>=points[i][0]) continue;
            else{
                arrow++;
                end = points[i][1];
            }
        }
        return arrow;
    }
};