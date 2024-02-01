#include <vector>
#include <algorithm>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }

    int findpar(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = findpar(parent[u]);
    }

    void unionbyrank(int a, int b)
    {
        int pa = findpar(a);
        int pb = findpar(b);
        if (pa == pb)
            return;
        if (rank[pa] > rank[pb])
        {
            parent[pb] = pa;
        }
        else if (rank[pa] < rank[pb])
        {
            parent[pa] = pb;
        }
        else
        {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
    int connect()
    {
        int ans = 0;
        for (int i = 0; i < parent.size(); i++)
        {
            if (i == parent[i])
                ans++;
        }
        return ans;
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int row = 0;
        int col = 0;
        for (auto it : stones)
        {
            row = max(row, it[0]);
            col = max(col, it[1]);
        }
        DSU ds(row + col + 1);
        map<int,int>node;
        for (auto it : stones)
        {
            int a = it[0];
            int b = it[1];
            ds.unionbyrank(a, b + row + 1); // Corrected this line
            node[a] = 1;
            node[b+row+1] = 1;
        }
       int ct = 0;
       for(auto it:node)
       {
           if(ds.findpar(it.first)==it.first) ct++;
       }
       return n-ct;
    }
};
