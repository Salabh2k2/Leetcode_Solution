class Solution {
public:
     bool detectCycle(int src ,vector<int>&vis,vector<int>&crvisit,vector<int> adj[],vector<int>&ans){
        vis[src]=1;
        crvisit[src]=1;
        for(auto it  : adj[src]){
            if(!vis[it]){
                if(detectCycle(it , vis , crvisit , adj,ans)) return true ;
            }
            else if(vis[it]  && crvisit[it]){
                return true ;
            }
            
        }
        ans.push_back(src);
        crvisit[src]=0;
        return false ;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           int n = numCourses;   
        vector<int> adj[n];
        for(auto x : prerequisites){
            vector<int> data = x;
            int a =data[0];
            int b = data[1];
            adj[a].push_back(b);
            
        }
        vector<int> vis(n,0);
        vector<int> crvisit(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(detectCycle(i,vis,crvisit ,adj,ans))
                return {};
            }
        }
        return ans ;
    }
};