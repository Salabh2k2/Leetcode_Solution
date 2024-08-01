class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto it:details)
        {
            string k = it;
            int n = it.size();
            string age ="";
            age+=k[n-4];
            age+=k[n-3];

            int a = stoi(age);
            ans+=(a>60);
        }
        return ans;
    }
};