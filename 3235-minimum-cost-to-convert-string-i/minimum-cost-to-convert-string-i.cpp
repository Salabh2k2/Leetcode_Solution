class Solution {
public:
    const int INF = 1e9;
    void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int m = changed.size();
        vector<vector<int>>dist(27,vector<int>(27,INF));
        for(int i = 0;i<dist.size();i++) dist[i][i] = 0;

        for(int i = 0;i<m;i++)
        {
            dist[original[i]-'a'][changed[i]-'a'] = min(cost[i],dist[original[i]-'a'][changed[i]-'a']);
        }
        long long ans = 0;
        floydWarshall(dist,27);
        for(int i = 0;i<n;i++)
        {
            if(source[i]==target[i]) continue;
            else{
                if(dist[source[i]-'a'][target[i]-'a']!=INF)
                {
                    ans+=dist[source[i]-'a'][target[i]-'a'];
                }
                else return -1;
            }
        }
        return ans;
    }
};