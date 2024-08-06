class Solution {
public:
    int minimumPushes(string word) {
        int n  = word.size();
        map<char,int>mp;
        for(auto it:word)
        {
            mp[it]++;
        }
        int ans = 0;
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        int a = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int c = a/8;
            ans+=(c+1)*it.first;
            a++;
        }
        return ans;
        //return 0;
    }
};