class Solution {
public:
    int minimumDeletions(string s) {
        int a_count=0;
        int min_del=0;

        for(char ch : s){
            if(ch=='b'){
                a_count++;
            }
            else{
                min_del=min(min_del+1,a_count);
            }
        }
        return min_del;
    }
};

/*
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int>suffix(n,0);
        suffix[n-1] = (s[n-1]=='a');
        for(int i = n-2;i>=0;i--)
        {
            if(s[i]=='a') suffix[i] = suffix[i+1]+1;
            else suffix[i] = suffix[i+1];
        }
        vector<int>prefix(n,0);
        prefix[0] = (s[0]=='b');
        for(int i = 1;i<n;i++)
        {
            if(s[i]=='b') prefix[i] = prefix[i-1]+1;
            else prefix[i] = prefix[i-1];
        }
        int ans = 0;
        for(int i  = n-1;i>=0;i--)
        {
            ans = 
        }

        return ans;
    }
};*/