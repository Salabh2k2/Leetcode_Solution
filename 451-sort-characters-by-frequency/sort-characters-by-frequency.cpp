class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        string ans = "";
        for(int i = 0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        while(!pq.empty())
        {
            char v = pq.top().second;
            int a = pq.top().first;
            while(a)
            {
                ans+=v;
                a--;
            }
            pq.pop();
        }
        return ans;
    }
};