class Solution {
public:
    int minOperations(vector<string>& logs) {
        int dist = 0;
        int n = logs.size();
        for(int i = 0;i<n;i++)
        {
            string v = logs[i];
            if(v[0]=='.' && v[1]=='.')
            {
                if(dist>0) dist--;
            }
            else if(v[0]!='.') dist++;
        }
        return dist;
    }
};