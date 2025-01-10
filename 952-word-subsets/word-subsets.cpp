class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>v(27,0);
        for(auto it: words2)
        {
            for(int i = 0;i<26;i++)
            {
                char c = 'a'+i;
                int k = count(it.begin(),it.end(),c);
                v[i] = max(v[i],k);
            }
        }
        for(auto it: words1)
        {
            bool flag = true;
            for(int i = 0;i<26;i++)
            {
                char c = 'a'+i;
                int k = count(it.begin(), it.end(),c);
                if(k<v[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(it);
        }
        return ans;

    }
};